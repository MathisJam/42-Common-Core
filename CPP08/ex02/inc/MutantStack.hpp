/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:12 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/27 10:08:58 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include <limits>
#include <deque>
#include <stack>
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

// PAS LE DROIT AU FICHER .CPP ET CLASSE TEMPLATE DONC CODE DANS HPP


template <typename T>
class MutantStack : public std::stack<T>
{
	public :
	// CANON FORM
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &cpy) : std::stack<T>(cpy) {}
		~MutantStack() {}
		MutantStack &operator=(const MutantStack &param)
		{
			if (this != &param)
				this = param;
			return *this;
		}

	// ITERATORS
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	// ITERATOR FUNCTIONS
	iterator end() { return (this->c.end()); }
	iterator begin() { return (this->c.begin()); }

	const_iterator end() const { (this->c.end()); }
	const_iterator begin() const { return (this->c.begin()); }
	private :

};

#endif
