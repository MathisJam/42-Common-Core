/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:15:35 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/25 18:49:26 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat () : name ("Paul"), grade(5)
{
	std::cout << BOLD WHITE << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << BOLD WHITE << "Calling Bureaucrat name/grade constructor" << std::endl;
	if (grade < 1)
	{
		grade = 1;
		throw GradeTooHighException();
	}
	if (grade > 150)
	{
		grade = 150;
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
	std::cout << BOLD WHITE << "Bureaucrat Copy constructor called" << std::endl;
	*this = cpy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << BOLD WHITE << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &param)
{
	if (this == &param)
		return (*this);
	grade = param.grade;
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

std::string Bureaucrat::getName() const
{
	return(name);
}

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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high 📈");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low 📉");
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BOLD GREEN << this->name << BOLD WHITE << " signed " << BOLD GREEN << form.getName() << " 🖋️" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD RED << RESET BOLD GREEN << this->name << BOLD RED << " couldn't sign "
		<< RESET BOLD GREEN << form.getName() << BOLD RED << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &br)
{
	os << WHITE CYAN << br.getName() << ", bureaucrat grade " << br.getGrade() << " 🤓💼";
	return os;
}
