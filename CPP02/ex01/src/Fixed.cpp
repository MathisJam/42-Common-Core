/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:57:50 by mjameau           #+#    #+#             */
/*   Updated: 2025/08/29 11:11:09 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

//---------------------------- CONSTRUCTORS DESTRUCTOR -------------------------------------
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	this->_value = value << _bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//---------------------------MEMBER FUNCTIONS-----------------------------------------------

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt() const
{
	return (_value >> _bits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << BOLD YELLOW << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}

//-----------------------------OPERATORS---------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Fixed &param)
{
	os << param.toFloat();
	return os;
}

Fixed &Fixed::operator=(const Fixed &param)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &param)
		this->_value = param.getRawBits();
	return (*this);
}
