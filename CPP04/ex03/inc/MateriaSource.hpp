/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:06:43 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/23 16:06:44 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	protected:
		AMateria*			_slots[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		~MateriaSource();
		MateriaSource&		operator=(const MateriaSource &src);

		void				learnMateria(AMateria *materia);
		AMateria*			createMateria(std::string const &type);
};

#endif
