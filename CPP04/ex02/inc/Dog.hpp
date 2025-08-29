/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:17:44 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 13:05:58 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "../inc/Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog();
		Dog(const Dog &cpy);
		~Dog();
		Dog &operator=(const Dog &param);
		void makeSound() const;
		Brain* getBrain() const;

	private :
		Brain* brain;

};

#endif
