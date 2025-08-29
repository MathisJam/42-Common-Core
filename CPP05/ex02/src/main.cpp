/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:15:37 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 17:26:49 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

int main()
{
	// AForm form("grocery list", 9, 5); // UNCOMMENT TO SEE THAT AFORM IS ASBTRACT (CAN'T COMPILE)

	std::cout << BOLD MAGENTA << "\n		-------------Testing ShrubberyCreationForm-------------" << RESET << std::endl;
	try
	{
		Bureaucrat James("👨 James", 6);
		Bureaucrat D("🧓 Dominique", 150);
		ShrubberyCreationForm form("Sonic 🦔");
		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << BOLD WHITE << "James grade : " <<  BOLD GREEN << James.getGrade() << RESET << std::endl;
		James.signForm(form);
		James.executeForm(form);
		std::cout << std::endl;

		std::cout << BOLD WHITE << "Dominique grade : " <<  BOLD GREEN << D.getGrade() << RESET << std::endl;
		D.signForm(form);
		D.executeForm(form);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " << e.what() << '\n';
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing RobotomyRequestForm -------------" << RESET << std::endl;
	try
	{
		Bureaucrat James("👨 James", 6);
		Bureaucrat D("🧓 Dominique", 150);
		RobotomyRequestForm form("Sonic 🦔");
		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << BOLD WHITE << "James grade : " <<  BOLD GREEN << James.getGrade() << RESET << std::endl;
		James.signForm(form);
		for (int i = 0; i < 4; i++)
			James.executeForm(form);
		std::cout << std::endl;

		std::cout << BOLD WHITE << "Dominique grade : " <<  BOLD GREEN << D.getGrade() << RESET << std::endl;
		D.signForm(form);
		D.executeForm(form);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " <<  e.what() << RESET << std::endl;
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing PresidentialPardonForm-------------" << RESET << std::endl;
	try
	{
		Bureaucrat James("👨 James", 6);
		Bureaucrat D("🧓 Dominique", 150);
		PresidentialPardonForm form("Sonic 🦔");
		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << BOLD WHITE << "James grade : " <<  BOLD GREEN << James.getGrade() << RESET << std::endl;
		James.executeForm(form);
		James.signForm(form);
		James.incrementGrade();
		James.executeForm(form);
		std::cout << std::endl;

		std::cout << BOLD WHITE << "Dominique grade : " <<  BOLD GREEN << D.getGrade() << RESET << std::endl;
		D.signForm(form);
		D.executeForm(form);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " << e.what() << '\n';
	}
}
