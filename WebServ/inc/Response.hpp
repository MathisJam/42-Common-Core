/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Response.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:33:03 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/28 16:52:13 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "Webserv.hpp"

class Response
{
	public :
	// CANON FORM
		Response();
		~Response();
		Response		&operator=(const Response &param);
		Response(const Response &cpy);

	// MEMBER FUNCTIONS
	std::string			toString() const;
	void				addHeader(const std::string &key, const std::string &value);

	// GETTERS SETTERS
	int					getStatusCode() const;
	std::string			getStatusMessage() const;
	std::string			getHeader(const std::string &key) const;
	std::string			getBody() const;

	void				setStatusCode(int code);
	void				setStatusMessage(const std::string &msg);
	void				setHeader(const std::string &key, const std::string &value);
	void				setBody(const std::string &body);
	const std::multimap<std::string, std::string>& getHeaders() const;

	private :
		int				_statusCode;
		std::string		_statusMessage;
		std::multimap<std::string, std::string> _headers;
		std::string		_body;
};

#endif
