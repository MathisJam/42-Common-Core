/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:06:10 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 16:06:17 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"


class Cure : public AMateria
{
	public :
	Cure();
	Cure(const Cure &src);
	~Cure();
	Cure&		operator=(const Cure &src);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif
