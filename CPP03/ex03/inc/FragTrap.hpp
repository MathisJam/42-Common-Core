/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:25:23 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/19 13:03:47 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(FragTrap const &cpy);
		~FragTrap();
		FragTrap &operator=(const FragTrap &cpy);
		void attack(const std::string &target);
		void HighFives();

	private:
};

#endif
