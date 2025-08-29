/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:15:41 by jchen             #+#    #+#             */
/*   Updated: 2025/07/01 21:36:03 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "HandlerRequest.hpp"
#include "Socket.hpp"
#include "Webserv.hpp"

class Server {
public:
    Server(const ConfWebserv& config);
    ~Server();

    // MEMBER FUNCTIONS
    void runServer(void);
    static bool g_running;
    std::map<std::string, SessionData> sessions;

private:
    std::map<int, Socket*> _listeningSockets;
    std::map<int, const ConfServ*> _fdToServerConfig;

    std::vector<struct pollfd> _pollFds;
    std::map<int, std::string> _clientRecv;
    std::map<int, std::string> _clientWrite;

    void handleNewConnection(int listenerFd);
    void addClient(int clientFd, const ConfServ* config);
    void removeClient(int index);
    void handleClientRead(int index);
    void handleClientWrite(int index);
};

#endif
