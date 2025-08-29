/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 09:56:52 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/08 09:56:52 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// LES FONCTIONS UTILES ET CELLES QUI SERVENT A RENVOYER DES STATUS CODE SONT ICI
#include "../inc/Response.hpp"
#include <stdint.h>

unsigned long long strict_stoi(std::string str) {
    unsigned long long ret = 0;
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i])) throw std::runtime_error(str + ": not a valid number");
        if (ret > (UINT64_MAX - (str[i] - '0')) / 10)
            throw std::out_of_range(str + ": value out of bonds");
        ret = ret * 10 + str[i] - '0';
    }
    return ret;
}

std::string ft_to_string(int value) {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

const ConfLoc* findLocation(const ConfServ& s_config, const std::string& uri) {
    // Initialise a NULL
    const ConfLoc* b_Match = NULL;
    size_t b_MatchLen = 0;

    // Boucle avec iterateur pour parcourir les locations
    for (std::vector<ConfLoc>::const_iterator it = s_config.locations.begin();
         it != s_config.locations.end();
         ++it) {
        // Prend le prefix de la location actuelle (ex : /images)
        const std::string& prefix = it->prefix;

        // Verfie si le prefix (/images) correspond a l'uri passe en arg (ex : /images/gallery)
        if (uri.compare(0, prefix.length(), prefix) == 0) {
            // Si le prefix correspond et qu'il est + long (initialise a 0 de base donc forcement)
            // on assigne
            // + le prefix est long + il est precis (/images/gallery c mieux que /images)
            if (prefix.length() > b_MatchLen) {
                b_Match = &(*it);
                b_MatchLen = prefix.length();
            }
        }
    }
    // return le meilleur match trouve (le + precis), si rien trouve return NULL.
    return (b_Match);
}

std::string extractQueryString(const std::string& uri) {
    size_t pos = uri.find('?');
    if (pos == std::string::npos) return "";
    return (uri.substr(pos + 1));
}

std::string getMimeType(const std::string& path) {
    // Cherche la derniere extension (ex: .html, .png)
    size_t dot = path.rfind('.');
    if (dot == std::string::npos) return "application/octet-stream";

    std::string ext = path.substr(dot);

    static std::map<std::string, std::string> mimeTypes;

    if (mimeTypes.empty()) {
        mimeTypes[".html"] = "text/html";
        mimeTypes[".htm"] = "text/html";
        mimeTypes[".css"] = "text/css";
        mimeTypes[".js"] = "application/javascript";
        mimeTypes[".json"] = "application/json";
        mimeTypes[".png"] = "image/png";
        mimeTypes[".jpg"] = "image/jpeg";
        mimeTypes[".jpeg"] = "image/jpeg";
        mimeTypes[".gif"] = "image/gif";
        mimeTypes[".txt"] = "text/plain";
        mimeTypes[".pdf"] = "application/pdf";
    }

    std::map<std::string, std::string>::const_iterator it = mimeTypes.find(ext);
    if (it != mimeTypes.end()) return it->second;
    return "application/octet-stream";
}

std::string intToString(int number) {
    std::stringstream ss;
    ss << number;
    return (ss.str());
}

Response RedirectResponse(int code, const std::string& url) {
    Response res;

    if (code != 301 && code != 302 &&
        code !=
            307) // Par defaut si le code est different de ces 3 la alors on le met a 302 (default)
        code = 302;

    res.setStatusCode(code);

    // Met le message correspondant au code
    switch (code) {
        case 301: res.setStatusMessage("Moved Permanently"); break;

        case 302: res.setStatusMessage("Found"); break;

        case 307: res.setStatusMessage("Temporary Redirect"); break;
    }

    // Set headers et body creer avec url
    res.setHeader("Location", url);

    std::string body = "<html><body><h1>" + intToString(code) + " " + res.getStatusMessage() +
                       "</h1><p>Redirecting to <a href=\"" + url + "\">" + url +
                       "</a></p></body></html>";
    res.setHeader("Content-Type", "text/html");
    res.setBody(body);

    // return la response;
    return (res);
}

// fonction qui verifie si la valeur retournee par une fonction est -1 (error)
// si aucun probleme, renvoie la bonne valeur de retour
int checkFailure(int valueToCheck, const std::string& errorMsg) {
    if (valueToCheck == -1)
        throw(std::runtime_error("Error : " + errorMsg + " : " + strerror(errno)));

    return (valueToCheck);
}

std::string centerText(const std::string& str, size_t width, char filler) {
    if (str.length() >= width) return (str);

    size_t leftPadding = (width - str.length()) / 2;
    size_t rightPadding = width - str.length() - leftPadding;

    return (std::string(leftPadding, filler) + str + std::string(rightPadding, filler));
}
