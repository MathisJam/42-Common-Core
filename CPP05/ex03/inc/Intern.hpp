/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:47:36 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/26 16:05:44 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"



class Intern
{
	public :
		Intern();
		Intern(const Intern &cpy);
		~Intern();
		Intern &operator=(const Intern &param);

		AForm *makeForm(std::string name, std::string target);

};

#endif
