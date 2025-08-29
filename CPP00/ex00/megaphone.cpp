/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:45:05 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/19 12:33:01 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argv[i]; ++i)
	{
		for(int j = 0; argv[i][j]; j++)
			argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i];
		if (argv[i] != NULL)
			std::cout << " ";
	}
	std::cout << std::endl;
}
