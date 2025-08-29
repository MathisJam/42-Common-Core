/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:02:37 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/02 11:15:00 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* PLAN --
		1 - Check argv >= 2, gerer le parsing
		2 - Faire recursive pour diviser en paires et mettre la + grande paire a droite
		3 - Quand plus de paires possibles, faire pend et main.
		4 - Ne pas inclure elems sans paires -> mettre b1 et tt les aS dans main, mettre tt les autres bS dans pend.
		5 - Utiliser suite jacobsthal pour inclure pend dans main.
		6 - Recursive ca jusqu'a ce que ce soit trie.
*/

#include "../inc/PmergeMe.hpp"

bool duplicate(const std::vector<unsigned int> &vct)
{
	std::set<unsigned int> s(vct.begin(), vct.end());
	return (s.size() != vct.size());
}
template<typename T>
void printContainer(const std::string &status, const T &container)
{
	std::cout << BOLD MAGENTA << status;

	for (size_t i = 0; i < container.size(); ++i)
		std::cout << " " << container[i];

	std::cout << RESET << std::endl;
}


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << BOLD RED << "Not enough arguments" << RESET << std::endl;
		return 1;
	}

	PmergeMe pm;
	pm.ParseInput(argv + 1);

	if (duplicate(pm.getVector()))
	{
		std::cerr << BOLD RED << "Error: duplicates not allowed" << RESET << std::endl;
		return 1;
	}

	printContainer("Before:", pm.getVector());

	double startV = getTime();
	pm.FordVector();
	double endV = getTime();

	double startD = getTime();
	pm.FordDeque();
	double endD = getTime();

	printContainer("After:", pm.getVector());

	std::deque<unsigned int> dq = pm.getDeque();
	std::cout << BOLD CYAN << std::fixed << std::setprecision(5) <<
	 "Time to process a range of " << dq.size() <<" elements with std::deque : " << (endD - startD) << " us" << RESET << std::endl;

	 std::vector<unsigned int> vct = pm.getVector();
	 std::cout << BOLD CYAN << std::fixed << std::setprecision(5) <<
	 "Time to process a range of " << vct.size() <<" elements with std::vector : " << (endV - startV) << " us" << RESET << std::endl;

	return 0;
}

