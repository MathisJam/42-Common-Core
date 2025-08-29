/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 09:56:33 by mjameau           #+#    #+#             */
/*   Updated: 2025/07/01 21:37:10 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "Response.hpp"
#include "Webserv.hpp"

class Request {
public:
    // CANON FORM
    Request();
    Request(const Request& cpy);
    Request& operator=(const Request& param);
    ~Request();

    // MEMBER FUNCTIONS
    /*Une fonction pour parser la requete HTTP*/
    Response parseRequest(const std::string& str, const Context* conf);

    // SETTER GETTERS
    const std::string& getMethod() const;
    const std::string& getUri() const;
    const std::string& getVersion() const;
    const std::map<std::string, std::string>& getHeaders() const;
    const std::string& getBody() const;
    const std::string& getSessionId() const { return _sessionId; }
    void setMethod(const std::string& method);
    void setUri(const std::string& uri);
    void setHeaders(const std::map<std::string, std::string>& headers);
    void setBody(const std::string& body) { this->body = body; }

private:
    std::string method;
    std::string uri;
    std::string version;
    std::map<std::string, std::string> headers;
    std::string body;
    std::string _sessionId;
};

#endif
