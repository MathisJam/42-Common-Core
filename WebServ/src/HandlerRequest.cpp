/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandlerRequest.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:40:33 by mjameau           #+#    #+#             */
/*   Updated: 2025/07/06 14:37:23 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HandlerRequest.hpp"
#include "../inc/Webserv.hpp"

HandlerRequest::HandlerRequest() {}

HandlerRequest::HandlerRequest(const HandlerRequest& cpy) { *this = cpy; }

HandlerRequest::~HandlerRequest() {}

HandlerRequest& HandlerRequest::operator=(const HandlerRequest& param) {
    if (this != &param) { *this = param; }
    return (*this);
}

static std::string generateSessionId() {
    std::stringstream ss;
    ss << time(NULL) << "_" << rand();
    return ss.str();
}

static std::string joinPaths(const std::string& p1, const std::string& p2) {
    std::string path1 = p1;
    std::string path2 = p2;

    if (!path1.empty() && path1[path1.size() - 1] == '/') {
        path1 = path1.erase(path1.size() - 1);
    } // like endswith
    if (!path2.empty() && path2[0] == '/') { path2.erase(0, 1); } // like startswith
    return path1 + "/" + path2;
}

// MEMBER FUNCTIONS
/*
regarde quelle type de requete on recoit (CGI, Static, Upload) et l'envoyer dans la fonction
correspondante.
*/
Response
HandlerRequest::handleRequest(const Request& req, const ConfServ& s_config, Server* server) {
    Response res;

    // trouve la ConfLoc correspondant a l'URI
    std::string uri = req.getUri();
    size_t qpos = uri.find('?');
    if (qpos != std::string::npos) uri = uri.substr(0, qpos);

    const ConfLoc* loc = findLocation(s_config, uri);
    if (!loc) return ErrorResponse(404, &s_config);

    std::string sessionId = req.getSessionId();
    bool newSession = false;

    if (sessionId.empty() || server->sessions.find(sessionId) == server->sessions.end()) {
        sessionId = generateSessionId();
        server->sessions[sessionId].visit_count = 1;
        server->sessions[sessionId].dark_mode = false; // Initialize dark mode
        server->sessions[sessionId].click_count = 0;
        newSession = true;
    } else {
        server->sessions[sessionId].visit_count++;
    }

    if (req.getBody().size() > loc->client_max_body_size) { return ErrorResponse(413, loc); }

    // verifie si la methode HTTP est autorisee dans cette ConfLoc
    std::vector<std::string>::const_iterator it = std::find(
        loc->allowed_methods.begin(),
        loc->allowed_methods.end(),
        req.getMethod()
    );

    if (it == loc->allowed_methods.end()) return ErrorResponse(405, &s_config);
    // Verifie si une redirection est configuree pour cette URI, si oui on prend le code (301 ||
    // 302) dans redir->seconf.first et l'url dans l'autre
    if ((loc->redirect.first == 301 || loc->redirect.first == 302) &&
        !loc->redirect.second.empty() && req.getUri() == loc->prefix)
        return RedirectResponse(loc->redirect.first, loc->redirect.second);

    // si c'est une requete CGI (ex: .php, .py), on la traite via un script
    if (isCGI(req, *loc)) return handleCGI(req, *loc);

    // si methode POST et les uploads sont autorises, traite l’upload
    if (req.getMethod() == "POST" && !loc->upload_path.empty()) return handleUpload(req, *loc);

    if (uri == "/profile") {
        if (newSession) {
            // Set the cookie for the new session
            res.addHeader(
                "Set-Cookie",
                "sessionId=" + sessionId + "; Path=/; HttpOnly; Max-Age=3600" // seconds donc 1h
            );
        }
        res.setStatusCode(200);
        res.setHeader("Content-Type", "text/html");
        std::stringstream body;
        body << "<html><body><h1>Welcome!</h1>"
             << "<p>Your session ID is: " << sessionId << "</p>"
             << "<p>You have visited this page " << server->sessions[sessionId].visit_count
             << " times.</p>"
             << "</body></html>";
        res.setBody(body.str());
        return res;
    }

    // sinon, traite comme une requete classique vers un fichier statique
    return (res = handleStaticRequest(req, *loc));
}

Response HandlerRequest::handleUpload(const Request& req, const ConfLoc& loc) {
    Response res;
    if (loc.upload_path.empty()) return ErrorResponse(500, &loc);
    if (req.getMethod() != "POST") return ErrorResponse(405, &loc);

    std::map<std::string, std::string>::const_iterator it = req.getHeaders().find("Content-Type");
    if (it == req.getHeaders().end()) return ErrorResponse(400, &loc);

    std::string contentType = it->second;
    std::string boundary;
    size_t bpos = contentType.find("boundary=");
    if (bpos != std::string::npos) { boundary = "--" + contentType.substr(bpos + 9); }

    if (boundary.empty()) {
        // Extraire le nom du fichier depuis l'URI
        std::string uri = req.getUri();
        std::string filename = uri.substr(uri.find_last_of('/') + 1);
        if (filename.empty()) {
            std::ostringstream oss;
            oss << "upload_" << time(NULL) << "_" << getpid();
            filename = oss.str();
        }

        std::string savepath = loc.upload_path;
        if (savepath[savepath.size() - 1] != '/') savepath += "/";
        savepath += filename;

        std::ofstream file(savepath.c_str(), std::ios::out | std::ios::binary);
        if (!file.is_open()) return ErrorResponse(403, &loc);
        file.write(req.getBody().c_str(), req.getBody().size());
        file.close();

        res.setStatusCode(201);
        res.setStatusMessage("Created");
        res.setHeader("Content-Type", "text/html");
        std::ostringstream html;
        html << "<html><body><h1>File uploaded successfully</h1>"
             << "<p>Saved as: " << savepath << "</p></body></html>";
        res.setBody(html.str());
        return res;
    }

    const std::string& body = req.getBody();
    std::vector<std::string> savedFiles;
    size_t pos = 0;
    while (true) {
        size_t part_start = body.find(boundary, pos);
        if (part_start == std::string::npos) break;
        part_start += boundary.length();

        if (body.compare(part_start, 2, "--") == 0) break;

        if (body.compare(part_start, 2, "\r\n") == 0) part_start += 2;

        size_t header_end = body.find("\r\n\r\n", part_start);
        if (header_end == std::string::npos) break;

        std::string part_header = body.substr(part_start, header_end - part_start);

        size_t disp = part_header.find("Content-Disposition:");
        if (disp == std::string::npos) {
            pos = header_end + 4;
            continue;
        }
        size_t fname = part_header.find("filename=\"", disp);
        std::string filename;
        if (fname != std::string::npos) {
            fname += 10;
            size_t fname_end = part_header.find("\"", fname);
            if (fname_end != std::string::npos)
                filename = part_header.substr(fname, fname_end - fname);
        }
        if (filename.empty()) {
            pos = header_end + 4;
            continue;
        }

        std::string savepath = loc.upload_path;
        if (savepath[savepath.size() - 1] != '/') savepath += "/";
        std::string finalname = filename;
        if (finalname.empty()) {
            std::ostringstream oss;
            oss << "upload_" << time(NULL) << "_" << getpid();
            finalname = oss.str();
        }
        savepath += finalname;

        size_t data_start = header_end + 4;
        size_t next_boundary = body.find(boundary, data_start);
        if (next_boundary == std::string::npos) break;
        size_t data_end = next_boundary;
        // Enlève le \r\n final si présent
        if (data_end > 1 && body[data_end - 2] == '\r' && body[data_end - 1] == '\n') data_end -= 2;

        std::ofstream file(savepath.c_str(), std::ios::out | std::ios::binary);
        if (file.is_open()) {
            file.write(body.c_str() + data_start, data_end - data_start);
            file.close();
            savedFiles.push_back(finalname);
        }

        pos = next_boundary;
    }

    // Réponse HTML listant les fichiers uploadés
    std::ostringstream html;
    html << "<html><body><h1>Upload result</h1>";
    if (savedFiles.empty()) html << "<p>No file uploaded.</p>";
    else {
        html << "<ul>";
        for (size_t i = 0; i < savedFiles.size(); ++i)
            html << "<li>Saved as: " << loc.upload_path << "/" << savedFiles[i] << "</li>";
        html << "</ul>";
    }
    html << "</body></html>";

    res.setStatusCode(201);
    res.setStatusMessage("Created");
    res.setHeader("Content-Type", "text/html");
    res.setBody(html.str());
    return res;
}

Response HandlerRequest::handleCGI(const Request& req, const ConfLoc& loc) {
    Response res;

    // recupere le chemin du script CGI a executer
    std::string uri = req.getUri();

    std::string path = uri;
    size_t qpos = uri.find('?');
    if (qpos != std::string::npos) path = uri.substr(0, qpos); // /test.cgi

    std::string ext = path.substr(path.rfind('.'));

    // le chemin du script CGI
    std::string cgiExec = loc.cgi_handlers.at(ext).path;

    // creer les variables d'environnement
    std::vector<std::string> envStrings;
    envStrings.push_back("GATEWAY_INTERFACE=CGI/1.1");
    envStrings.push_back("REQUEST_METHOD=" + req.getMethod());
    std::string script_name = path;
    envStrings.push_back("SCRIPT_NAME=" + path);
    envStrings.push_back("PATH_INFO=" + path);
    envStrings.push_back("REDIRECT_STATUS=200");
    envStrings.push_back("SERVER_PROTOCOL=HTTP/1.1");

    // si contenu de la requete, ajoute CONTENT_LENGTH et CONTENT_TYPE
    if (!req.getBody().empty())
        envStrings.push_back("CONTENT_LENGTH=" + intToString(req.getBody().size()));

    std::map<std::string, std::string>::const_iterator ct = req.getHeaders().find("Content-Type");
    if (ct != req.getHeaders().end()) envStrings.push_back("CONTENT_TYPE=" + ct->second);

    // ajoute la variable d'environnement QUERY_STRING exemple : ?key=value
    envStrings.push_back("QUERY_STRING=" + extractQueryString(uri));

    // Ajoute la variable d'environnement HTTP_COOKIE si l'en-tête Cookie est présent
    std::map<std::string, std::string>::const_iterator cookieHeader = req.getHeaders().find("Cookie");
    if (cookieHeader != req.getHeaders().end()) {
        envStrings.push_back("HTTP_COOKIE=" + cookieHeader->second);
    }

    std::string uriPath = loc.root + path;
    if (!loc.alias.empty()) {
        uriPath = loc.alias + path.substr(loc.prefix.length());
    } else {
        uriPath = loc.root + path;
    }
    envStrings.push_back("SCRIPT_FILENAME=" + uriPath);

    std::string script_filename;
    if (!loc.alias.empty()) {
        // For alias, the script's filesystem path is the alias + the part of the URI after the
        // location prefix.
        script_filename = joinPaths(loc.alias, path.substr(loc.prefix.length()));
    } else {
        // For root, the script's filesystem path is the root + the full URI path.
        script_filename = joinPaths(loc.root, path);
    }

    // fait char** pour execve -> alloue manuellement les char* pour chaque variable d'environnement
    char** envp = new char*[envStrings.size() + 1];
    for (size_t i = 0; i < envStrings.size(); ++i) {
        envp[i] = new char[envStrings[i].size() + 1];
        std::strcpy(envp[i], envStrings[i].c_str());
    }
    envp[envStrings.size()] = NULL;

    // pipes pour communication avec le CGI
    int inputPipe[2], outputPipe[2];
    if (pipe(inputPipe) < 0 || pipe(outputPipe) < 0) {
        for (size_t i = 0; envp[i]; ++i) delete[] envp[i];
        delete[] envp;
        return ErrorResponse(500, &loc);
    }

    struct stat sb;
    if (stat(script_filename.c_str(), &sb) != 0) return ErrorResponse(404, &loc);
    if (ext == ".py" && !(sb.st_mode & S_IXUSR)) return ErrorResponse(404, &loc);
    if (access(script_filename.c_str(), R_OK) != 0) return ErrorResponse(404, &loc);

    // on fait l'enfant (sans sexe) et on voit si il a reussi a naitre
    pid_t pid = fork();
    if (pid < 0) {
        for (size_t i = 0; envp[i]; ++i) delete[] envp[i];
        delete[] envp;
        return ErrorResponse(500, &loc);
    }

    // enfant
    if (pid == 0) {
        // Change directory to the script's directory
        std::string scriptDir = script_filename.substr(0, script_filename.find_last_of('/'));
        if (chdir(scriptDir.c_str()) != 0) {
            // If chdir fails, exit. The parent will see this as a server error.
            exit(EXIT_FAILURE);
        }

        // redigire stdin stdout
        dup2(inputPipe[0], 0);
        dup2(outputPipe[1], 1);

        // ferme les bouts inutiles des pipes
        close(inputPipe[1]);
        close(outputPipe[0]);

        // argv contient la CGI et l'uri comme argument on cast car execve attend des char* const
        char* argv[] = {
            // argv0
            const_cast<char*>(cgiExec.c_str()),
            // argv1
            const_cast<char*>(script_filename.c_str()),
            // argv2 NULL pour terminer la liste
            NULL
        };

        execve(cgiExec.c_str(), argv, envp);
        // Si execve echoue
        exit(1);
    }

    // parent

    // ferme les bouts inutiles des pipes
    close(inputPipe[0]);
    // on ecrit le corps de la requete dans le pipe entree
    write(inputPipe[1], req.getBody().c_str(), req.getBody().size());
    // on ferme le pipe d'ecriture pour signaler la fin de l'entree
    close(inputPipe[1]);

    // on ferme le pipe de sortie pour signaler la fin de l'entree
    close(outputPipe[1]);

    int status;
    int waited = 0;
    const int timeout = 5; // secondes
    // gere timeout si CGI bloquer, g mit 5 secondes pour le timeout, on peut changer si besoin
    while (waited < timeout) {
        pid_t result = waitpid(pid, &status, WNOHANG);
        if (result == 0) {
            sleep(1);
            waited++;
        } else if (result > 0) break;
        else {
            // erreur waitpid
            kill(pid, SIGKILL);
            close(outputPipe[0]);
            for (size_t i = 0; envp[i]; ++i) delete[] envp[i];
            delete[] envp;
            return ErrorResponse(500, &loc);
        }
    }

    if (waited >= timeout) {
        kill(pid, SIGKILL);
        waitpid(pid, NULL, 0);
        close(outputPipe[0]);
        for (size_t i = 0; envp[i]; ++i) delete[] envp[i];
        delete[] envp;
        return ErrorResponse(504, &loc);
    }

    //  on lit la sortie du CGI et on stocke le resultat dans une string
    std::string cgiOutput;
    char buffer[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(outputPipe[0], buffer, sizeof(buffer))) > 0)
        cgiOutput.append(buffer, bytesRead);
    close(outputPipe[0]);

    // delete envp
    for (size_t i = 0; envp[i]; ++i) delete[] envp[i];
    delete[] envp;

    // si execve a echoue ou le processus n'a pas termine correctement
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) return ErrorResponse(500, &loc);

    // separation des headers et du body
    size_t headerEnd = cgiOutput.find("\r\n\r\n");
    size_t offset = 4;
    if (headerEnd == std::string::npos) {
        headerEnd = cgiOutput.find("\n\n");
        offset = 2;
    }
    if (headerEnd == std::string::npos) return ErrorResponse(500, &loc);

    std::string headerPart = cgiOutput.substr(0, headerEnd);
    std::string bodyPart = cgiOutput.substr(headerEnd + offset);

    while (!bodyPart.empty() && (bodyPart[0] == '\r' || bodyPart[0] == '\n'))
        bodyPart = bodyPart.substr(1);

    // Nettoie tous les \r et \n au début du body
    while (!bodyPart.empty() && (bodyPart[0] == '\r' || bodyPart[0] == '\n'))
        bodyPart = bodyPart.substr(1);

    // Supprime toute ligne "Status: ..." même précédée de \r ou \n
    while (true) {
        // Cherche le début de la ligne
        size_t line_start = 0;
        // Ignore les \r et \n au début
        while (line_start < bodyPart.size() &&
               (bodyPart[line_start] == '\r' || bodyPart[line_start] == '\n'))
            ++line_start;
        // Vérifie si la ligne commence par "Status:"
        if (bodyPart.compare(line_start, 7, "Status:") == 0) {
            size_t endl = bodyPart.find('\n', line_start);
            if (endl == std::string::npos) bodyPart = "";
            else bodyPart = bodyPart.substr(endl + 1);
            // Nettoie encore les \r et \n au début après suppression
            while (!bodyPart.empty() && (bodyPart[0] == '\r' || bodyPart[0] == '\n'))
                bodyPart = bodyPart.substr(1);
        } else break;
    }
    res.setBody(bodyPart);

    // on parse les headers
    std::istringstream headerStream(headerPart);
    std::string line;
    while (std::getline(headerStream, line)) {
        if (line.empty() || line == "\r") continue;
        size_t colon = line.find(':');
        if (colon != std::string::npos) {
            std::string key = line.substr(0, colon);
            std::string value = line.substr(colon + 1);
            while (!value.empty() && (value[0] == ' ' || value[0] == '\t')) value.erase(0, 1);
            if (!value.empty() && value[value.size() - 1] == '\r') value.erase(value.size() - 1);

            if (key == "Status") {
                // Gère le code HTTP si besoin
                std::istringstream iss(value);
                int code;
                std::string msg;
                if (iss >> code) {
                    res.setStatusCode(code);
                    std::getline(iss, msg);
                    if (!msg.empty() && msg[0] == ' ') msg.erase(0, 1);
                    res.setStatusMessage(msg);
                }
            } else if (key == "Set-Cookie") res.addHeader(key, value);
            else res.setHeader(key, value);
        }
    }

    // on set le body et le status code et le message de la reponse
    for (std::multimap<std::string, std::string>::const_iterator it = res.getHeaders().begin();
         it != res.getHeaders().end();
         ++it)
        std::cerr << "Header: " << it->first << " = " << it->second << std::endl;
    return (res);
}

Response HandlerRequest::generateAutoIndexResponse(
    const std::string& uri,
    const std::string& dirPath,
    const ConfLoc& loc
) {
    Response res;

    // ouvre le dossier demande (par ex: "./www/assets/")
    DIR* dir = opendir(dirPath.c_str());
    if (!dir) return ErrorResponse(500, &loc);

    // commence à ecrire du HTML dans un string stream
    std::ostringstream html;
    html << "<html><head><title>Index of " << uri << "</title></head><body>";
    html << "<h1>Index of " << uri << "</h1><ul>";

    // parcours chaque fichier ou dossier dans le repertoire
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        std::string name = entry->d_name;

        // ignore les entrees speciales "." et ".."
        if (name == "." || name == "..") continue;

        // on construit le chemin complet vers l'element
        std::string fullPath = dirPath + "/" + name;

        // si c'est un dossier, on ajoute un "/" à la fin du nom
        struct stat st;
        if (stat(fullPath.c_str(), &st) == 0 && S_ISDIR(st.st_mode)) name += "/";

        // ecrit un lien cliquable vers le fichier ou le dossier
        html << "<li><a href=\"" << uri;
        if (uri[uri.length() - 1] != '/') html << "/";
        html << name << "\">" << name << "</a></li>";
    }

    // ferme la liste et le HTML
    html << "</ul></body></html>";

    // ferme le dossier
    closedir(dir);

    // cree la reponse HTTP avec le contenu HTML
    res.setStatusCode(200);
    res.setStatusMessage("OK");
    res.setHeader("Content-Type", "text/html");
    res.setBody(html.str());

    return res;
}

Response HandlerRequest::handleStaticRequest(const Request& req, const ConfLoc& loc) {
    Response res;
    std::string uri = req.getUri();
    size_t qpos = uri.find('?');
    if (qpos != std::string::npos) uri = uri.substr(0, qpos);

    std::string path;
    if (!loc.alias.empty()) {
        // on enleve le truc avant pour faire comme demander dans le sujet;
        path = loc.alias + uri.substr(loc.prefix.length());
    } else {
        path = loc.root + uri;
    }

    struct stat fileStat;

    if (stat(path.c_str(), &fileStat) != 0) return ErrorResponse(404, &loc);

    if (req.getMethod() == "DELETE") {
        if (S_ISDIR(fileStat.st_mode)) return ErrorResponse(403, &loc);

        if (access(path.c_str(), W_OK) != 0) return ErrorResponse(403, &loc);

        if (std::remove(path.c_str()) != 0) return ErrorResponse(500, &loc);

        res.setStatusCode(204);
        res.setStatusMessage("No Content");
        return res;
    }

    if (S_ISDIR(fileStat.st_mode)) {
        // Parcours les fichiers index par défaut et cherche le premier accessible
        bool foundIndex = false;
        std::string indexPath;
        for (size_t i = 0; i < loc.default_index.size(); ++i) {
            std::string candidate = path;
            if (!candidate.empty() && candidate[candidate.size() - 1] != '/') candidate += "/";
            candidate += loc.default_index[i];

            if (access(candidate.c_str(), R_OK) == 0) {
                indexPath = candidate;
                foundIndex = true;
                break;
            }
        }

        if (foundIndex) {
            path = indexPath;
        } else if (loc.autoindex) {
            return generateAutoIndexResponse(uri, path, loc);
        } else {
            return ErrorResponse(403, &loc); //yes yes good like nginx !!!
        }
    }

    // Vérifie accès au fichier
    if (access(path.c_str(), R_OK) != 0) return ErrorResponse(403, &loc);

    // Lecture du fichier
    std::ifstream file(path.c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open()) return ErrorResponse(500, &loc);

    std::string body;
    char buffer[1024];
    while (file.read(buffer, sizeof(buffer))) body.append(buffer, file.gcount());
    body.append(buffer, file.gcount());
    file.close();

    // Détermination type MIME
    std::string ext;
    size_t pos = path.rfind('.');
    if (pos != std::string::npos) ext = path.substr(pos);
    else ext = "";

    std::string contentType = getMimeType(ext);

    res.setStatusCode(200);
    res.setStatusMessage("OK");
    res.setHeader("Content-Type", contentType);
    res.setBody(body);
    return res;
}

bool HandlerRequest::isCGI(const Request& req, const ConfLoc& loc) const {
    // on prend l'uri de la requete
    std::string uri = req.getUri();

    // on enleve la query string si elle existe
    size_t qpos = uri.find('?');
    if (qpos != std::string::npos) { uri = uri.substr(0, qpos); }

    // si y'a pas de '.' alors pas de .py ou .php etc donc pas de script donc faux
    size_t dot = uri.rfind('.');
    if (dot == std::string::npos) return (false);

    // on recupere l'extension apres le '.'
    std::string ext = uri.substr(dot);

    // regarde si l'extension est dans les handlers CGI de la location
    std::map<std::string, cgi_handler>::const_iterator it = loc.cgi_handlers.find(ext);
    if (it == loc.cgi_handlers.end()) return (false);
    // cherche si la methode est dedans
    const std::vector<std::string>& methods = it->second.methods;

    return std::find(methods.begin(), methods.end(), req.getMethod()) != methods.end();
}
