/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:44:26 by mjameau           #+#    #+#             */
/*   Updated: 2025/05/18 16:44:26 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << BOLD << "Default constructor called" << RESET << std::endl;
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	std::cout << BOLD << "Copy constructor called" << RESET << std::endl;
    *this = cpy;
};

BitcoinExchange::~BitcoinExchange()
{
	std::cout << BOLD << "Destructor called" << RESET << std::endl;
};
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &param)
{
    if (this != &param)
        this->_exchanger = param._exchanger;
    return *this;
};

void BitcoinExchange::initExchanger(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << BOLD RED << "Error: could not open file :" << fileName << RESET << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\r") + 1);

        std::istringstream ss(line);
        std::string date, priceStr;

        if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
        {
            float price = std::atof(priceStr.c_str());
            _exchanger[date] = price;
        }
    }
    file.close();
};

float BitcoinExchange::getPrice(std::string &date, float amount)
{
    if (_exchanger.empty())
    {
        throw( std::logic_error(BOLD RED "exchanger data is empty." RESET));
    }

    std::map<std::string, float>::const_iterator it = _exchanger.lower_bound(date);

    if (it == _exchanger.end())
    {
        it--;
    }
    else if (it->first != date)
    {
        if (it == _exchanger.begin())
        {
            throw(std::runtime_error(BOLD RED "date not found and no earlier date available" RESET));
        }
        --it;
    }

    return it->second * amount;
}





bool isDigits(const std::string &s)
{
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}


bool BitcoinExchange::isValidDate(std::string &date)
{
    std::istringstream ss(date);

    std::string token;

    if (!std::getline(ss, token, '-') || token.length() != 4 || !isDigits(token))
        return false;
    if (!std::getline(ss, token, '-') || token.length() != 2 || std::atoi(token.c_str()) > 12|| !isDigits(token))
        return false;
    if (!std::getline(ss, token) || token.length() != 2 || std::atoi(token.c_str()) > 31 || !isDigits(token))
        return false;
    return ss.eof();
};

bool BitcoinExchange::isValidValue(const std::string& value)
{
    float val = std::atof(value.c_str());

    if (val >=0 && val <= 1000)
         return true;
    else
        return false;
};

