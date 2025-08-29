/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:52:51 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 13:05:22 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &cpy);
	DiamondTrap(std::string _name);
	~DiamondTrap();
	DiamondTrap &operator=(DiamondTrap const &param);
	void whoAmI();
	using ScavTrap::attack;

	private:
	std::string _name;
};


#endif
