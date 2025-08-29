/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:03:08 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/19 19:02:52 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cout << BOLD RED << "Error ❌ : Usage: ./harl [DEBUG/INFO/WARNING/ERROR]" << RESET << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
