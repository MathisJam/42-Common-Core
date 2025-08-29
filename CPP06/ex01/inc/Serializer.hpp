/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:43:28 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/31 10:36:00 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>
#include <stdint.h>

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



typedef struct Data
{
	std::string name;
	std::string fav_emoji;
	size_t age;
	Data *next;
}		Data;

class Serializer
{
	public :
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private :
		Serializer();
		~Serializer();
		Serializer(const Serializer &cpy);
		Serializer &operator=(const Serializer &param);
};

#endif
