/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:13:48 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/25 11:30:04 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << BOLD YELLOW << "Cat default constructor called" << RESET << std::endl;
}
Cat::Cat(Cat const &cpy) : Animal()
{
	*this = cpy;
	std::cout << BOLD YELLOW << "Cat copy constructor called" << RESET << std::endl;
}

Cat &Cat::operator=(Cat const &param)
{
	if (this == &param)
		return(*this);
	this->type = param.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << BOLD << this->getType() << "​​ 🐱​:" << BOLD << " MEOW MEOW MEOW" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << BOLD YELLOW << "Cat destructor called" << RESET << std::endl;
}
