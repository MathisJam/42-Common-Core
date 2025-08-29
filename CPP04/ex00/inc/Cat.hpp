/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:09:42 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 11:13:33 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "../inc/Animal.hpp"

class Cat : public Animal
{
	public :
		Cat();
		Cat(const Cat &cpy);
		~Cat();
		Cat &operator=(Cat const &param);
		void makeSound() const;
};

#endif
