/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:20:18 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 11:50:05 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

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

class	WrongAnimal
{
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal &cpy);
		 ~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal const &param);
		void makeSound() const;
		std::string getType() const;

	protected :
		std::string type;
};

#endif
