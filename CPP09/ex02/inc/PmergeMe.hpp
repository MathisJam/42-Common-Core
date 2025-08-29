/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:02:47 by mjameau           #+#    #+#             */
/*   Updated: 2025/05/28 18:05:05 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <sys/time.h>
#include <set>
#include <iomanip>

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

class PmergeMe
{
	public :
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &cpy);
		PmergeMe &operator=(const PmergeMe &param);
		void ParseInput(char **tab);
		void FordDeque();
		void FordVector();
		std::vector<unsigned int> getVector();
		std::deque<unsigned int> getDeque();
		// void MakePairs(char **tab);

	private :
		std::deque<unsigned int> dq;
		std::vector<unsigned int> vct;
};

double getTime();
std::vector<size_t> JacobsthalIndex(size_t nb);
void SortFordVector(std::vector<unsigned int> &seq);
void SortFordDeque(std::deque<unsigned int> &seq);

#endif
