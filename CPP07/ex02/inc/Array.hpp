/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:37:03 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/14 14:56:47 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

template <typename T>
class Array
{
	public :
	//--------------- CONSTRUCTORS DESTRUCTOR -----------------------
		Array() : _size(0)
		{
			std::cout << BOLD << "Default constructor called" << RESET << std::endl;
			_arr = new T[_size]();
		};

		Array(unsigned int n) : _size(n)
		{
			std::cout << BOLD << "Constructor with arg called" << RESET << std::endl;
			_arr = new T[_size]();
		};

		Array(const Array &cpy) : _size(cpy._size)
		{
			std::cout << BOLD << "Copy constructor called" << RESET << std::endl;
			_arr = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_arr[i] = cpy._arr[i];
		};

		~Array()
		{
			std::cout << BOLD << "Destructor called" << RESET << std::endl;
			delete[] _arr;
		}

	//---------------- OPERATORS ---------------------------
		Array &operator=(const Array &param)
		{
			if (this != &param)
			{
				delete[] _arr;
				_size = param._size;
				_arr = new T[_size];
				for (size_t i = 0; i < _size; i++)
					_arr[i] = param._arr[i];
			}
			return (*this);
		};

		T &operator[](size_t i)
		{
			if (i >= _size)
				throw (std::out_of_range(BOLD RED"Index out of bonds"));
			return (_arr[i]);
		}

		const T &operator[](size_t i) const
		{
			if (i >= _size)
				throw (std::out_of_range(BOLD RED"Index out of bonds"));
			return (_arr[i]);
		}

	//--------------------- MEMBER FUNCTION -------------------
		size_t size() const
		{
			return _size;
		};

	private :
		size_t	_size;
		T* _arr;
};

#endif
