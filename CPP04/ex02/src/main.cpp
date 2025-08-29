/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:24:43 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 15:01:28 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongCat.hpp"

int main()
{
	std::cout << BOLD GREEN << "\nTESTING ANIMAL TAB" << RESET << std::endl;
	Animal* tab[6];
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			tab[i] = new Dog();
			tab[i]->makeSound();
		}
		else
		{
			tab[i] = new Cat();
			tab[i]->makeSound();
		}
	}
	std::cout << std::endl;

	std::cout << BOLD GREEN << "\nDELETE TAB" << RESET << std::endl;
	for (int i = 0; i < 6; i++)
		delete tab[i];

	std::cout << BOLD GREEN << "\nCREATING FIRST DOG/BRAIN" << RESET << std::endl;
	Dog* Bonnie = new Dog();

	for (int i = 0; i < 100; i++)
		Bonnie->getBrain()->setIdea(i, BOLD CYAN "LETS GO TO THE PARK 🌲🌲 " RESET);
	int i = 0;
	std::cout << BOLD GREEN << "\nBRAIN IDEAS CHECK :\n" << RESET;
	while(i < 10)
		std::cout << Bonnie->getBrain()->getIdea(i++) << std::endl;
	std::cout << BOLD GREEN << "\nBRAIN ADRESS CHECK" << RESET << std::endl;
	std::cout << BOLD RED << "Bonnie brain = " << Bonnie->getBrain()->getIdeasAdress() << std::endl;

	std::cout << BOLD GREEN << "\nCREATING SECOND DOG/BRAIN" << RESET << std::endl;
	Dog* Clyde = new Dog();

	std::cout << BOLD GREEN << "\nASSIGNING BONNIE IDEAS TO CLYDE" << RESET << std::endl;
	*Clyde = *Bonnie;

	std::cout << BOLD GREEN "\nBRAIN IDEAS CHECK :\n" << RESET;
	i = 0;
	while(i < 10)
		std::cout << Clyde->getBrain()->getIdea(i++) << std::endl;;
	std::cout << BOLD GREEN << "\nBRAIN ADRESS CHECK : \n" << RESET;
	std::cout << BOLD RED << "Clyde brain = " << Clyde->getBrain()->getIdeasAdress() << std::endl;

	std::cout << BOLD GREEN << "\nDELETE" << std::endl;
	delete Clyde;
	delete Bonnie;

	return(0);
}
