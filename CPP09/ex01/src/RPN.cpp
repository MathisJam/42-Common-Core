/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:38:09 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/02 11:49:26 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

// CANON FORM --------------------------------------------------------------
RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &cpy)
{
	*this = cpy;
}

RPN &RPN::operator=(const RPN &param)
{
	if (this != &param)
		this->_st = param._st;
	return (*this);
}

// MEMBER FUNCTIONS -----------------------------------------------------------

bool RPN::isOp(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int RPN::DoTheMath(char Op, int a, int b)
{
	switch(Op)
	{
		case '+':
			return (a+b);

		case '-':
			return (a-b);

		case '*':
			return (a*b);

		case '/':
			if (b == 0)
				throw(std::runtime_error(BOLD RED"Division by 0, segfault risk" RESET));
			return (a/b);

		default:
			throw(std::runtime_error(BOLD RED "Invalid operand" RESET));
	}

}

void RPN::ParseRPN(const std::string &str)
{
	std::istringstream ss(str);
	std::string token;
	bool flagOp = false;

	while (ss >> token)
	{
		if (token.length() == 1 && isdigit(token[0]))
			_st.push(token[0] - '0');
		else if (token.length() == 1 && isOp(token[0]))
		{
			flagOp = true;
			if (_st.size() < 2)
				throw(std::logic_error(BOLD RED "Not enough digits to operate" RESET));

			int b = _st.top(); _st.pop();
			int a = _st.top(); _st.pop();

			int res = DoTheMath(token[0], a, b);
			_st.push(res);
		}
		else
			throw(std::runtime_error(BOLD RED "Error: Make sure all tokens are separate by a space" RESET));
	}
	if (!flagOp)
		throw std::logic_error(BOLD RED "No operators" RESET);
	if (_st.size() < 1)
		throw(std::logic_error(BOLD RED "Invalid RPN" RESET));
	if (_st.size() != 1)
		throw std::logic_error(BOLD RED "Leftover or missing operators" RESET);

	std::cout << BOLD CYAN << "Result : " << _st.top() << " ✨​" << RESET << std::endl;
}
