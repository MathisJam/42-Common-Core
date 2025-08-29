/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:52:41 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 12:47:38 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

int main(void)
{

	{
		std::cout << BOLD GREEN << "*----TESTING CLAPTRAP----*\n" << RESET << std::endl;

		ClapTrap Ka("Karen");

		// *--------* UNCOMMENT TO TEST ENERGY *-----------*
		// for (int i = 0; i < 12; i++)
		//     Ka.attack("Julie");
		Ka.takeDamage(9);
		Ka.beRepaired(3);
		Ka.attack("Julie");
		Ka.takeDamage(10);
		Ka.attack("Julie");
	}
	std::cout << "\n" << std::endl;
	{
		std::cout << BOLD GREEN << "*----TESTING SCAVTRAP----*\n" << RESET << std::endl;

		ScavTrap Ro("Romain");

		// *--------* UNCOMMENT TO TEST ENERGY *-----------*
		// for (int i = 0; i < 52; i++)
		// 	Ro.attack("Paul");
		Ro.takeDamage(99);
		Ro.beRepaired(49);
		Ro.attack("Paul");
		Ro.takeDamage(50);
		Ro.attack("Paul");
		Ro.guardGate();
	}
	std::cout << "\n" << std::endl;
	{

		std::cout << BOLD GREEN << "*----TESTING FRAGTRAP----*\n" << RESET << std::endl;

		FragTrap Ma("Mathis");

		// *--------* UNCOMMENT TO TEST ENERGY *-----------*
		// for (int i = 0; i < 102; i++)
		// 	Ma.attack("Paul");
		Ma.takeDamage(99);
		Ma.beRepaired(49);
		Ma.attack("Karen");
		Ma.HighFives();
		Ma.takeDamage(50);
		Ma.attack("Karen");
		Ma.HighFives();
	}
}
