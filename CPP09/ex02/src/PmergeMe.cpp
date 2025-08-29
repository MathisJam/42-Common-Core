/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjameau <mjameau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:02:43 by mjameau           #+#    #+#             */
/*   Updated: 2025/06/02 11:29:34 by mjameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// CANON FORM --------------------------------------------------------------
PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &param)
{
	if (this != &param)
	{
		this->dq = param.dq;
		this->vct = param.vct;
	}
	return (*this);
}

// GETTERS

std::vector<unsigned int> PmergeMe::getVector()
{
	return this->vct;
}
std::deque<unsigned int> PmergeMe::getDeque()
{
	return this->dq;
}

// FUNCTIONS ---------------------------------------------------
void PmergeMe::ParseInput(char **tab)
{
	for (int i = 0; tab[i] ;i++)
	{
		char *end;
		unsigned long num = std::strtoul(tab[i], &end, 10);
		if (*end != 0 || num > UINT_MAX)
		{
			std::cerr << BOLD RED << "Invalid number" << RESET << std::endl;
			exit(1);
		}
		unsigned int nb = static_cast<unsigned int>(num);
		dq.push_back(nb);
		vct.push_back(nb);
	}
}

double getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return static_cast<double>(tv.tv_sec) * 1e6 + static_cast<double>(tv.tv_usec);
}

void PmergeMe::FordDeque()
{
	// long start = getTime();

	SortFordDeque(dq);

	// long end = getTime();

	// std::cout << BOLD CYAN << std::fixed << std::setprecision(5) <<
	//  "Time to process a range of " << dq.size() <<" elements with std::deque : " << (end - start) << " us" << RESET << std::endl;
}
void SortFordDeque(std::deque<unsigned int> &seq)
{
	if (seq.size() <= 1)
		return ;

	std::deque<unsigned int> main;
	std::deque<unsigned int> pend;

	for (size_t i = 0; i + 1 < seq.size(); i += 2)
	{
		unsigned int a = seq[i];
		unsigned int b = seq[i + 1];

		if (a > b)
			std::swap(a, b);
		main.push_back(b);
		pend.push_back(a);
	}

	if (seq.size() % 2 != 0)
		main.push_back(seq.back());

	SortFordDeque(main);

	std::vector<size_t> jacIndexes = JacobsthalIndex(pend.size());

	for (size_t i = 0; i < jacIndexes.size(); i++)
	{
		size_t idx = jacIndexes[i];
		if (idx < pend.size())
		{
			std::deque<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[idx]);
			main.insert(pos, pend[idx]);
		}
	}
	seq = main;

}


void PmergeMe::FordVector()
{
	// long start = getTime();

	SortFordVector(vct);

	// long end = getTime();

	// std::cout << BOLD CYAN << std::fixed << std::setprecision(5) <<
	//  "Time to process a range of " << dq.size() <<" elements with std::vector : " << (end - start) << " us" << RESET << std::endl;
}
void SortFordVector(std::vector<unsigned int> &seq)
{
	if (seq.size() <= 1)
		return ;

	std::vector<unsigned int> main;
	std::vector<unsigned int> pend;

	for (size_t i = 0; i + 1 < seq.size(); i += 2)
	{
		unsigned int a = seq[i];
		unsigned int b = seq[i + 1];

		if (a > b)
			std::swap(a, b);
		main.push_back(b);
		pend.push_back(a);
	}

	if (seq.size() % 2 != 0)
		main.push_back(seq.back());

	SortFordVector(main);

	std::vector<size_t> jacIndexes = JacobsthalIndex(pend.size());

	for (size_t i = 0; i < jacIndexes.size(); i++)
	{
		size_t idx = jacIndexes[i];
		if (idx < pend.size())
		{
			std::vector<unsigned int>::iterator pos = std::lower_bound(main.begin(), main.end(), pend[idx]);
			main.insert(pos, pend[idx]);
		}
	}
	seq = main;

}

std::vector<size_t> JacobsthalIndex(size_t nb)
{
	std::vector<size_t> indexes;
	if (nb == 0)
		return indexes;

	std::vector<size_t> J;
	J.push_back(0);
	J.push_back(1);

	while (J.back() < nb)
	{
		size_t next = J[J.size() - 1] + 2 * J[J.size() - 2];
		J.push_back(next);
	}

	indexes.push_back(0);
	for (int i = 2; i < (int)J.size() && J[i] < nb; i++)
		indexes.push_back(J[i]);

	for (size_t i = 1; i < nb; i++)
	{
		bool found = false;
		for (size_t j = 1; j < indexes.size(); j++)
			if (indexes[j] == i)
			{
				found = true;
				break;
			}
		if (!found)
			indexes.push_back(i);
	}

	return indexes;
}


