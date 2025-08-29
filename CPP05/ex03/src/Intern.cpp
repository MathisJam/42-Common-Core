/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:57:30 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 16:55:01 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

// CANON FORM
Intern::Intern()
{
	std::cout << BOLD << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	std::cout << BOLD << "Intern constructor by copy called" << RESET << std::endl;
	*this = cpy;
}

Intern::~Intern()
{
	std::cout << BOLD << "Intern destructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &param)
{
	if (this == &param)
		return (*this);
	return(*this);
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *makePresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(*formMakers[3])(const std::string) = {&makeShrubbery, &makeRobotomy, &makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << BOLD YELLOW << "Intern creates " << BOLD GREEN << formNames[i] << RESET << std::endl;
			return (formMakers[i](target));
		}
	}
	std::cerr << BOLD RED << "Unknown Form, try : ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm" << RESET << std::endl;
	return NULL;
}
