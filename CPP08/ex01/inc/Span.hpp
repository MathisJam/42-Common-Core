/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:25 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/25 10:47:18 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <limits>
#include <deque>
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class Span
{
	public :
	// CANON FORM (Default constructor in private bcs useless)
		~Span();
		Span(const Span &cpy);
		Span &operator=(const Span &param);

	// UNSIGNED INT CONSTRUCTOR
		Span(unsigned int N);

	// MEMBER FUNCTIONS
		void addNumber(unsigned int nb);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

	// TEMPLATE FUNCTION
	template <typename IT>
	void addMore(IT first, IT last)
	{
		size_t it_size = std::distance(first, last);
		if (_span.size() + it_size > _size)
			throw (std::logic_error("Adding those numbers would exceed Span size"));
		_span.insert(_span.end(), first, last);
	}

	private :
		std::vector<int> _span;
		size_t _size;
		Span();

};

#endif
