/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:18:00 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 17:14:48 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#pragma once
#include "Bureaucrat.hpp"

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

class Bureaucrat;

class Form
{
	public :
	// CANON FORM
		Form();
		Form(std::string name, int toSign, int toExec);
		Form(const Form &cpy);
		~Form();
		Form &operator=(const Form &param);
	// GETTERS
		int getToExec() const;
		int getToSign() const;
		bool getIsSigned() const;
		std::string getName() const;
	// SETTERS
		void setIsSigned(bool);
	// MEMBER FUNCTIONS
		void beSigned(Bureaucrat &br);
	// EXCEPTIONS
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
		const	std::string name;
		bool	isSigned;
		const int	toSign;
		const int	toExec;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
