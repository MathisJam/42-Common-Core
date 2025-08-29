/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:13:04 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/14 17:29:53 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Format.hpp"

std::string FormatTrunc (const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

int stringToInt(const std::string &str)
{
	std::stringstream ss(str);
	int num = 0;
	ss >> num;
	return num;
}

