/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:08:40 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 13:33:30 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	public :
		Brain();
		Brain(const Brain &cpy);
		Brain &operator=(const Brain &param);
		~Brain();
		std::string getIdea(int i);
		void setIdea(int i, std::string idea);
		std::string* getIdeasAdress();

	private :
		std::string ideas[100];
};

#endif
