/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:17:19 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 11:21:42 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << BOLD YELLOW << "Dog default constructor called" << RESET << std::endl;
	this->type = "Dog";
}
Dog::Dog(const Dog &cpy) : Animal()
{
	*this = cpy;
	std::cout << BOLD YELLOW << "Dog copy constructor called" << RESET << std::endl;
}

Dog &Dog::operator=(Dog const &param)
{
	if (this == &param)
		return(*this);
	this->type = param.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << BOLD << this->getType() << "​​ 🐶​:" << BOLD << " WOOF WOOF WOOF" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << BOLD YELLOW << "Dog destructor called" << RESET << std::endl;
}

