/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:03:15 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/19 19:30:22 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << BOLD MAGENTA << "DEBUG :" << RESET << std::endl;
	std::cout << BOLD CYAN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do! 🐷​" << RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << BOLD RED << "INFO :" << RESET << std::endl;
	std::cout << BOLD BLUE << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more! 🍔" << RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << BOLD YELLOW << "WARNING :" << RESET << std::endl;
	std::cout << BOLD MAGENTA << "I think I deserve to have some extra bacon for free. I've been coming here for years and you just started working here last month. 💸" << RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << BOLD GREEN << "ERROR :" << RESET << std::endl;
	std::cout << BOLD RED << "This is unacceptable. I want to speak to the manager now. 😡😤" << RESET << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << BOLD RED << "Invalid level, Harl doesn't know what to say" << RESET << std::endl;
}
