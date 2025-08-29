/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:42:56 by jchen             #+#    #+#             */
/*   Updated: 2025/06/30 14:01:19 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"


Socket::Socket(const std::string& ip, const std::string& port) : _fd(-1), _ip(ip), _port(port)
{
	_fd = checkFailure(socket(AF_INET, SOCK_STREAM, 0), "failed to create socket");		//IPv4, TCP, auto

	// hints : liste de ce que je veux demander a la fonction getaddrinfo
	struct addrinfo hints, *res;
	std::memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

	// obtention des informations en allouant de la memoire
	if (getaddrinfo(ip.c_str(), _port.c_str(), &hints, &res) != 0)
		throw (std::runtime_error("Error : getaddrinfo failed\n"));

	// copie les infos obtenues dans notre struct
	std::memcpy(&_address, res->ai_addr, sizeof(struct sockaddr_in));

	freeaddrinfo(res);
}

Socket::~Socket()
{
	if (_fd != -1)
		checkFailure(close(_fd), "failed to close socket");
}

// ------------ MEMBER FUNCTIONS ------------

void				Socket::initServerSocket()
{
	setNonBlocking(_fd);
	bindSocket();
	listenSocket();
}

int  				Socket::acceptSocket(sockaddr_in* clientAddr, socklen_t* addrLen)
{
	return(accept(_fd, (struct sockaddr*)clientAddr, addrLen));
}

void 				Socket::closeSocket()
{
	if (_fd != -1)
	{
		checkFailure(close(_fd), "failed to close socket");
		_fd = -1;
	}
}

void				Socket::setNonBlocking(int fd)
{
	int 	flags = fcntl(fd, F_GETFL, 0);

	checkFailure(flags, "failed to get socket flags");
	checkFailure(fcntl(fd, F_SETFL, flags | O_NONBLOCK), "failed to set socket to non-blocking");
}


// ------------ GETTERS SETTERS ------------

int					Socket::getFd(void) const
{
	return (_fd);
}

struct sockaddr_in	Socket::getAddress(void) const
{
	return (_address);
}

std::string			Socket::getIp(void) const
{
	return (_ip);
}

std::string			Socket::getPort(void) const
{
	return (_port);
}


// ------------ PRIVATE FUNCTIONS - SERVER SIDE ------------

void				Socket::bindSocket()
{
	int				optval = 1;

	checkFailure(setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)), "failed to set socket options");
	if (bind(_fd, (struct sockaddr*)&_address, sizeof(_address)) < 0){
		if (errno == EADDRINUSE)
		{
			std::cerr << ANSI_BOLD_RED "failed to bind socket for " + _ip + ":" + _port + ", " + strerror(errno) << ANSI_RESET << std::endl;
			closeSocket();
		}
		else
            throw(std::runtime_error("Error: failed to bind socket to " + _ip + ":" + _port + " : " + strerror(errno)));
	}
}

void 				Socket::listenSocket(void)
{
	if (_fd != -1)
    {
        if (listen(_fd, BACKLOG) == -1)
        {
            std::cerr << "Error: failed to listen on socket for " << _ip << ":" << _port << " : " << strerror(errno) << std::endl;
            closeSocket();
        }
    }
}
