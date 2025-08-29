/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:18:00 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 17:31:57 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AForm_HPP
#define AForm_HPP

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

class AForm
{
	public :
	// CANONAForm
	AForm();
	AForm(std::string name, int toSign, int toExec);
	AForm(const AForm &cpy);
	virtual ~AForm();
	AForm &operator=(const AForm &param);

	// GETTERS
		virtual int getToExec() const;
		int getToSign() const;
		bool getIsSigned() const;
		std::string getName() const;

	// SETTERS
		void setIsSigned(bool);

	// MEMBER FUNCTIONS
		void beSigned(Bureaucrat &br);
		virtual void execute(Bureaucrat const &br) const = 0;

	// EXCEPTIONS
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	class FormNotSigned : public std::exception
	{
		public :
			virtual const char* what() const throw();
	};

	private :
		const	std::string name;
		bool	isSigned;
		const int	toSign;
		const int	toExec;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
