/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:37:06 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/02 11:18:27 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main(void)
{
	std::cout << BOLD YELLOW << "\t--- TESTING WITH STRINGS ARRAY ---" << RESET << "\n";
	std::string arr[] = {"Hi i'm Bozo", "Come play with me", "🤡 🔪"};
	::iter(arr, printIndex);
	std::cout << "\n\n";

	std::cout << BOLD YELLOW << "\t--- TESTING WITH CONST STRINGS ARRAY ---" << RESET << "\n";
	const std::string CS_arr[] = {"You go hiding", "I'll count", "🤡 🔪"};
	::iter(CS_arr, printIndex);
	std::cout << "\n\n";

	std::cout << BOLD YELLOW << "\t--- TESTING WITH INT ARRAY ---" << RESET << "\n";
	int int_arr[] = {1, 2, 3, 4, 5};
	::iter(int_arr, printIndex);
	std::cout << "\n\n";

	std::cout << BOLD YELLOW << "\t--- TESTING WITH FLOAT ARRAY ---" << RESET << "\n";
	float f_arr[] = {5.50f, 6.01f, 6.50f};
	::iter(f_arr, printIndex);
	std::cout << "\n\n";

	std::cout << BOLD YELLOW << "\t--- TESTING WITH CHAR ARRAY ---" << RESET << "\n";
	char c_arr[] = {'C', 'O', 'M', 'I', 'N', 'G'};
	::iter(c_arr, printIndex);
	std::cout << std::endl;
}
