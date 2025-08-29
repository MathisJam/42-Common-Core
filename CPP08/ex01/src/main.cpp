/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:30:19 by mjameau           #+#    #+#             */
/*   Updated: 2025/04/25 11:16:08 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

int main()
{
	Span sp = Span(10);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << BOLD GREEN << "\n\t TESTING SUBJECT MAIN" << RESET << std::endl;
	std::cout << BOLD ITALIC << "Vector numbers {3, 6, 9, 11, 17}\n";
	std::cout << BOLD ITALIC << "Expected result : Short = 2 (diff 6,9), Long = 14 (diff 3, 17)\n";
	std::cout << BOLD CYAN << "\nShortest result = " <<  sp.shortestSpan() << std::endl;
	std::cout << "Longest result = " <<  sp.longestSpan() << RESET << std::endl;

	std::cout << BOLD GREEN << "\n\t TESTING AFTER ADDING MORE NUMBERS" << RESET<< std::endl;

	int arr[] = {7, 14, 27, 34, 72};
	sp.addMore(arr, arr + sizeof(arr) / sizeof(int));
	std::cout << BOLD ITALIC << "Vector numbers {3, 6, 7, 9, 11, 14, 17, 27, 34, 72}\n";
	std::cout << BOLD ITALIC << "Expected result : Short = 1 (diff 6,7), Long = 69 (diff 3, 72)\n";
	std::cout << BOLD CYAN << "\nShortest result = " <<  sp.shortestSpan() << std::endl;
	std::cout << "Longest result = " <<  sp.longestSpan() << RESET << std::endl;


	std::cout << BOLD GREEN << "\n\t TESTING EXCEPTIONS" << RESET << std::endl;

	try
	{
		sp.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD ITALIC << "addNumber : \n";
		std::cerr << RESET BOLD RED << e.what() << RESET << std::endl;;
	}


	int Narr[] = {7, 14, 27, 34, 72};
	try
	{
		sp.addMore(Narr, Narr + sizeof(Narr) / sizeof(int));
	}
	catch(const std::exception& e)
	{
		std::cout << BOLD ITALIC << "\naddMore : \n";
		std::cerr << RESET BOLD RED << e.what() << RESET << std::endl << std::endl;
	}

}
