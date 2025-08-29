/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:44:39 by mjameau           #+#    #+#             */
/*   Updated: 2025/05/18 16:44:39 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>

#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class BitcoinExchange {

    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cpy);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &param);

        void initExchanger(std::string fileName);
        float getPrice(std::string &date, float amount);
        bool isValidDate(std::string &date);
        bool isValidValue(const std::string &value);

    private :
        std::map<std::string, float> _exchanger;
};

#endif
