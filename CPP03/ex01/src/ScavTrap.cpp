/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:04:55 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 12:44:51 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_hp = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << BOLD YELLOW << "ScavTrap " << BOLD MAGENTA << name << BOLD YELLOW << " constructed!" << RESET << std::endl;
	_hp = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << BOLD YELLOW << "ScavTrap destructor called for " << BOLD MAGENTA << _name << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energy <= 0)
	{
		std::cout << BOLD BLUE << "No energy left, " << BOLD GREEN << "ScavTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << BOLD BLUE << "No HP left, " << BOLD GREEN << "ScavTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	std::cout << BOLD GREEN << "🤖 ScavTrap " << BOLD MAGENTA << this->_name << RED << " attacks " << BOLD BLUE << target << RED <<" causing " << YELLOW << this->_damage <<  RED <<" points of damage 💥🔫" << RESET << std::endl;
	this->_energy -= 1;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &param)
{
	if (this != &param)
	{
		this->_name = param._name;
		this->_hp = param._hp;
		this->_energy = param._energy;
		this->_damage = param._damage;
	}
	return *this;
}

void ScavTrap::guardGate()
{
	if (this->_energy <= 0)
	{
		std::cout << BOLD BLUE << "No energy left, ScavTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << BOLD BLUE << "No HP left, ScavTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	std::cout << BOLD GREEN << "ScavTrap " << BOLD MAGENTA << _name << BOLD BLUE << " is now in Gatekeeper mode" << RESET << std::endl;
}
