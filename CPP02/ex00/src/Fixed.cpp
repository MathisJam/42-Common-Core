/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:33:05 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/05 13:51:42 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << BOLD GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(Fixed const &cpy)
{
	std::cout << BOLD CYAN << "Copy constructor called" << RESET << std::endl;
	*this = cpy;
}

Fixed &Fixed::operator=(const Fixed &param)
{
	std::cout << BOLD BLUE << "Copy assignement operator called" << RESET << std::endl;
	if (this != &param)
		_value = param.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << BOLD YELLOW << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}

int Fixed::getRawBits() const
{
	std::cout << BOLD MAGENTA << "getRawBits member function called" << RESET << std::endl;
	return this->_value;
}

Fixed::~Fixed()
{
	std::cout << BOLD RED << "Destructor called" << RESET << std::endl;
}
