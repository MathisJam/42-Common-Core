/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:05:53 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 15:03:17 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/AForm.hpp"


// CANON FORM
AForm::AForm() : name("Papershit"), isSigned(false), toSign(4), toExec(4)
{
	std::cout << BOLD << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &cpy) : toSign(cpy.toSign), toExec(cpy.toExec)
{
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = cpy;
}

AForm::AForm(std::string name, int toSign, int toExec) : name(name), isSigned(false), toSign(toSign), toExec(toExec)
{
	std::cout << BOLD WHITE << "AForm Constructor with args called" << std::endl;
	if (this->getToSign() < 1 || this->getToExec() < 1)
		throw GradeTooHighException();
	if (this->getToSign() > 150 || this->getToExec() > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << BOLD << "AForm Destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &param)
{
	if (this == &param)
		return(*this);
	return (*this);
}

// GETTERS
int AForm::getToExec() const
{
	return (toExec);
}

int AForm::getToSign() const
{
	return (toSign);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

std::string AForm::getName() const
{
	return (name);
}

// SETTER

void AForm::setIsSigned(bool sign)
{
	if (isSigned == true)
	{
		std::cout << BOLD CYAN << "AForm is already signed but... let's do it again i guess 🙄" << RESET << std::endl;
	}
	else
		isSigned = sign;
}

// SIGN FORM

void	AForm::beSigned(Bureaucrat &br)
{
	if (br.getGrade() <= toSign)
		setIsSigned(true);
	else
		throw GradeTooLowException();
}

// EXECUTE FORM
void	AForm::execute(const Bureaucrat &br) const
{
	(void)br;
}

// EXCEPTIONS

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high 📈");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low 📉");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("Form is not signed");
}
// OPERATOR <<

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << BOLD GREEN << form.getName() << RESET BOLD << " needs grade " << BOLD YELLOW << form.getToSign() << RESET BOLD << " to be signed and grade "
	<< BOLD YELLOW << form.getToExec() << RESET BOLD <<" to be executed.\nSignature on this paper : " << BOLD YELLOW << form.getIsSigned() << " 👀" << RESET << std::endl;
	return os;
}
