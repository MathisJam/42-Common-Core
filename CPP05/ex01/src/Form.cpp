/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:17:56 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 17:17:20 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"


// CANON FORM
Form::Form() : name("Papershit"), isSigned(false), toSign(4), toExec(4)
{
	std::cout << BOLD << "Default Form constructor called" << std::endl;
}

Form::Form(const Form &cpy) : isSigned(false), toSign(cpy.toSign), toExec(cpy.toExec)
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = cpy;
}

Form::Form(std::string name, int toSign, int toExec) : name(name), isSigned(false), toSign(toSign), toExec(toExec)
{
	std::cout << BOLD WHITE << "Form Constructor with args called" << std::endl;
	if (this->getToSign() < 1 || this->getToExec() < 1)
		throw GradeTooHighException();
	if (this->getToSign() > 150 || this->getToExec() > 150)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout << BOLD << "Form Destructor called" << std::endl;
}

Form &Form::operator=(const Form &param)
{
	if (this == &param)
		return(*this);
	return (*this);
}


//GETTERS
int Form::getToExec() const
{
	return (toExec);
}

int Form::getToSign() const
{
	return (toSign);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

std::string Form::getName() const
{
	return (name);
}

// SETTER

void Form::setIsSigned(bool sign)
{
	if (isSigned == true)
	{
		std::cout << BOLD CYAN << "Form is already signed but... let's do it again i guess 🙄" << RESET << std::endl;
	}
	else
		isSigned = sign;
}

// MEMBER FUNCTION

void	Form::beSigned(Bureaucrat &br)
{
	if (br.getGrade() <= toSign)
		setIsSigned(true);
	else
		throw GradeTooLowException();
}
//EXCEPTIONS
const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high 📈");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low 📉");
}
//OPERATOR <<
std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << BOLD GREEN << form.getName() << RESET BOLD << " needs grade " << BOLD YELLOW << form.getToSign() << RESET BOLD << " to be signed and grade "
	<< BOLD YELLOW << form.getToExec() << RESET BOLD <<" to be executed.\nSignature on this paper : " << BOLD YELLOW << form.getIsSigned() << " 👀" << RESET << std::endl;
	return os;
}
