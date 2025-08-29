/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:15:37 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 17:22:05 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	std::cout << BOLD MAGENTA << "\n		-------------Testing Form can't be signed-------------" << RESET << std::endl;
	try
	{
		Form form("grocery list", 5, 5);
		Bureaucrat James("👨 James", 9);
		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << BOLD WHITE << "James grade : " <<  BOLD GREEN << James.getGrade() << RESET << std::endl;
		James.signForm(form);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " << e.what() << '\n';
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing Form can be signed -------------" << RESET << std::endl;
	try
	{
		Form form("martial law approval", 150, 150);
		Bureaucrat D("🧓 Dominique", 149);
		std::cout << std::endl;
		std::cout << form << std::endl;
		std::cout << BOLD WHITE << "Dominique grade : " <<  BOLD GREEN << D.getGrade() << RESET << std::endl;
		D.signForm(form);
		std::cout << "\n" << form << std::endl; // UNCOMMENT TO SEE IF PAPER IS SIGNED (BOOL SET TO TRUE)

		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " <<  e.what() << RESET << std::endl;
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing << Operator-------------" << RESET << std::endl;
	try
	{
		Form form("Confidential but useless form", 1, 1);
		std::cout << "\n" << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unexpected exception = " << e.what() << std::endl;
	}
}
