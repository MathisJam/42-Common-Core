/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:06:19 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 16:06:20 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"


class Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice &src);
		~Ice();
		Ice&		operator=(const Ice &src);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
