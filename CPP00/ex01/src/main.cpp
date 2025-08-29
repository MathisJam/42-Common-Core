/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:18:21 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/17 12:31:51 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook P_Inst;
	std::string command;

	std::cout << " " << std::endl << BOLD GREEN << "Choose a command ---"
	<< RESET << std::endl << " " << std::endl << BOLD YELLOW << "ADD : Add a contact 📞" <<
	RESET << std::endl << BOLD BLUE << "SEARCH : Search a contact 📋" << RESET << std::endl
	<< BOLD RED << "EXIT : Exit the PhoneBook 👋" << RESET << std::endl << " " << std::endl
	<< BOLD GREEN << "-------------------------------" << RESET << std::endl << std::endl;
	while(true)
	{
		std::cout << BOLD WHITE << "Command : " << RESET;
		if (std::getline(std::cin, command).fail() == 1)
		{
			std::cout << " " << std::endl;
			break;
		}
		else
		{
			if (command == "ADD")
			{
				P_Inst.addContact();
			}
			else if (command == "SEARCH")
			{
				P_Inst.searchContact();
			}
			else if (command == "EXIT")
			{
				break;
			}
			else
			{
				std::cout << BOLD RED << "Unknown command ❌" << RESET << std::endl;
			}
		}
	}
}
