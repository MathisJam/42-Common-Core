/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:24:43 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 12:03:03 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* cat = new Cat();
	const Animal* dog = new Dog();

	std::cout<< BOLD GREEN << "\nTESTING GETTYPE FUNCTION"<< RESET <<std::endl;
	std::cout << BOLD << "Expected : Cat, result : " << cat->getType() << std::endl;
	std::cout << BOLD << "Expected : Dog, result : " <<dog->getType() << std::endl;

	std::cout<< BOLD GREEN << "\nTESTING MAKESOUND FUNCTION"<< RESET << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout<< BOLD GREEN << "\nTESTING WRONGANIMAL CLASS"<< RESET << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout<< BOLD GREEN << "\nTESTING WRONGANIMAL GETTYPE FUNCTION"<< RESET <<std::endl;
	std::cout << BOLD << "Expected : WrongCat, result : " << wrongCat->getType() << std::endl;

	std::cout<< BOLD GREEN << "\nTESTING WRONGANIMAl MAKESOUND FUNCTION"<< RESET << std::endl;
	wrongCat->makeSound();
	wrongCat->makeSound();

	std::cout << BOLD GREEN << "\nTESTING WRONGCAT MAKESOUND AS WRONGCAT" << RESET << std::endl;
	const WrongCat*	lion = new WrongCat();
	std::cout << std::endl;
	lion->makeSound();

	std::cout << BOLD GREEN << "\nDELETE" << RESET << std::endl;
	delete cat;
	delete dog;
	delete meta;

	std::cout << BOLD GREEN << "\nDELETE WRONGANIMAL + WRONGCAT" << RESET << std::endl;
	delete wrongCat;
	delete wrongMeta;
	delete lion;

	return(0);
}
