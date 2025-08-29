/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:42:09 by jchen             #+#    #+#             */
/*   Updated: 2025/07/06 14:20:38 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "Webserv.hpp"

#define BACKLOG 4096
#define CHUNCK_SIZE	4096


class Socket
{
	public:
		Socket(const std::string& ip, const std::string& port);
		~Socket();

	// MEMBER FUNCTIONS
		void				initServerSocket();

		void				closeSocket(void);
		int					acceptSocket(sockaddr_in* client_addr, socklen_t* addrlen);
		void				setNonBlocking(int fd);

	// SETTER GETTERS
		int					getFd(void) const;
		struct sockaddr_in	getAddress(void) const;
		std::string			getIp(void) const;
		std::string			getPort(void) const;


	private:
		int					_fd;
		struct sockaddr_in	_address;
		std::string			_ip;
		std::string			_port;

	// PRIVATE SERVER FUNCTIONS
		void				bindSocket(void);
		void				listenSocket(void);
};

#endif

