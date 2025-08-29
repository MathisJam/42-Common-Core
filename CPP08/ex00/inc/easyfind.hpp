/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:03 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/14 17:14:34 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
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

template <typename T>
typename T::iterator easyfind(T &C, int nb)
{
	for (typename T::iterator found = C.begin(); found != C.end(); ++found)
	{
		if (*found == nb)
			return (found);
	}
	throw (std::runtime_error("No occurence found"));
}

#endif
