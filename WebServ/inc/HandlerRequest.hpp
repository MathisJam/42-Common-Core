/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandlerRequest.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:36:19 by mjameau           #+#    #+#             */
/*   Updated: 2025/07/06 14:20:22 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLEREQUEST_HPP
#define HANDLEREQUEST_HPP

#include "../inc/Request.hpp"
#include "../inc/Response.hpp"
#include "../inc/Webserv.hpp"
#include "Server.hpp"

class Server;

class HandlerRequest {
public:
    // CANON FORM
    HandlerRequest();
    HandlerRequest(const HandlerRequest& cpy);
    ~HandlerRequest();
    HandlerRequest& operator=(const HandlerRequest& param);

    // MEMBER FUNCTIONS
    bool isCGI(const Request& req, const ConfLoc& loc) const;
    Response handleRequest(const Request& req, const ConfServ& s_config, Server* server);
    Response generateAutoIndexResponse(
        const std::string& uri,
        const std::string& dirPath,
        const ConfLoc& loc
    );

    Response handleCGI(const Request& req, const ConfLoc& loc);
    Response handleStaticRequest(const Request& req, const ConfLoc& loc);
    Response handleUpload(const Request& req, const ConfLoc& loc);

private:
};

std::string getMimeType(const std::string& path);
const ConfLoc* findLocation(const ConfServ& s_config, const std::string& uri);
std::string intToString(int number);

template <typename T>
Response ErrorResponse(int code, const T* conf) {
    Response res;

    std::map<int, std::string> msgs;
    msgs[400] = "Bad Request";
    msgs[403] = "Forbidden";
    msgs[404] = "Not Found";
    msgs[405] = "Method Not Allowed";
    msgs[411] = "Length Required";
    msgs[413] = "Payload too large";
    msgs[500] = "Internal Server Error";
    msgs[501] = "Not Implemented";
    msgs[505] = "HTTP Version Not Supported";

    std::map<int, std::string>::const_iterator it = msgs.find(code);
    std::string message = (it != msgs.end()) ? it->second : "Error";

    res.setStatusCode(code);
    res.setStatusMessage(message);

    std::string body;

    // Cherche une page d’erreur personnalisée
    if (conf && conf->error_files.count(code)) {
        std::string errorPath = conf->root;
        std::string relPath = conf->error_files.at(code);
        // Gère les slashs pour éviter les doubles ou les oublis
        if (!errorPath.empty() && errorPath[errorPath.size() - 1] == '/' && relPath[0] == '/')
            errorPath.erase(errorPath.size() - 1);
        errorPath += relPath;
        std::ifstream file(errorPath.c_str());
        if (file.is_open()) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            body = buffer.str();
        }
    }

    if (body.empty()) {
        body =
            "<html>"
            "<head><title>" +
            intToString(code) + " " + message +
            "</title></head>"
            "<body style='background:#222;color:#fff;font-family:Segoe "
            "UI,Arial,sans-serif;text-align:center;padding:60px;'>"
            "<div style='background:rgba(0,0,0,0.7);display:inline-block;padding:40px "
            "60px;border-radius:16px;'>"
            "<h1 style='font-size:3em;margin-bottom:20px;'>" +
            intToString(code) + " " + message +
            "</h1>"
            "<hr style='border:0;border-top:1px solid #444;margin:30px 0;'>"
            "<p style='margin-top:40px;font-size:1.1em;color:#00BFFF;'>webserv waf waf</p>"
            "</div>"
            "</body>"
            "</html>";
    }

    res.setBody(body);
    res.setHeader("Content-Type", "text/html");

    return res;
}

Response RedirectResponse(int code, const std::string& url);
std::string extractQueryString(const std::string& uri);
unsigned long long strict_stoi(std::string str);

#endif
