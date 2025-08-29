/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:15:37 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/25 18:40:29 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
	std::cout << BOLD MAGENTA << "\n		-------------Testing GradeTooHigh-------------" << RESET << std::endl;
	try
	{
		Bureaucrat Pal("Palu", 1);
		Pal.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " << e.what() << '\n';
	}
	std::cout << BOLD MAGENTA << "\n		-------------Testing GradeTooLow-------------" << RESET << std::endl;
	try
	{
		Bureaucrat Pal("Palu", 150);
		while(Pal.getGrade() < 151)
			Pal.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << BOLD RED << "\nException = " <<  e.what() << RESET << std::endl;
	}

	std::cout << BOLD MAGENTA << "\n		-------------Testing << Operator-------------" << RESET << std::endl;
	try
	{
		Bureaucrat Pal("Palu", 150);
		Pal.incrementGrade();
		std::cout << BOLD CYAN << "\nHi my name is " << Pal << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unexpected exception = " << e.what() << std::endl;
	}
}
