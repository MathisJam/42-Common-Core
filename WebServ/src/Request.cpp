/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 09:56:30 by mjameau           #+#    #+#             */
/*   Updated: 2025/07/06 14:43:00 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Request.hpp"
#include "../inc/HandlerRequest.hpp"

// ----------- CANON FORM ---------------
Request::Request() : method(""), uri(""), version(""), headers(), body("") {}

Request::~Request() {}

Request::Request(const Request& cpy) { *this = cpy; }

Request& Request::operator=(const Request& param) {
    if (this != &param) {
        this->method = param.method;
        this->uri = param.uri;
        this->version = param.version;
        this->headers = param.headers;
        this->body = param.body;
    }
    return (*this);
}

// ------------ GETTERS SETTERS ------------

void Request::setHeaders(const std::map<std::string, std::string>& headers) {
    this->headers = headers;
}

void Request::setMethod(const std::string& method) { this->method = method; }
void Request::setUri(const std::string& uri) { this->uri = uri; }
const std::string& Request::getMethod() const { return (this->method); }

const std::string& Request::getUri() const { return (this->uri); }

const std::string& Request::getVersion() const { return (this->version); }

const std::map<std::string, std::string>& Request::getHeaders() const { return (this->headers); }

const std::string& Request::getBody() const { return (this->body); }

// ---------- MEMBER FUNCTIONS ------------

Response Request::parseRequest(const std::string& str, const Context* conf) {

    std::cerr << centerText(" *  RAW REQUEST  * ", CENTER_WIDTH, '-') << "\n"
              << std::endl
              << str << "\n"
              << centerText(" *  END RAW  * ", CENTER_WIDTH, '-') << "\n"
              << std::endl;

    std::istringstream stream(str);
    std::string line;

    if (!std::getline(stream, line)) {
        return ErrorResponse(400, conf);
    }

    if (!line.empty() && line[line.size() - 1] == '\r') line.erase(line.size() - 1);


    std::istringstream lineStream(line);
    if (!(lineStream >> method >> uri >> version)) {
        return ErrorResponse(400, conf);
    }

    for (size_t i = 0; i < method.size(); ++i) method[i] = std::toupper(method[i]);

    if (method != "GET" && method != "POST" && method != "DELETE") {
        return ErrorResponse(501, conf);
    }

    this->headers.clear();

    while (std::getline(stream, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r') line.erase(line.size() - 1);
        if (line.empty()) break;

        size_t pos = line.find(':');
        if (pos == std::string::npos) continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        while (!value.empty() && value[0] == ' ') value.erase(0, 1);

        this->headers[key] = value;
    }

    std::map<std::string, std::string>::iterator it_cookie = headers.find("Cookie");
    if (it_cookie != headers.end()) {
        std::string cookie_str = it_cookie->second;
        size_t pos = cookie_str.find("sessionId=");
        if (pos != std::string::npos) {
            size_t start = pos + 10;
            size_t end = cookie_str.find(';', start);
            if (end == std::string::npos) end = cookie_str.length();
            _sessionId = cookie_str.substr(start, end - start);
        }
    } // cookies mmh

    std::map<std::string, std::string>::iterator it_cl = headers.find("Content-Length");
    std::map<std::string, std::string>::iterator it_te = headers.find("Transfer-Encoding");

    if (method == "POST") {
        if (it_te != headers.end() && it_te->second == "chunked") {
            std::string unchunked_body;
            while (stream.good()) {
                std::string hex_size_str;
                std::getline(stream, hex_size_str);
                if (!hex_size_str.empty() && hex_size_str[hex_size_str.length() - 1] == '\r') {
                    hex_size_str.erase(hex_size_str.size() - 1);
                }

                std::stringstream ss;
                ss << std::hex << hex_size_str;
                size_t chunk_size;
                ss >> chunk_size;

                if (chunk_size == 0) {
                    // End of chunks
                    break;
                }

                std::vector<char> chunk_data(chunk_size);
                stream.read(chunk_data.data(), chunk_size);
                unchunked_body.append(chunk_data.data(), chunk_size);

                // Consume the trailing CRLF after the chunk data
                std::string crlf;
                std::getline(stream, crlf);
            }
            this->body = unchunked_body;

        } else if (it_cl != headers.end()) {
            // Handle Content-Length
            char* end;
            long len = std::strtol(it_cl->second.c_str(), &end, 10);
            if (*end != '\0' || len < 0) return ErrorResponse(400, conf);

            body.resize(len);
            stream.read(&body[0], len);
        } else {
            // post request without content-length or chunked
            return ErrorResponse(411, conf);
        }
    }

    // Requête OK, retourne une réponse spéciale avec code 0 (pas d’erreur)
    Response okResponse;
    okResponse.setStatusCode(0);
    return (okResponse);
}
