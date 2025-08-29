/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:03:06 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 18:30:30 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}


Cure::Cure(const Cure &src)
{
	_type = src._type;
}


Cure::~Cure()
{
}


Cure	&Cure::operator=(const Cure &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}




AMateria	*Cure::clone() const
{
	Cure* newCure = new Cure(*this);

	std::cout << BOLD WHITE << "Cloned the " << BOLD BLUE << _type << BOLD WHITE << " materia at address "
			  << BOLD YELLOW << newCure << RESET << std::endl;
	return (newCure);
}


void	Cure::use(ICharacter& target)
{
	std::cout << BOLD WHITE << "*Heals " << BOLD GREEN << target.getName() << BOLD WHITE << "'s wounds* 🩹" << RESET << std::endl;
}
