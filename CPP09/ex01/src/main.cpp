/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:37:52 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/02 11:32:30 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Plan :
		1- Check arguments != 2
		2- Prendre argv[1] et envoyer dans fonction parsing (que digits et operands) + mini 2 digits au debut (X X operand) et pas de => 10
		3- Si parsing bon decouper en token apres chaque space/whitespaces et push dans la stack<char, list<char> >
		4- Ensuite prendre les 2 index precedent operateur et faire calcul (coder fonction pour chaque operand?)
*/

#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << BOLD RED << "Wrong argument(s), try with a RPN notation in double quotes N : \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << RESET << std::endl;

	try
	{
		RPN monkey;
		monkey.ParseRPN(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


