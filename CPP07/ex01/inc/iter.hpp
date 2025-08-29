/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:37:10 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/14 12:12:53 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

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

template <typename P>
void printIndex(const P& i)
{
	std::cout << BOLD RED << i << RESET BOLD << " | ";
}

template <typename T, size_t N>
void iter(T (&array)[N], void (*foo)(const T&))
{
	for (size_t i = 0; i < N; i++)
		foo(array[i]);
}

#endif

