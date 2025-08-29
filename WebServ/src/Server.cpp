/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:48:09 by jchen             #+#    #+#             */
/*   Updated: 2025/07/06 14:43:28 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

bool Server::g_running = true;

Server::Server(const ConfWebserv& config) {
    _pollFds.clear();

    for (std::vector<ConfServ>::const_iterator it = config.servers.begin();
         it != config.servers.end();
         ++it) {
        Socket* serverSocket = new Socket(it->hostname, it->port);
        try {
            serverSocket->initServerSocket();
        } catch (const std::exception& e) {
            delete serverSocket;
            for (std::map<int, Socket*>::iterator it = _listeningSockets.begin();
                 it != _listeningSockets.end();
                 ++it) {
                delete it->second;
            }
            throw;
        }
        int fd = serverSocket->getFd();
        if (fd == -1) {
            delete serverSocket;
            continue;
        }

        struct pollfd pfdServer;
        pfdServer.fd = fd;
        pfdServer.events = POLLIN;
        pfdServer.revents = 0;
        _pollFds.push_back(pfdServer);

        _listeningSockets.insert(std::make_pair(fd, serverSocket));
        _fdToServerConfig.insert(std::make_pair(fd, &(*it)));

        if (_pollFds.size() == 2) {
            std::vector<ConfServ>::const_iterator serv1 = config.servers.begin();

            std::cout << ANSI_BOLD_GREEN << centerText("  Welcome to our  ", CENTER_WIDTH, '=')
                      << std::endl;

            std::cout
                << ANSI_BOLD_GREEN
                << centerText(" __      _____ ___ ___ ___ _____   __", CENTER_WIDTH, ' ')
                << std::endl
                << centerText(" \\ \\    / / __| _ ) __| __| _ \\ \\ / /", CENTER_WIDTH, ' ')
                << std::endl
                << centerText("  \\ \\/\\/ /| _|| _ \\__ \\ _||   /\\ V / ", CENTER_WIDTH, ' ')
                << std::endl
                << centerText("   \\_/\\_/ |___|___/___/___|_|_\\ \\_/   ", CENTER_WIDTH, ' ')
                << std::endl
                << ANSI_RESET << std::endl;

            std::cout << ANSI_BOLD_GREEN
                      << centerText(
                             "  Servers listening on " + serv1->hostname + ":" + serv1->port +
                                 " and " + it->hostname + ":" + it->port + "  ",
                             CENTER_WIDTH,
                             '='
                         )
                      << ANSI_RESET << "\n\n\n"
                      << std::endl;
        }
    }
}

Server::~Server() {
    for (size_t i = 0; i < _pollFds.size(); ++i) {
        int current_fd = _pollFds[i].fd;
        // Check if the current_fd exists in our map of listening sockets.
        if (_listeningSockets.find(current_fd) == _listeningSockets.end()) {
            // If not found, it's a client socket. The Server is responsible for it.
            close(current_fd);
        }
    }

    for (std::map<int, Socket*>::iterator it = _listeningSockets.begin();
         it != _listeningSockets.end();
         ++it) {
        delete it->second; // This will call ~Socket(), which should call close().
    }
}

// ------------ MEMBER FUNCTIONS ------------

void Server::runServer(void) {

    while (g_running) {
        if (poll(&_pollFds[0], _pollFds.size(), -1) < 0) {
            if (errno == EINTR) continue;
            throw(std::runtime_error("poll() failed: " + std::string(strerror(errno))));
        }

        for (size_t i = 0; i < _pollFds.size(); i++) {
            if (_pollFds[i].revents == 0) continue;

            if (_listeningSockets.count(_pollFds[i].fd)) {
                if (_pollFds[i].revents & POLLIN) handleNewConnection(_pollFds[i].fd);
            } else {
                if (_pollFds[i].revents & POLLIN) handleClientRead(i);
                if (i < _pollFds.size() && (_pollFds[i].revents & POLLOUT)) handleClientWrite(i);
            }
        }
    }
}

// ------------ PRIVATE FUNCTIONS - SERVER SIDE ------------

void Server::handleNewConnection(int listenerFd) {
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    Socket* listenerSocket = _listeningSockets.at(listenerFd);
    int clientFd = listenerSocket->acceptSocket(&clientAddr, &clientAddrLen);

    listenerSocket->setNonBlocking(clientFd);
    addClient(clientFd, _fdToServerConfig.at(listenerFd));

    std::ostringstream oss;
    oss << "[  New client < " << clientFd << " > connected  ]";
    std::string msg = oss.str();

    std::cout << ANSI_BOLD_YELLOW << centerText(msg, CENTER_WIDTH, ' ') << "\n"
              << ANSI_RESET << std::endl;
}

void Server::addClient(int clientFd, const ConfServ* config) {
    struct pollfd pfdClient;
    pfdClient.fd = clientFd;
    pfdClient.events = POLLIN;
    pfdClient.revents = 0;

    _pollFds.push_back(pfdClient);

    _clientRecv[clientFd] = "";
    _clientWrite[clientFd] = "";
    _fdToServerConfig[clientFd] = config;
}

void Server::removeClient(int index) {
    int fd = _pollFds[index].fd;

    close(fd);
    _pollFds.erase(_pollFds.begin() + index);
    _clientRecv.erase(fd);
    _clientWrite.erase(fd);
    _fdToServerConfig.erase(fd);
}

void Server::handleClientRead(int index) {
    int clientFd = _pollFds[index].fd;
    const ConfServ* config = _fdToServerConfig.at(clientFd);

    char buffer[CHUNCK_SIZE];
    ssize_t bytesRead = recv(clientFd, buffer, sizeof(buffer), 0);

    if (bytesRead <= 0) {
        removeClient(index);
        return;
    }

    _clientRecv[clientFd].append(buffer, bytesRead);

    // Boucle tant qu'il y a une requête complète dans le buffer
    while (true) {

        size_t headersEnd = _clientRecv[clientFd].find("\r\n\r\n");
        if (headersEnd == std::string::npos) break; // Pas de headers complets

        // Cherche Content-Length
        std::string headers = _clientRecv[clientFd].substr(0, headersEnd + 4);
        size_t totalRequestSize = 0;
        bool isChunked = (headers.find("Transfer-Encoding: chunked") != std::string::npos);
        if (isChunked) {
            // ne sait pas la taille a l avance, cher un 0 a la fin du body pour savoir
            size_t bodyEnd = _clientRecv[clientFd].find("\r\n0\r\n\r\n", headersEnd);
            if (bodyEnd == std::string::npos) break; // Incomplete chunked body
            std::cout << "hihi " << std::endl;
            totalRequestSize = bodyEnd + strlen("\r\n0\r\n\r\n");
        } else {
            size_t contentLength = 0;
            size_t clPos = headers.find("Content-Length:");

            if (clPos != std::string::npos) {
                size_t valueStart = headers.find_first_not_of(" ", clPos + 15);
                size_t valueEnd = headers.find("\r\n", valueStart);
                std::string clStr = headers.substr(valueStart, valueEnd - valueStart);
                contentLength = std::atoi(clStr.c_str());
            }
            totalRequestSize = headersEnd + 4 + contentLength;
        }

        if (_clientRecv[clientFd].size() < totalRequestSize) break; // Pas tout le body reçu

        std::string rawRequest = _clientRecv[clientFd].substr(0, totalRequestSize);
        Request req;
        Response parseRes = req.parseRequest(rawRequest, config);
        Response res;
        if (parseRes.getStatusCode() != 0) {
            res = parseRes;
        } else {
            HandlerRequest handler;
            res = handler.handleRequest(req, *config, this);
        }
        std::cerr << "Returning " << res.getStatusCode() << " : " + res.getStatusMessage()
                  << std::endl;
        std::cerr << "\n" << centerText("", CENTER_WIDTH, '=') << "\n\n" << std::endl;

        _clientWrite[clientFd] += res.toString();
        _pollFds[index].events |= POLLOUT;

        _clientRecv[clientFd].erase(0, totalRequestSize);
    }
}

void Server::handleClientWrite(int index) {
    int clientFd = _pollFds[index].fd;
    std::string& data = _clientWrite[clientFd];

    if (data.empty()) {
        _pollFds[index].events &= ~POLLOUT;
        return;
    }

    ssize_t bytesSent = send(clientFd, data.c_str(), data.size(), 0);
    if (bytesSent <= 0) {
        std::cout << "Client [ " << clientFd << " ] error or disconnected" << std::endl;
        removeClient(index);
        return;
    }

    data.erase(0, bytesSent);
    if (data.empty())
        _pollFds[index].events &= ~POLLOUT; // Retire POLLOUT a la liste des flags = message recu!
}
