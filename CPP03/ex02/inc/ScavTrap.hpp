/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:49:32 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/10 11:59:53 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

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

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &cpy);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &param);
		void attack(const std::string &target);
		void guardGate();

	private :
};

#endif
