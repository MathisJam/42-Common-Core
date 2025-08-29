/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:54:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 11:57:19 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"


// --- CONSTRUCTORS DESTRUCTORS

ClapTrap::ClapTrap()  : _name("Julie"), _hp(10), _energy(10), _damage(0)
{
	std::cout << BOLD YELLOW << "Default constructor called" << RESET <<  std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _energy(10), _damage(0)
{
	std::cout << BOLD YELLOW << "Constructor with name called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

ClapTrap::~ClapTrap()
{
	std::cout << BOLD YELLOW << "Destructor called" << RESET << std::endl;
}

// --- OPERATORS
ClapTrap &ClapTrap::operator=(const ClapTrap &param)
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


// --- MEMBER FUNCTIONS

void ClapTrap::attack(const std::string &target)
{
	if (this->_energy <= 0)
	{
		std::cout << BOLD BLUE << "No energy left, ClapTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << BOLD BLUE << "No HP left, ClapTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	std::cout << BOLD GREEN << "🤖 ClapTrap " << BOLD MAGENTA << this->_name << RED << " attacks " << BOLD BLUE << target << RED <<" causing " << YELLOW << this->_damage <<  RED <<" points of damage 🗡️" << RESET << std::endl;
	this->_energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << BOLD GREEN << "🤖 ClapTrap " << BOLD MAGENTA << this->_name << BOLD RED " got hit dealing them " << BOLD YELLOW << amount << " points of damage" << RESET << std::endl;
	if (this->_hp <= amount)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std::cout << BOLD CYAN << "HP Left : " << this->_hp << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy <= 0)
	{
		std::cout << BOLD BLUE << "No energy left, ClapTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << BOLD BLUE << "No HP left, ClapTrap " << BOLD MAGENTA << _name << BOLD BLUE << " can't do anything 😭 " << RESET << std::endl;
		return ;
	}
	std::cout << BOLD GREEN << "🤖 ClapTrap " << BOLD MAGENTA << this->_name << BOLD BLUE << " repaired themselve " << BOLD YELLOW << amount << " hit points ! Yeah!!" << RESET << std::endl;
	std::cout << BOLD CYAN << "Previous HP : " << this->_hp << std::endl;
	if (this->_hp > 10)
		_hp = 10;
	else
		_hp += amount;
	std::cout << "HP Left now : " << this->_hp << RESET << std::endl;
	this->_energy -= 1;
}
