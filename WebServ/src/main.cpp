/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <jchen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:16:13 by jchen             #+#    #+#             */
/*   Updated: 2025/06/30 15:16:13 by jchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HandlerRequest.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Server.hpp"
#include "Socket.hpp"
#include "Webserv.hpp"

static void handler_sig(int sig) {
    (void)sig;

    std::cout << ANSI_BOLD_RED << "\n"
              << std::endl
              << centerText("  Shutting down the server... ", CENTER_WIDTH, '=') << ANSI_RESET
              << std::endl;

    Server::g_running = false;
}

int main(int argc, char** argv) {
    try {
        signal(SIGPIPE, SIG_IGN);
        if (argc > 2) {
            std::cerr << USAGE_ERROR << std::endl;
            return (EXIT_FAILURE);
        }

        signal(SIGINT, &handler_sig);
        ConfWebserv conf = parse_config(argc > 1 ? argv[1] : "configs/default.conf");
        Server server(conf);
        server.runServer();
    } catch (std::exception& e) {
        std::cerr << ANSI_BOLD_RED << e.what() << ANSI_RESET << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}
