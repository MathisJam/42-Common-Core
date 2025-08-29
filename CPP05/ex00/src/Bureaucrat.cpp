/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:15:35 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 17:11:45 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"


//CANON FORM
Bureaucrat::Bureaucrat () : name ("Paul"), grade(5)
{
	std::cout << BOLD WHITE << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << BOLD WHITE << "Calling name/grade constructor" << std::endl;
	if (grade < 1)
	{

		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
	std::cout << BOLD WHITE << "Copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BOLD WHITE << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &param)
{
	if (this == &param)
		return (*this);
	grade = param.grade;
	return (*this);
}


// GETTERS
int Bureaucrat::getGrade() const
{
	return (grade);
}

std::string Bureaucrat::getName() const
{
	return(name);
}


// MEMBER FUNCTIONS
void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

// EXCEPTIONS
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high 📈");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low 📉");
}

// OPERATOR <<
std::ostream &operator<<(std::ostream &os, const Bureaucrat &br)
{
	os << WHITE CYAN << br.getName() << ", bureaucrat grade " << br.getGrade() << " 🤓💼";
	return os;
}
