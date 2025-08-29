/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:45:06 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 15:28:40 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

// CANON FORM
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << BOLD << "RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << BOLD << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BOLD << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &param)
{
	if (this == &param)
		return (*this);
	this->target = param.target;
	return (*this);

}

// CONSTRUCTOR TARGET
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << BOLD << "RobotomyRequestForm constructor with target name called" << RESET << std::endl;
}

// MEMBER FUNCTION

static int count = 0;

void	RobotomyRequestForm::execute(const Bureaucrat &br) const
{
	bool IsIt = this->getIsSigned();

	if (IsIt == true)
	{
		if (br.getGrade() <= this->getToExec())
			{
				if (count++ % 2)
					std::cout << BOLD YELLOW << "	🧑‍🔧🤖 BRRRRRRRRRRRRR... " << BOLD GREEN << getTarget() << BOLD YELLOW
					<< " has been robotimized successfully" << RESET << std::endl;
				else
					std::cout << BOLD RED << "	😱 Ohhh no!! Robotomy failed" << RESET << std::endl;
			}
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSigned();
}

// GETTER
std::string	RobotomyRequestForm::getTarget() const
{
	return (target);
}

//OPERATOR <<
std::ostream &operator<<(std::ostream &os, RobotomyRequestForm &form)
{
	os << BOLD GREEN << form.getName() << RESET BOLD << " needs grade " << BOLD YELLOW << form.getToSign() << RESET BOLD << " to be signed and grade "
	<< BOLD YELLOW << form.getToExec() << RESET BOLD <<" to be executed.\nSignature on this paper : " << BOLD YELLOW << form.getIsSigned() << " 👀" << RESET << std::endl;
	return os;
}

