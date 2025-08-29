/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:02:29 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 19:06:46 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"

Character::Character() : _name("???")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << BOLD GREEN << _name << RESET << BOLD WHITE << " entered the fight 🗡️ 🛡️" << RESET << std::endl;
}


Character::Character(const std::string inputName) : _name(inputName)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << BOLD GREEN << _name << RESET << BOLD WHITE << " entered the fight 🗡️ 🛡️" << std::endl;
}


Character::Character(const Character &src)
{
	*this = src;
}


Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	std::cout << BOLD GREEN << _name << BOLD RED << " died 💀" << RESET << std::endl;

}


Character	&Character::operator=(const Character &src)
{
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (src._inventory[i])
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}

	return (*this);
}

std::string const	&Character::getName() const
{
	return (_name);
}


void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << BOLD RED << "Oh this materia seems NULL" << RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << BOLD GREEN << _name << BOLD WHITE << " equipped the "
					  << BOLD BLUE << m->getType() << RESET << BOLD WHITE " materia in the slot n°" << i << " 👜" << std::endl;
			return;
		}

	}
	std::cout << BOLD RED << "Can't equip the materia, your inventory is already full! "
			  << "The Materia has been destroyed...💥"  << RESET << std::endl;
	delete m;
}


void	Character::unequip(int idx)
{
	if ((0 <= idx && idx < 4) && _inventory[idx])
	{
		std::cout << BOLD GREEN << _name << BOLD WHITE << " unequipped the "
				  << BOLD BLUE << _inventory[idx]->getType() << RESET << BOLD WHITE << " materia in the slot n°" << idx << " 🗑️" << std::endl;
		delete _inventory[idx];
		_inventory[idx] = NULL;

		return;
	}
	std::cout << BOLD RED << "There's nothing in this slot to unequip 🔎" << RESET << std::endl;
}


void	Character::use(int idx, ICharacter &target)
{
	if (0 > idx || idx >= 4 || !_inventory[idx])
		std::cout << BOLD RED << _name <<  " tries to use a materia, but there's nothing in this slot! 🫗" << RESET << std::endl;
	else
	{
		std::cout << BOLD GREEN << _name << BOLD WHITE << " uses the "
				  << BOLD BLUE << _inventory[idx]->getType() << RESET << BOLD WHITE << " materia on " << BOLD GREEN << target.getName() << " : ";
		_inventory[idx]->use(target);
	}
}
