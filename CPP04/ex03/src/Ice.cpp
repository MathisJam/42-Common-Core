/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:09:51 by jchen             #+#    #+#             */
/*   Updated: 2025/03/23 18:30:09 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}


Ice::Ice(const Ice &src)
{
	_type = src._type;
}


Ice::~Ice()
{
}

Ice	&Ice::operator=(const Ice &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}

AMateria	*Ice::clone() const
{
	Ice* newIce = new Ice(*this);

	std::cout << BOLD WHITE << "Cloned the " << BOLD BLUE << _type << BOLD WHITE << " materia at address "
			  << BOLD YELLOW << newIce << RESET << std::endl;
	return (newIce);
}


void	Ice::use(ICharacter& target)
{
	std::cout << BOLD WHITE << "*Shoots an ice bolt at " << BOLD GREEN << target.getName() << BOLD WHITE << "* 🧊" << RESET << std::endl;
}
