/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:13:29 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/17 12:24:56 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <sstream>
#include <string>

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

std::string FormatTrunc (const std::string &str);

int stringToInt(const std::string &str);

#endif
