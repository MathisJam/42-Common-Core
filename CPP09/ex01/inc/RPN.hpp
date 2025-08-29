/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:27:41 by mjameau           #+#    #+#             */
/*   Updated: 2025/05/28 17:30:08 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iterator>
#include <fstream>
#include <sstream>
#include <stdexcept>

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

class RPN
{
	public :
		RPN();
		~RPN();
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &param);

		void ParseRPN(const std::string &str);

	private :
		std::stack<int, std::list<int> > _st;
		bool isOp(char c);
		int DoTheMath(char Op, int a, int b);
};

#endif


