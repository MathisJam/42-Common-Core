/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:59:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 11:37:00 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() : type("default")
{
	std::cout << BOLD WHITE << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	*this = cpy;
	std::cout << BOLD WHITE << "Animal copy constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << BOLD WHITE << "Animal destructor called" << RESET << std::endl;
}

Animal &Animal::operator=(Animal const &param)
{
	if (this == &param)
		return(*this);
	this->type = param.type;
	return (*this);
}

void Animal::makeSound() const
{
		std::cout << BOLD RED << "🌬️  NO SOUNDS TO HEAR" << RESET << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}

