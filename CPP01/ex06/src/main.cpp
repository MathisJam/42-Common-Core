/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:58:45 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/19 19:08:24 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << BOLD RED << "Error ❌ : Usage: ./harlFilter [DEBUG/INFO/WARNING/ERROR/...]" << RESET << std::endl;
		return 1;
	}
	Harl harl;
	std::string level = argv[1];
	switch (level == "DEBUG" ? 0 :
		 level == "INFO" ? 1 :
		 level == "WARNING" ? 2 :
		 level == "ERROR" ? 3 : -1)
	{
	case 0:
		harl.complain("DEBUG");
		std::cout << std::endl;
	case 1:
		harl.complain("INFO");
		std::cout << std::endl;
	case 2:
		harl.complain("WARNING");
		std::cout << std::endl;
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << BOLD MAGENTA << "🥱 [ Probably complaining about insignificant problems ] 🥱" << RESET << std::endl;
		return(1);
	}
}
