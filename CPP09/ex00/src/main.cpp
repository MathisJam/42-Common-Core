/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:44:31 by mjameau           #+#    #+#             */
/*   Updated: 2025/05/18 16:44:31 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << BOLD RED << "Usage: " << argv[0] << " <input_file>" << RESET << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btcExchange;
		btcExchange.initExchanger("data.csv");
		std::ifstream inputFile(argv[1]);

		if (!inputFile.is_open())
		{
			std::cerr << BOLD RED << "Error: could not open file: " << argv[1] << RESET << std::endl;
			return 1;
		}

		std::string line;
		while (std::getline(inputFile, line))
		{
			std::istringstream ss(line);
			std::string date, valueStr;

			if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
			{
				date.erase(0, date.find_first_not_of(" \t"));
				date.erase(date.find_last_not_of(" \t") + 1);
				valueStr.erase(0, valueStr.find_first_not_of(" \t"));
				valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

				if (!btcExchange.isValidDate(date))
				{
					std::cerr << BOLD RED << "Error: invalid date format => " << date << RESET << std::endl;
					continue;
				}

				if (!btcExchange.isValidValue(valueStr))
				{
					std::cerr << BOLD RED << "Error: invalid value => " << valueStr << RESET << std::endl;
					continue;
				}

				float amount = std::atof(valueStr.c_str());

				try
				{
					double price = btcExchange.getPrice(date, amount);
					std::cout << BOLD << date << " => " << amount << " BTC = " << price << "💲​" << RESET << std::endl;
				}
				catch (const std::exception &e)
				{
					std::cerr << BOLD RED << "Error: " << e.what() << RESET << std::endl;
				}
			}
			else
			{
				std::cerr << BOLD RED << "Error: invalid line format => " << line << RESET << std::endl;
			}
		}

		inputFile.close();
	}
	catch (const std::exception &e)
	{
		std::cerr << BOLD RED << "Error: " << e.what() << RESET << std::endl;
		return 1;
	}

	return 0;
}
