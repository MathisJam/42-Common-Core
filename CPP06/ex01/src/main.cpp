/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:51:16 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/11 10:53:29 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main(void)
{
	Data ptrN;

	ptrN.name = "Marie-Edith";
	ptrN.age = 78;
	ptrN.fav_emoji = "🤡";
	ptrN.next = NULL;

	Data ptr;

	ptr.name = "Jean-Michel";
	ptr.age = 67;
	ptr.fav_emoji = "🤣😂";
	ptr.next = &ptrN;

	//--------------------------------------PRINTING ORIGINAL VALUES----------------------------------------------------//
	std::cout << BOLD MAGENTA << "\n\t\t\tORIGINAL DATA STRUCTURE\n";

	std::cout << BOLD GREEN << "First pointer :\n" << RESET BOLD <<
	"\tAdress : " << &ptr << "\n\tName : " << ptr.name << "\n\tAge : " << ptr.age
	<< "\n\tFavorite emoji : " << ptr.fav_emoji << "\n\tNext ptr : " << ptr.next << std::endl;

	std::cout << BOLD GREEN << "\nSecond pointer :\n" << RESET BOLD <<
	"\tAdress : " << &ptrN << "\n\tName : " << ptrN.name << "\n\tAge : " << ptrN.age
	<< "\n\tFavorite emoji : " << ptrN.fav_emoji << "\n\tSext : " << ptrN.next << std::endl;

	std::cout << std::endl;

	//--------------------------------------TESTING SERIALIZATION----------------------------------------------------//
	Data *ser = Serializer::deserialize(Serializer::serialize(&ptr));
	Data *serN = Serializer::deserialize(Serializer::serialize(&ptrN));

	std::cout << BOLD MAGENTA << "\t\t\tRESULTS AFTER SERIALIZATION/DESERIALIZATION\n";

	std::cout << BOLD GREEN << "First pointer :\n" << RESET BOLD <<
	"\tAdress : " << ser << "\n\tName : " << ser->name << "\n\tAge : " << ser->age
	<< "\n\tFavorite emoji : " << ser->fav_emoji << "\n\tNext : " << ser->next << std::endl;

	std::cout << BOLD GREEN << "\nSecond pointer :\n" << RESET BOLD <<
	"\tAdress : " << serN << "\n\tName : " << serN->name << "\n\tAge : " << serN->age
	<< "\n\tFavorite emoji : " << serN->fav_emoji << "\n\tNext : " << serN->next << std::endl;

	//-------------------------------------CHECKING SERIALIZED ADRESS------------------------------------------------------//
	std::cout << BOLD MAGENTA << "\t\t\tDOING IT IN 2 TIMES (CHECKING THE SERIALIZED ADRESS)" << std::endl;

	uintptr_t raw = Serializer::serialize(&ptr);
	std::cout << BOLD GREEN << "\nSerialized pointer adress : \n\t" << RESET BOLD << raw << std::endl;

	Data *ptrNN = Serializer::deserialize(raw);
    std::cout << BOLD GREEN << "\nDeserialized Data: " << RESET BOLD << "\n\tAdress : " << ptrNN << "\n\tName : " << ptrNN->name << "\n\tAge : "
	<< ptrNN->age << "\n\tFavorite emoji : " << ptrNN->fav_emoji << "\n\tNext : " << ptrNN->next << std::endl;;
}
