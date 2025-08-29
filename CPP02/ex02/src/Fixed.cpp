/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:33:44 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/05 17:06:42 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

//---------------------------- CONSTRUCTORS DESTRUCTOR -------------------------------------
Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int value)
{
	this->_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &cpy)
{
	*this = cpy;
}

Fixed::~Fixed()
{
}

//---------------------------MEMBER FUNCTIONS-----------------------------------------------

int Fixed::getRawBits() const
{
	return this->_value;
}

float Fixed::toFloat() const
{
	return static_cast<float>(_value) / (1 << _bits);
}

int Fixed::toInt() const
{
	return(_value >> _bits);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

//-----------------------------OPERATORS---------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Fixed &param)
{
	os << param.toFloat();
	return os;
}

Fixed &Fixed::operator=(const Fixed &param)
{
	if (this != &param)
		this->_value = param.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed res;

	res._value = this->_value + fixed._value;
	return (res);
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed res;

	res._value = this->_value - fixed._value;
	return (res);
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed res;

	res._value = (this->_value * fixed._value) >> _bits;
	return (res);
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	if (fixed._value == 0)
	{
		std::cerr << "Error : Division by 0" << std::endl;
		Fixed error(0);
		return error;
	}

	Fixed res;

	res._value = ((this->_value << _bits) / fixed._value);
	return (res);
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (this->_value < fixed._value);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (this->_value > fixed._value);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_value >= fixed._value);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_value <= fixed._value);
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (this->_value == fixed._value);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_value != fixed._value);
}

Fixed &Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_value += 1;
	return (temp);
}

Fixed &Fixed::operator--()
{
	--_value;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_value -= 1;
	return (temp);
}
