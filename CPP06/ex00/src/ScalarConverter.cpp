/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 11:10:10 by mjameau           #+#    #+#             */
/*   Updated: 2025/03/29 18:39:06 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &arg)
{
	if (isNanInf(arg))
	{
		std::cout << BOLD << "char: impossible\n";
        std::cout << "int: impossible\n";
		if (arg == "nan" || arg == "nanf")
		{
			std::cout << "float: nanf\n";
            std::cout << "double: nan\n";
        }
		else if (arg == "inf" || arg == "+inf" || arg == "-inf")
		{
			std::cout << "float: " << arg << "f\n";
			std::cout << "double: " << arg << "\n";
		}
		else
		{
			std::cout << "float: " << arg << "\n";
			std::cout << "double: " << arg.substr(0, arg.length() - 1) << "\n";
		}

		return;
	}
	int res = detectType(arg);
	try
	{
		switch (res)
		{
			case 0:
				convertFromChar(arg[0]);
				break;
			case 1:
				convertFromInt(stringToInt(arg));
				break;
			case 2:
				convertFromFloat(stringToFloat(arg));
				break;
			case 3:
				convertFromDouble(stringToDouble(arg));
				break;
			default:
				std::cout << BOLD << "Invalid type" << std::endl;
		}
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Invalid argument:" << e.what() << std::endl;
	}
	catch (const std::overflow_error &e)
	{
		std::cerr << "Overflow error." << e.what() << std::endl;
	}
}

int ScalarConverter::detectType(std::string const &arg)
{
	if (arg.length() == 1 && !isdigit(arg[0]))
		return (0);
	else if (arg.find('.') == std::string::npos && arg.find('f') == std::string::npos)
		return (1);
	else if (arg.find('f') != std::string::npos)
		return (2);
	else
		return (3);
}

bool ScalarConverter::isNanInf(std::string const &arg)
{
	return (arg == "nan" || arg == "nanf" ||
		arg == "inf" || arg == "+inf" || arg == "-inf" ||
		arg == "inff" || arg == "+inff" || arg == "-inff");
}

int ScalarConverter::stringToInt(const std::string &arg)
{
	std::stringstream ss(arg);
    long long result;
    ss >> result;
    if (ss.fail())
		throw std::invalid_argument(BOLD RED" Invalid argument occured, no values can be displayed.");
    if (result > INT_MAX)
		throw std::overflow_error(BOLD RED" Overflow error occured, no values can be displayed.");
    if (result < INT_MIN)
		throw std::overflow_error(BOLD RED " Underflow error occured, no values can be displayed.");
    return static_cast<int>(result);
}

float ScalarConverter::stringToFloat(const std::string &arg)
{
    std::stringstream ss(arg);
    float result;
    ss >> result;
	if (ss.fail())
	throw std::invalid_argument(BOLD RED" Invalid argument occured, no values can be displayed.");
	if (result > __FLT_MAX__)
		throw std::overflow_error(BOLD RED" Float Overflow error occured, no values can be displayed.");
	if (result < -__FLT_MAX__)
		throw std::overflow_error(BOLD RED " Float Underflow error occured, no values can be displayed.");
    return result;
}

double ScalarConverter::stringToDouble(const std::string &arg)
{
	std::stringstream ss(arg);
    double result;
    ss >> result;
	if (ss.fail())
	throw std::invalid_argument(BOLD RED" Invalid argument occured, no values can be displayed.");
	if (result > __DBL_MAX__)
		throw std::overflow_error(BOLD RED" Overflow error occured, no values can be displayed.");
	if (result < -__DBL_MAX__)
		throw std::overflow_error(BOLD RED " Underflow error occured, no values can be displayed.");
	return result;
}

void ScalarConverter::convertFromChar(char c)
{
	std::cout << BOLD << "char : " << c << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(c) << std::endl;
}
void ScalarConverter::convertFromInt(int n)
{
	if (n >= 32 && n <= 126)
		std::cout << BOLD << "char : " << static_cast<char>(n) << std::endl;
	else
		std::cout << BOLD << "char : " << "Non displayable" << std::endl;

	std::cout << "int : " << n << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(n) << std::endl;
}
void ScalarConverter::convertFromFloat(float f)
{
	if (f == static_cast<int>(f) && f >= 32 && f <= 126)
		std::cout << BOLD << "char : " << static_cast<char>(f) << std::endl;
	else
		std::cout << BOLD << "char : " << "Non displayable" << std::endl;

	std::cout << "int : " << static_cast<float>(f) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertFromDouble(double d)
{
	if (d == static_cast<int>(d) && d >= 32 && d <= 126)
		std::cout << BOLD << "char : " << static_cast<char>(d) << std::endl;
	else
		std::cout << BOLD << "char : " << "Non displayable" << std::endl;

	std::cout << "int : " << static_cast<int>(d) << std::endl;
	std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double : " << d << std::endl;
}
