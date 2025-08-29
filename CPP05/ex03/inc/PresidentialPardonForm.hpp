/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:10:43 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 14:45:34 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public :

	// CANON FORM
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &param);
	// MEMBER FUNCTIONS
		void execute(Bureaucrat const &br) const;
	//GETTERS
		std::string getTarget() const;

	private :
		std::string target;
};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm &form);

#endif
