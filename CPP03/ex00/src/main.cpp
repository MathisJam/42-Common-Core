/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:48:34 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 15:59:59 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main(void)
{
	std::cout << BOLD GREEN << "*----TESTING CLAPTRAP----*\n" << RESET << std::endl;\

	ClapTrap b("Karen");

	// *--------* UNCOMMENT TO TEST ENERGY *-----------*
	// for (int i = 0; i < 12; i++)
	//     b.attack("Julie");
	b.takeDamage(9);
	b.beRepaired(3);
	b.attack("Julie");
	b.takeDamage(10);
	b.attack("Julie");
}
