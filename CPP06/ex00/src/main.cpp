/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:10:07 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/29 18:25:12 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << BOLD RED << "Only 1 arg is required. try ./convert 42 or ./convert -4.2f"
		<< RESET << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
}
