/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:00 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/14 17:15:41 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main()
{
	std::cout << BOLD GREEN << "\tTESTING WITH VECTOR" << RESET << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << BOLD CYAN ITALIC << "Searching 20... 🔍 " << std::endl;
		std::cout << RESET BOLD << "Found in vector : " << *it << " ✨" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception : " << e.what() << std::endl;
	}

	std::cout << BOLD GREEN << "\n\tTESTING WITH LIST" << RESET << std::endl;
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 3);
		std::cout << BOLD CYAN ITALIC << "Searching 3... 🔍" << std::endl;
		std::cout << RESET BOLD << "Found in list : " << *it << " ✨" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << "Exception : " << e.what() << std::endl;
	}


	std::cout << BOLD GREEN << "\n\tTESTING WITH DEQUE" << RESET << std::endl;
	std::deque<int> deq;
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(42);

	try
	{
		std::deque<int>::iterator it = easyfind(deq, 42);
		std::cout << BOLD CYAN ITALIC << "Searching 42... 🔍" << std::endl;
		std::cout << RESET BOLD << "Found in list : " << *it << " ✨" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD << "Exception : " << e.what() << std::endl;
	}

	std::cout << BOLD GREEN << "\n\tTESTING EXCEPTION" << RESET << std::endl;
	try
	{
		easyfind(vec, 99);
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD RED << "Exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}
