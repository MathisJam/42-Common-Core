/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:37:00 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/21 10:44:37 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main() {

	// TEST SUJET / UNCOMMENT
	// int * a = new int();
	// std::cout << *a << std::endl;

	std::cout << BOLD GREEN << "\tSIZE CONSTRUCTOR" << RESET << std::endl;
	Array<int> a(5);

	std::cout << BOLD << "array a = [";
	for (size_t i = 0; i < a.size(); ++i)
	{
		a[i] = i * 1;
		std::cout << BOLD << a[i];
		if (i < a.size() - 1)
			std::cout << ",";
	}
	std::cout << "]" << RESET << std::endl;


	std::cout << BOLD GREEN << "\n\tCOPY CONSTRUCTOR B = A" << RESET << std::endl;
	Array<int> b = a;
	std::cout << std::endl;

	std::cout << BOLD GREEN << "\tRESULT AFTER COPY" << RESET << std::endl;
	std::cout << BOLD << "array b = [";
	for (size_t i = 0; i < b.size(); ++i)
	{
		std::cout << BOLD << b[i];
		if (i < b.size() - 1)
			std::cout << ",";
	}
	std::cout << "]" << RESET << std::endl;


	std::cout << BOLD GREEN << "\n\tCHANGING B[0] VALUE TO 100 TO SEE IF DEEP COPY" << RESET << std::endl;
	b[0] = 100;
	std::cout << RESET BOLD << "a[0] = " << a[0] << "\nb[0] = " << b[0] << std::endl;
	std::cout << RESET BOLD GREEN << "a[0] value didn't change ✨" << std::endl;

	std::cout << BOLD GREEN << "\n\tTESTING OUT OF BONDS" << RESET << std::endl;
	try
	{
		std::cout << a[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << BOLD RED << "Exception: " << e.what() << std::endl;
	}

	std::cout << BOLD GREEN << "\n\tTESING STRINGS ARRAY" << RESET << std::endl;
	Array<std::string> Sa(5);
	Sa[0] = "It's";
	Sa[1] = "me";
	Sa[2] = "again";
	Sa[3] = "🤡";
	Sa[4] = "🔪";
	std::cout << BOLD << "array Sa = [";
	for (size_t i = 0; i < Sa.size(); ++i)
	{
		std::cout << BOLD RED << Sa[i];
		if (i < Sa.size() - 1)
			std::cout << RESET BOLD << "," << BOLD RED;
	}
	std::cout << RESET << "]"  <<  std::endl;
	std::cout << BOLD GREEN << "\n\tCOPY CONSTRUCTOR Sb = Sa" << RESET << std::endl;
	Array<std::string> Sb = Sa;
	std::cout << std::endl;

	std::cout << BOLD GREEN << "\tRESULT AFTER COPY" << RESET << std::endl;
	std::cout << BOLD << "array Sb = [";
	for (size_t i = 0; i < Sb.size(); ++i)
	{
		std::cout << BOLD RED  << Sb[i];
		if (i < Sb.size() - 1)
			std::cout << RESET BOLD << "," << BOLD RED;
	}
	std::cout << RESET << "]"  << std::endl;

	std::cout << BOLD GREEN << "\n\tDESTRUCTORS A B / Sa Sb" << RESET << std::endl;
}
