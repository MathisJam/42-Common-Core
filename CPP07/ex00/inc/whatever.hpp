/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:37:24 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/14 11:19:36 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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

template <typename S>
void swap(S &a, S &b)
{
	S temp;
	temp = a;
	a = b;
	b = temp;
};

template <typename N>
const N &min(const N &a, const N &b)
{
	return (a < b ? a : b);
}

template <typename Nb>
const Nb &max(const Nb &a, const Nb &b)
{
	return (a > b ? a : b);
}

#endif
