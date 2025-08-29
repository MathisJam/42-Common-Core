/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:40:58 by mjameau           #+#    #+#             */
/*   Updated: 2025/07/02 14:32:50 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Response.hpp"


// ---------------- CANON FORM -------------
Response::Response() : _statusCode(200), _statusMessage("OK"), _body("")
{
}

Response::~Response()
{
}

Response::Response(const Response &cpy)
{
	*this = cpy;
}

Response &Response::operator=(const Response &param)
{
	if (this != &param)
	{
		this->_body = param._body;
		this->_statusCode = param._statusCode;
		this->_statusMessage = param._statusMessage;
		this->_headers = param._headers;
	}
	return (*this);
}

// ---------------- GETTERS SETTERS ----------------

void Response::setBody(const std::string &body)
{
	this->_body = body;
}

void Response::setStatusCode(int code)
{
	this->_statusCode = code;
}

void Response::setStatusMessage(const std::string &msg)
{
	this->_statusMessage = msg;
}

void Response::setHeader(const std::string &key, const std::string &value)
{
	_headers.erase(key); // Supprime toutes les valeurs pour cette clé
	_headers.insert(std::make_pair(key, value)); // Ajoute la nouvelle paire
}


int Response::getStatusCode() const
{
	return (_statusCode);
}

std::string Response::getStatusMessage() const
{
	return(_statusMessage);
}

std::string Response::getHeader(const std::string &key) const
{
	std::map<std::string, std::string>::const_iterator it = _headers.find(key);
	if (it != _headers.end())
		return(it->second);
	return ("");
}

std::string Response::getBody() const
{
	return (_body);
}

const std::multimap<std::string, std::string>& Response::getHeaders() const
{
		return _headers;
}

// ---------- MEMBER FUNCTION ----------
std::string Response::toString() const
{
	std::stringstream resp;

	resp << "HTTP/1.1 " << _statusCode << " " << _statusMessage << "\r\n";

	// Si Content-Length n'est pas dans les headers, on l'ajoute
	if (_headers.find("Content-Length") == _headers.end())
		resp << "Content-Length: " << _body.size() << "\r\n";

	// Ensuite on ecrit tous les headers (sauf Content-Length si on l'a deja ecrit au-dessus)
	for (std::multimap<std::string, std::string>::const_iterator it = _headers.begin(); it != _headers.end(); ++it)
	{
		// Eviter d'ecrire Content-Length ou Transfer-Encoding: chunked en double
		if (it->first != "Content-Length" && it->first != "Transfer-Encoding")
			resp << it->first << ": " << it->second << "\r\n";
	}

	resp << "\r\n";  // ligne vide entre headers et body
	resp << _body;

	return resp.str();
}

void Response::addHeader(const std::string &key, const std::string &value)
{
	if (key == "Set-Cookie")
		_headers.insert(std::make_pair(key, value)); // autorise plusieurs
	else {
		_headers.erase(key); // supprime tous les anciens
		_headers.insert(std::make_pair(key, value)); // ajoute le nouveau
	}
}
