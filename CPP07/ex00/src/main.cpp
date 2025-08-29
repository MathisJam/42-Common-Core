/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:37:21 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/14 11:29:38 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"

int main( void )
{
	std::cout << BOLD YELLOW << "\t\t-------- TESTING WITH INT -------" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << BOLD GREEN << "BEFORE SWAP" << RESET << std::endl;
	std::cout << BOLD << "a = " << a << ", b = " << b << std::endl;
	::swap( a, b );
	std::cout << BOLD GREEN << "AFTER SWAP" << RESET << std::endl;
	std::cout << BOLD << "a = " << a << ", b = " << b << std::endl;
	std::cout << BOLD GREEN << "\nTESTING MIN (EXPECTED 2)" << RESET << std::endl;
	std::cout << BOLD << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << BOLD GREEN << "TESTING MAX (EXPECTED 3)" << RESET << std::endl;
	std::cout << BOLD << "max(a, b) = " << ::max( a, b ) << std::endl;

	std::cout << BOLD YELLOW << "\t\t-------- TESTING WITH STRINGS -------" << std::endl;
	std::string c = "STR1";
	std::string d = "STR2";
	std::cout << BOLD GREEN << "BEFORE SWAP" << RESET << std::endl;
	std::cout << BOLD << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << BOLD GREEN << "AFTER SWAP" << RESET << std::endl;
	std::cout << BOLD << "c = " << c << ", d = " << d << std::endl;
	std::cout << BOLD GREEN << "\nTESTING MIN (EXPECTED STR1)" << RESET << std::endl;
	std::cout << BOLD << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << BOLD GREEN << "TESTING MAX (EXPECTED STR2)" << RESET << std::endl;
	std::cout << BOLD << "max(c, d) = " << ::max( c, d) << std::endl;

	return 0;
}
