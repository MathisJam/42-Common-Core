/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:10:13 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/29 13:01:06 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <stdexcept>
#include <iomanip>
#pragma once

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

class ScalarConverter
{
	public:
		static void convert(std::string const &arg);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &param);

		static int detectType(std::string const &arg);
		static bool isNanInf(std::string const &arg);
		static void convertFromChar(char c);
		static void convertFromInt (int n);
		static void convertFromFloat(float f);
		static void convertFromDouble (double d);
		static int stringToInt(const std::string &arg);
		static float stringToFloat(const std::string &arg);
		static double stringToDouble(const std::string &arg);

};



#endif
