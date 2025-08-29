/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:22:13 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 11:37:09 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wdefault")
{
	std::cout << BOLD WHITE << "WrongAnimal default constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy)
{
	*this = cpy;
	std::cout << BOLD WHITE << "WrongAnimal copy constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BOLD WHITE << "WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &param)
{
	if (this == &param)
		return(*this);
	this->type = param.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
		std::cout << BOLD RED << "🌬️  NO SOUNDS TO HEAR (wrong animal)" << RESET << std::endl;
}
