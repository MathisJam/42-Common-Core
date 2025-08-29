/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:15:43 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/25 16:11:46 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class Bureaucrat {

	public :

	// CANON FORM
			Bureaucrat();
			Bureaucrat(std::string name, int grade );
			Bureaucrat(const Bureaucrat &cpy);
			~Bureaucrat();
			Bureaucrat &operator=(const Bureaucrat &param);

	// GETTERS
			int getGrade() const;
			std::string getName() const;

	// MEMBER FUNCTIONS
			void incrementGrade();
			void decrementGrade();

	class GradeTooHighException : public std::exception
	{
		public :
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
		const char* what() const throw();
	};

	private :

	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &br);

#endif
