/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:32:01 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 15:28:36 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"


// CANON FORM
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << BOLD << "PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << BOLD << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BOLD << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &param)
{
	if (this == &param)
		return (*this);
	this->target = param.target;
	return (*this);
}

// CONSTRUCTOR TARGET
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << BOLD << "PresidentialPardonForm constructor with target name called" << RESET << std::endl;
}

// MEMBER FUNCTION
void	PresidentialPardonForm::execute(const Bureaucrat &br) const
{
	bool IsIt = this->getIsSigned();

	if (IsIt == true)
	{
		if (br.getGrade() <= this->getToExec())
			std::cout << BOLD GREEN << this->getTarget() << RESET BOLD << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSigned();
}

// GETTERS

std::string	PresidentialPardonForm::getTarget() const
{
	return (target);
}

//OPERATOR <<
std::ostream &operator<<(std::ostream &os, PresidentialPardonForm &form)
{
	os << BOLD GREEN << form.getName() << RESET BOLD << " needs grade " << BOLD YELLOW << form.getToSign() << RESET BOLD << " to be signed and grade "
	<< BOLD YELLOW << form.getToExec() << RESET BOLD <<" to be executed.\nSignature on this paper : " << BOLD YELLOW << form.getIsSigned() << " 👀" << RESET << std::endl;
	return os;
}
