/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:09 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/27 10:40:57 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

int main()
{
	std::cout << BOLD GREEN << "\n​\t\t📚 ------------------ TESTING WITH MUTANTSTACK CLASS ------------------ 📚​\n" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << RESET BOLD ITALIC << "Checking last added element (expected 17)" << RESET BOLD GREEN "\nresult = " << mstack.top() << " ✨" << std::endl << std::endl;
	std::cout << BOLD ITALIC CYAN << "Erasing last added element...\n" << std::endl;
	mstack.pop();
	std::cout << RESET BOLD ITALIC << "Checking MutantStack size (expected 1)" << RESET BOLD GREEN "\nresult = " << mstack.size() << " ✨" << std::endl << std::endl;

	std::cout << BOLD ITALIC CYAN << "Pushing {3,5,737,0} in MutantStack...\n" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	int i = 1;
	while (it != ite)
	{
		std::cout << RESET BOLD ITALIC << "Element n* " << i << " = " << RESET BOLD GREEN << *it << std::endl;
		++it;
		i++;
	}
	std::stack<int> s(mstack);

	std::cout << BOLD GREEN << "\n\t\t📋 ------------------ TESTING WITH STD::LIST TO SEE IF SAME RESULT ------------------ 📋 \n" << std::endl;

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << RESET BOLD ITALIC << "Checking last added element in list (expected 17)" << RESET BOLD GREEN "\nresult = " << mlist.back() << " ✨" << std::endl << std::endl;

	std::cout << BOLD ITALIC CYAN << "Erasing last added element in list...\n" << std::endl;
	mlist.pop_back();

	std::cout << RESET BOLD ITALIC << "Checking list size (expected 1)" << RESET BOLD GREEN "\nresult = " << mlist.size() << " ✨" << std::endl << std::endl;

	std::cout << BOLD ITALIC CYAN << "Pushing {3,5,737,0} in list...\n" << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::list<int>::iterator itt = mlist.begin();
	std::list<int>::iterator itte = mlist.end();
	++itt;
	--itt;
	i = 1;
	while (itt != itte)
	{
		std::cout << RESET BOLD ITALIC << "Element n* " << i << " = " << RESET BOLD GREEN << *itt << std::endl;
		++itt;
		i++;
	}
	std::list<int> Ass(mlist);
	return 0;
}
