/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:10:46 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 14:45:56 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &param);
		void execute(Bureaucrat const &br) const;
		std::string getTarget() const;

	private :
		std::string target;
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm &form);

#endif
