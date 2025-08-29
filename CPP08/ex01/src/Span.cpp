/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:22 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/25 11:04:20 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::~Span()
{
	std::cout << BOLD ITALIC << "Destructor called" << RESET << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << BOLD ITALIC << "Constructor with N size called" << RESET << std::endl;
}

Span::Span(const Span &cpy) : _size(cpy._size)
{
	std::cout << BOLD ITALIC << "Copy constructor called" << RESET << std::endl;
}

Span &Span::operator=(const Span &param)
{
	if (this != &param)
	{
		_size = param._size;
	}
	return (*this);
}


void Span::addNumber(unsigned int nb)
{
	if (_span.size() < _size)
	{
		_span.push_back(nb);
		return;
	}
	throw (std::runtime_error("Span max size reached, cannot add"));
}

unsigned int Span::shortestSpan() const
{
	if (_span.size() <= 1)
		throw(std::logic_error("Not enough numbers in the vector"));

	std::vector<int> tmp = _span;
	std::sort(tmp.begin(), tmp.end());

	unsigned int min_elem = std::numeric_limits<unsigned int>::max();
	for(size_t i = 1; i < tmp.size(); i++)
	{
		unsigned int diff = tmp[i] - tmp[i - 1];
		if (diff < min_elem)
			min_elem = diff;
	}
	return (min_elem);
}

unsigned int Span::longestSpan() const
{
	if (_span.size() <= 1)
		throw(std::logic_error("Not enough numbers in the vector"));

	int min = *std::min_element(_span.begin(), _span.end());
	int max = *std::max_element(_span.begin(), _span.end());

	return (max - min);
}


