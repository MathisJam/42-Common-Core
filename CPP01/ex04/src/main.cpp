/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:15:31 by mjameau           #+#    #+#             */
/*   Updated: 2025/02/19 16:55:44 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#define BOLD "\033[1m"
#define RED "\033[31m"
#define RESET "\033[0m"

/*
Obs : Toujours mettre != std::string::npos en utilisant find()
On trouve d'abord la position de s1 dans la ligne avec find().
Si on n'utilise pas .replace, alors on supprime deja la ligne avec .erase et on ajoute
la nouvelle ligne avec .insert
On incremente ensuite la pos de +s2.length() pour ne pas boucler a l'infini
On met evidemment chaque ligne dans le fichier de sortie
On oublie pas de fermer les fichiers
*/
int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << BOLD RED << "Usage: ./Sid_is_for_losers [filename] [s1] [s2]" << RESET << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cout << BOLD RED << "Error: Could not open file." << RESET << std::endl;
		return (1);
	}
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cout << BOLD RED << "Error: Could not create file." << RESET << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (0);
}
