/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:04:33 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/25 10:02:47 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


int	main()
{
	std::cout << std::endl << BOLD MAGENTA << "			LEARNING MATERIA\n"<< RESET << std::endl;
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	std::cout << std::endl << BOLD MAGENTA << "			MANAGING INVENTORY\n"<< RESET << std::endl;
	ICharacter* Patrick = new Character("Patrick ⭐");
	std::cout << std::endl;

	AMateria* ice0 = src->createMateria("ice");
	AMateria* cure1 = src->createMateria("cure");
	AMateria* ice2 = src->createMateria("ice");
	AMateria* cure3 = src->createMateria("cure");

	Patrick->equip(ice0);
	Patrick->equip(cure1);
	Patrick->equip(ice2);
	Patrick->equip(cure3);
	std::cout << std::endl;

	AMateria* cure4 = src->createMateria("cure");
	Patrick->equip(cure4);
	AMateria* cure5 = src->createMateria("cure");
	Patrick->unequip(2);
	Patrick->equip(cure5);

	std::cout << std::endl << BOLD MAGENTA << "			USING MATERIAS\n"<< RESET << std::endl;


	ICharacter* Bob = new Character("Bob 🧽");
	std::cout << std::endl;

	Patrick->use(0, *Bob);
	Patrick->use(1, *Bob);
	Patrick->use(2, *Bob);
	Patrick->use(3, *Bob);
	std::cout << std::endl;

	Bob->use(0, *Patrick);
	*Bob = *Patrick;
	AMateria* iced = src->createMateria("ice");
	Bob->equip(iced);
	Bob->use(0, *Patrick);

	delete Bob;
	delete Patrick;
	delete src;
}
