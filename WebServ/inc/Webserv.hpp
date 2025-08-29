/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 09:56:39 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/08 09:56:39 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include "ast.hpp"
#include <algorithm>
#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <fcntl.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <netdb.h>
#include <netinet/in.h>
#include <ostream>
#include <poll.h>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

#define ANSI_RESET "\x1b[0m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_BOLD_RED ANSI_RED ANSI_BOLD
#define ANSI_BOLD_GREEN ANSI_GREEN ANSI_BOLD
#define ANSI_BOLD_YELLOW ANSI_YELLOW ANSI_BOLD

#define CENTER_WIDTH 100
#define USAGE_ERROR ANSI_BOLD_RED "Usage: ./webserv [configuration_file]" ANSI_RESET

struct SessionData {
    int visit_count;
    bool dark_mode;
    unsigned long long click_count;
};

struct cgi_handler {
    std::string path;
    std::vector<std::string> methods;
};

struct ConfLoc;
struct Context {
    std::map<int, std::string> error_files;
    unsigned long long client_max_body_size;
    std::string root;
    std::pair<int, std::string> redirect;
    bool autoindex;
    std::vector<std::string> default_index;
    std::string upload_path;
    std::map<std::string, cgi_handler > cgi_handlers;
    std::vector<std::string> allowed_methods;
    std::vector<ConfLoc> locations;
    std::string hostname;
    std::string port;
    std::vector<std::string> names;
    std::string alias;

    Context()
        : client_max_body_size(10000), root("/"), autoindex(false), upload_path("/upload/"),
          hostname("0.0.0.0"), port("8080"), alias("") {}
};

struct ConfLoc : Context {
    std::string prefix;
};

struct ConfServ : Context {
    bool is_default;

    ConfServ() : is_default(false) {};
};

struct ConfWebserv {
    std::vector<ConfServ> servers;
};

unsigned long long strict_stoi(std::string str);
std::string ft_to_string(int value);
ConfWebserv parse_config(const char* file);
ConfServ resolveServer(ASTBlock const& srvAST);
int checkFailure(int valueToCheck, const std::string& errorMsg);
std::string centerText(const std::string& str, size_t width, char filler);

#endif
