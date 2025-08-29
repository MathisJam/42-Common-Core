/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:15:37 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 17:28:51 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

int main()
{
	// AForm form("grocery list", 9, 5); // UNCOMMENT TO SEE THAT AFORM IS ASBTRACT (CAN'T COMPILE)

	std::cout << BOLD MAGENTA << "\n		-------------Testing Intern make ShrubberyCreationForm-------------" << RESET << std::endl;
	try
	{
		Intern Loser;
		Bureaucrat James("👨 James", 6);
		Bureaucrat D("🧓 Dominique", 150);

		AForm *form = Loser.makeForm("ShrubberyCreationForm", "Boss");
		if (!form)
			return 1;
		std::cout << std::endl;
		std::cout << *form << std::endl;

		std::cout << BOLD WHITE << "James grade : " <<  BOLD GREEN << James.getGrade() << RESET << std::endl;
		James.signForm(*form);
		James.executeForm(*form);
		std::cout << std::endl;

		std::cout << BOLD WHITE << "Dominique grade : " <<  BOLD GREEN << D.getGrade() << RESET << std::endl;
		D.signForm(*form);
		D.executeForm(*form);
		std::cout << std::endl;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " << e.what() << '\n';
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing Intern make RobotomyRequestForm -------------" << RESET << std::endl;
	try
	{
		Intern Loser;
		Bureaucrat James("👨 James", 6);
		Bureaucrat D("🧓 Dominique", 150);

		AForm *form = Loser.makeForm("RobotomyRequestForm", "Boss");
		if (!form)
			return 1;
		std::cout << std::endl;
		std::cout << *form << std::endl;

		std::cout << BOLD WHITE << "James grade : " <<  BOLD GREEN << James.getGrade() << RESET << std::endl;
		James.signForm(*form);
		James.executeForm(*form);
		James.executeForm(*form);
		James.executeForm(*form);
		James.executeForm(*form);
		std::cout << std::endl;

		std::cout << BOLD WHITE << "Dominique grade : " <<  BOLD GREEN << D.getGrade() << RESET << std::endl;
		D.signForm(*form);
		D.executeForm(*form);
		std::cout << std::endl;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " <<  e.what() << RESET << std::endl;
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing Intern make PresidentialPardonForm-------------" << RESET << std::endl;
	try
	{
		Intern Loser;
		Bureaucrat James("👨 James", 6);
		Bureaucrat D("🧓 Dominique", 150);

		AForm *form = Loser.makeForm("PresidentialPardonForm", "Boss");
		if (!form)
			return 1;
		std::cout << std::endl;
		std::cout << *form << std::endl;

		std::cout << BOLD WHITE << "James grade : " <<  BOLD GREEN << James.getGrade() << RESET << std::endl;
		James.executeForm(*form);
		James.signForm(*form);
		James.incrementGrade();
		James.executeForm(*form);
		std::cout << std::endl;

		std::cout << BOLD WHITE << "Dominique grade : " <<  BOLD GREEN << D.getGrade() << RESET << std::endl;
		D.signForm(*form);
		D.executeForm(*form);
		std::cout << std::endl;
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " << e.what() << '\n';
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing Intern make Unknown Form-------------" << RESET << std::endl;
	try
	{
		Intern Loser;
		AForm *form = Loser.makeForm("Prout", "Boss");
		if (!form)
			return 1;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " << e.what() << '\n';
	}
}
