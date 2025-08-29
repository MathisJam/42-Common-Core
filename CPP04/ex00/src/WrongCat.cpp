/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:24:34 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 11:38:49 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << BOLD YELLOW << "WrongCat default constructor called" << RESET << std::endl;
	this->type = "WrongCat";
}
WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal()
{
	*this = cpy;
	std::cout << BOLD YELLOW << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << BOLD YELLOW << "WrongCat destructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &param)
{
	if (this == &param)
		return(*this);
	this->type = param.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << BOLD YELLOW << "🦁 RAAAAAAAAAAWWWWWRRR" << RESET << std::endl;
	std::cout << WHITE << "   wait... that's a big cat 😱" << RESET << std::endl;
}
