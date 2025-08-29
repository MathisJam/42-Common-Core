/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:18:39 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 13:33:19 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << BOLD YELLOW << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	std::cout << BOLD YELLOW << "Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = cpy.ideas[i];
}

Brain::~Brain()
{
	std::cout << BOLD YELLOW << "Brain destructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &param)
{
	if (this == &param)
		return (*this);
	for (int i = 0; i < 100; i++)
	{
		if (param.ideas->length() > 0)
			this->ideas[i] = param.ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int i)
{
	if (i > 100)
		return ("No ideas at this index");
	return (this->ideas[i]);
}

std::string* Brain::getIdeasAdress()
{
	return (this->ideas);
}

void Brain::setIdea(int i, std::string idea)
{
	if (i < 100)
		this->ideas[i] = idea;
	else
		std::cout <<BOLD RED << "Too much ideas already BIG BRAINZ 🧠🤯" << RESET << std::endl;
}
