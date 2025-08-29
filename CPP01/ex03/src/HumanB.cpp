/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:06:22 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/19 19:33:24 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void) const
{
	if (this->_weapon == NULL)
	{
		std::cout << BOLD << CYAN << this->_name << BOLD << RED <<  " attacks with his" << BOLD GREEN << " fists" << RESET << std::endl;
		return ;
	}
	else
		std::cout << BOLD << CYAN << this->_name << BOLD << RED << " attacks with his " << BOLD GREEN << _weapon->getType() << RESET << std::endl;
}
