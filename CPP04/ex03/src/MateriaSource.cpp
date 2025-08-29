/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:10:00 by jchen             #+#    #+#             */
/*   Updated: 2025/03/23 19:02:38 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
}


MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}


MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i])
			delete _slots[i];
	}
}


MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_slots[i])
				delete _slots[i];
			if (src._slots[i])
				_slots[i] = src._slots[i]->clone();
			else
				_slots[i] = NULL;
		}
	}

	return (*this);
}

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
	{
		std::cout << BOLD RED << "This materia seems NULL" << RESET << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = materia;
			std::cout << BOLD WHITE << "The Source successfully learned the " << BOLD BLUE << materia->getType() << BOLD WHITE
					  << " materia at address " << BOLD YELLOW << materia << "📚" << RESET << std::endl;
			return;
		}

	}

	std::cout << BOLD RED << "Can't learn the materia, the source is already full 🫄" << RESET << std::endl;
	delete materia;
}


AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] && _slots[i]->getType() == type)
		{
			return(_slots[i]->clone());
		}
	}

	std::cout << BOLD RED << "Unknown materia, the source has to learn it first" << RESET << std::endl;
	return (NULL);
}
