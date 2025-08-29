/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:44:58 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 15:34:27 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

// CANON FORM
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << BOLD << "ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << BOLD << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << BOLD << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &param)
{
	if (this == &param)
		return (*this);
	this->target = param.target;
	return (*this);
}

// CONSTRUCTOR TARGET
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << BOLD << "ShrubberyCreationForm constructor with target name called" << RESET << std::endl;
}

// MEMBER FUNCTION
void	ShrubberyCreationForm::execute(const Bureaucrat &br) const
{
	bool IsIt = this->getIsSigned();

	if (IsIt == true)
	{
		if (br.getGrade() <= this->getToExec())
			{
				std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());
				for (int i =0; i < 2; i++)
				{
					outfile << BOLD RED <<"                                                         ." << std::endl;
					outfile << BOLD YELLOW << "                                              .         ;" << std::endl;
					outfile << BOLD GREEN <<"                 .              .              ;%     ;;" << std::endl;
					outfile << BOLD CYAN <<"                   ,           ,                :;%  %;" << std::endl;
					outfile << BOLD BLUE <<"                    :         ;                   :;%;'     .," << std::endl;
					outfile << BOLD MAGENTA <<"           ,.        %;     %;            ;        %;'    ,;" << std::endl;
					outfile << BOLD RED <<"             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
					outfile << BOLD YELLOW <<"              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
					outfile << BOLD GREEN <<"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
					outfile << BOLD CYAN <<"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
					outfile << BOLD BLUE <<"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
					outfile << BOLD MAGENTA <<"                    `:%;.  :;bd%;          %;@%;'" << std::endl;
					outfile << BOLD RED <<"                      `@%:.  :;%.         ;@@%;'" << std::endl;
					outfile << BOLD YELLOW <<"                        `@%.  `;@%.      ;@@%;" << std::endl;
					outfile << BOLD GREEN <<"                          `@%%. `@%%    ;@@%;" << std::endl;
					outfile << BOLD CYAN <<"                            ;@%. :@%%  %@@%;" << std::endl;
					outfile << BOLD BLUE <<"                              %@bd%%%bd%%:;" << std::endl;
					outfile << BOLD MAGENTA <<"                               #@%%%%%:;;" << std::endl;
					outfile << BOLD RED <<"                                %@@%%%::;" << std::endl;
					outfile << BOLD YELLOW <<"                                %@@@%(o);  . '         " << std::endl;
					outfile << BOLD GREEN <<"                                %@@@o%;:(.,'         " << std::endl;
					outfile << BOLD CYAN <<"                            `.. %@@@o%::;         " << std::endl;
					outfile << BOLD BLUE <<"                               `)@@@o%::;         " << std::endl;
					outfile << BOLD MAGENTA <<"                                %@@(o)::;        " << std::endl;
					outfile << BOLD RED <<"                               .%@@@@%::;         " << std::endl;
					outfile << BOLD YELLOW <<"                               ;%@@@@%::;.          " << std::endl;
					outfile << BOLD GREEN <<"                              ;%@@@@%%:;;;. " << std::endl;
					outfile << BOLD CYAN <<"                          ...;%@@@@@%%:;;;;,..    " << std::endl;
				}
			}
		else
			throw GradeTooLowException();
	}
	else
		throw FormNotSigned();
}

// GETTER
std::string	ShrubberyCreationForm::getTarget() const
{
	return (target);
}

//OPERATOR <<
std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &form)
{
	os << BOLD GREEN << form.getName() << RESET BOLD << " needs grade " << BOLD YELLOW << form.getToSign() << RESET BOLD << " to be signed and grade "
	<< BOLD YELLOW << form.getToExec() << RESET BOLD <<" to be executed.\nSignature on this paper : " << BOLD YELLOW << form.getIsSigned() << " 👀" << RESET << std::endl;
	return os;
}
