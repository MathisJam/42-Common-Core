/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:05:38 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 16:05:53 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter
{
	public :
		Character();
		Character(const std::string inputName);
		Character(const Character &src);
		~Character();
		Character&			operator=(const Character &src);

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	protected :
		AMateria		*_inventory[4];
		std::string		_name;
};

#endif
