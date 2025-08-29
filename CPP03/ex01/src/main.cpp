/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:52:41 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 16:00:16 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main(void)
{

	{
		std::cout << BOLD GREEN << "*----TESTING CLAPTRAP----*\n" << RESET << std::endl;
		ClapTrap a("Karen");

		// *--------* UNCOMMENT TO TEST ENERGY *-----------*
		// for (int i = 0; i < 12; i++)
		//     b.attack("Julie");
		a.takeDamage(9);
		a.beRepaired(3);
		a.attack("Julie");
		a.takeDamage(10);
		a.attack("Julie");
	}
	std::cout << "\n" << std::endl;
	{
		std::cout << BOLD GREEN << "*----TESTING SCAVTRAP----*\n" << RESET << std::endl;

		ScavTrap Ro("Romain");

		// *--------* UNCOMMENT TO TEST ENERGY *-----------*
		// for (int i = 0; i < 49; i++)
		// 	Ro.attack("Paul");
		Ro.takeDamage(99);
		Ro.beRepaired(49);
		Ro.attack("Paul");
		Ro.takeDamage(50);
		Ro.attack("Paul");
		Ro.guardGate();
	}
}
