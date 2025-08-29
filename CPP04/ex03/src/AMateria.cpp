/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:01:09 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 16:20:10 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}


AMateria::AMateria(std::string const &type) : _type(type)
{
}


AMateria::AMateria(const AMateria &src)
{
	_type = src._type;
}


AMateria::~AMateria()
{
}


AMateria&	AMateria::operator=(const AMateria &src)
{
	if (this != &src)
		_type = src._type;

	return (*this);
}

std::string const&	AMateria::getType() const
{
	return (_type);
}


void	AMateria::use(ICharacter& target)
{
	std::cout << BOLD WHITE << "*use the " << BOLD CYAN << _type << " materia on " << BOLD GREEN << target.getName() << "* 🪩" << RESET << std::endl;
}
