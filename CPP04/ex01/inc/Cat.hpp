/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:09:42 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 13:06:04 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat &cpy);
		~Cat();
		Cat &operator=(Cat const &param);
		void makeSound() const;
		Brain* getBrain() const;

	private :
		Brain* brain;
};

#endif
