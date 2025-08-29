/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:52:48 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 16:08:51 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("R2D2_clap_name"), _name("R2D2")
{
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;

	std::cout << BOLD YELLOW << "DiamondTrap constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;

	std::cout << BOLD YELLOW << "DiamondTrap constructor by name called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	*this = cpy;
	std::cout << BOLD YELLOW << "DiamondTrap constructor by copy called" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BOLD YELLOW << "DiamondTrap destructor called" << RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &param)
{
	if (this != &param)
	{
		ClapTrap::operator=(param);
		_name = param._name;
	}
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << BOLD BLUE << "💎 Hi, I am " << BOLD MAGENTA << _name << BOLD BLUE << " and my ClapTrap name is " << BOLD GREEN << ClapTrap::_name << RESET << std::endl;
}
