/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:48 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/22 08:52:38 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <time.h>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>

PmergeMe::PmergeMe(){
    //std::cout << "Default Constructor called" << std::endl;
    
}

PmergeMe::~PmergeMe(){
    //std::cout << "Default Destructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe  &PmergeMe::operator=(const PmergeMe &opeCopy)
{
    this->vector_tab = opeCopy.vector_tab;
    this->list_tab = opeCopy.list_tab;
    return (*this);
}

void	PmergeMe::recursive_pairs_sort_list(std::list<int> &input)
{
	std::list<int> paired;

	if (input.size() <= 1)
		return ;
	else if (input.size() <= 2)
	{
		if (input.front() > input.back())
			std::swap(input.front(), input.back());
		return ;
	}

	// sort pairs two by two //
	std::list<int>::iterator it;
	int	a;
	int	b;
	for (it = input.begin(); it != input.end(); it++)
	{
		a = *it;
		it++;
		if (it == input.end())
			break ;
		b = *it;
		paired.push_back(std::max(a, b));
		paired.push_back(std::min(a, b));
	}
	if ((input.size() % 2) != 0)
		paired.push_back(input.back());
	input.clear();

	// create list of all bigger elements of pairs //
	for (size_t i = 0; i < paired.size() - 1; i += 2)
	{
		it = paired.begin();
		std::advance(it, i);
		input.push_back(*it);
	}
	if ((paired.size() % 2) != 0)
		input.push_back(paired.back());

	// call again with a smaller list to do the recursive sort //
	this->recursive_pairs_sort_list(input);
	// do the binary search recursively and insert smaller elements
	std::list<int>::iterator it2;
	for (size_t i=1; i < paired.size(); i += 2)
	{
		it = paired.begin();
		it2 = input.begin();
		std::advance(it, i);
		int middle = this->binary_search_for_list(*it, input.size(), input);
		std::advance(it2, middle);
		input.insert(it2, *it);
	}
	return ;
}

int	PmergeMe::binary_search_for_list(int value, int size, std::list<int> &tab)
{
	std::list<int>::iterator index_middle;
	std::list<int>::iterator index_middle_m1;
	
	int	middle = size / 2;
	int	step = size / 4;
	if (step == 0)
		step = 1;
	while (true)
	{
		index_middle = tab.begin();
		index_middle_m1 = tab.begin();
		std::advance(index_middle, middle);
		std::advance(index_middle_m1, middle - 1);
		if (*index_middle >= value
		&& (middle == 0 || *index_middle_m1 <= value))
			break ;
		else if (*index_middle >= value)
			middle = middle - step;
		else if (*index_middle <= value)
			middle = middle + step;
		if (step != 1)
			step /= 2;
	}
	return (middle);
}

void	PmergeMe::recursive_pairs_sort_vector(std::vector<int> &input)
{
	std::vector<int> paired;

	if (input.size() <= 1)
		return ;
	else if (input.size() <= 2)
	{
		if (input[0] > input[1])
			std::swap(input[0], input[1]);
		return ;
	}

	// sort pairs two by two //
	for (size_t i=0; i < input.size() -1; i += 2)
	{
		paired.push_back(std::max(input[i], input[i + 1]));
		paired.push_back(std::min(input[i], input[i + 1]));
	}
	if ((input.size() % 2) != 0)
		paired.push_back(input.back());
	input.clear();

	// create list of all bigger elements of pairs //
	for (size_t i = 0; i < paired.size() - 1; i += 2)
		input.push_back(paired[i]);
	if ((paired.size() % 2) != 0)
		input.push_back(paired.back());

	// call again with a smaller list to do the recursive sort //
	this->recursive_pairs_sort_vector(input);
	// do the binary search recursively and insert smaller elements
	for (size_t i=1; i < paired.size(); i += 2)
	{
		int middle = this->binary_search_for_vectors(paired[i], input.size(), input);
		input.insert(input.begin() + middle, paired[i]);
	}
	return ;
}

int	PmergeMe::binary_search_for_vectors(int value, int size, std::vector<int> &tab)
{
	int	middle = size / 2;
	int	step = size / 4;
	if (step == 0)
		step = 1;
	while (true)
	{
		if (tab[middle] >= value
		&& (middle == 0 || tab[middle - 1] <= value))
			break ;
		else if (tab[middle] >= value)
			middle = middle - step;
		else if (tab[middle] <= value)
			middle = middle + step;
		if (step != 1)
			step /= 2;
	}
	return (middle);
}

void	PmergeMe::sort_vector()
{
	struct timeval	start;
	struct timeval	end;
	float			time;

	gettimeofday(&start, NULL);
	this->recursive_pairs_sort_vector(this->vector_tab);
	gettimeofday(&end, NULL);
	std::cout << "After : ";
	display_tab<std::vector<int>::iterator>(this->vector_tab.begin(), this->vector_tab.end());
	time = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << this->vector_tab.size() << " elements with std::vector : " << time << " us" << std::endl;
	return ;
}

void	PmergeMe::sort_list()
{
	struct timeval	start;
	struct timeval	end;
	float			time;

	gettimeofday(&start, NULL);
	this->recursive_pairs_sort_list(this->list_tab);
	gettimeofday(&end, NULL);
	time = ((end.tv_sec - start.tv_sec) * 1e6) + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << this->list_tab.size() << " elements with std::list : " << time << " us" << std::endl;
	return ;
}

bool	PmergeMe::parse_args(int argc, char **argv)
{
	for (int i=1; i != argc; i++)
	{
		for (int j=0; argv[i][j] != '\0'; j++)
		{
			if (!isdigit(argv[i][j]) && !isspace(argv[i][j]))
			{	
				std::cout << "Error: only positive integers as arguments !" << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

bool    PmergeMe::setup_tabs(int argc, char **argv)
{
	std::string			tmp;

	if (this->parse_args(argc, argv) == true)
	{
		for (int i=1; i != argc; i++)
		{
			tmp.assign(argv[i]);
			this->vector_tab.push_back(atoi(tmp.c_str()));
			this->list_tab.push_back(atoi(tmp.c_str()));
		}
		std::cout << "Before : ";
		for (int i=1; i != argc; i++)
			std::cout << argv[i] << " ";
		std::cout << "\n";
		return (true);
	}
	else
		return (false);
}