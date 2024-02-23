/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:55:35 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/06 15:41:30 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include "Span.hpp"

Span::Span(int _N)
{
	// std::cout << Default constructor called << std::endl; //
	this->N = _N;
}

Span::Span(const Span &_copy)
{
	// std::cout << Copy constructor called << std::endl;
	*this = _copy;
}

Span	&Span::operator=(const Span &_opeCopy)
{
	// std::cout << Overload operator constructor called << std::endl; //
 	this->N = _opeCopy.N;
	return (*this);
}

Span::~Span()
{
	// std::cout << Default destructor called << std::endl;
}

const char	*Span::SpanException::SpaceExc() const throw()
{
	return ("Not enough space to store more numbers !");
}

const char	*Span::SpanException::DistExc() const throw()
{
	return ("Span empty or filled with just one int, please try again !");
}

void	Span::addNumber(int number)
{
	if (this->tab.size() < this->N)
	{
		this->tab.push_back(number);
		//std::cout << "adding " << number << " to the span" << std::endl;
	}
	else
		throw SpanException();
}

void	Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	while (beg != end)
	{
		try
		{
			addNumber(*beg);
			std::cout << "adding " << *beg << " to the span" << std::endl;
			beg++;
		}
		catch(const Span::SpanException &e)
		{
			std::cerr << e.SpaceExc() << '\n';
			break ;
		}
	}
}

int	Span::longestSpan(void)
{
	if (this->tab.size() > 1)
		return (*std::max_element(tab.begin(), tab.end()) - *std::min_element(tab.begin(), tab.end()));
	else
		throw SpanException();
}

int	Span::shortestSpan(void)
{
	if (this->tab.size() > 1)
	{
		std::vector<int>::iterator	it;
		int							diff;
		diff = *std::max_element(tab.begin(), tab.end());
		std::sort(tab.begin(), tab.end());
		std::reverse(tab.begin(), tab.end());
		for (it = tab.begin(); it != tab.end() -1; it++)
		{
			if (diff > *it - *(it + 1))
				diff = *it - *(it + 1);
		}
		return (diff);
	}
	else
		throw SpanException();
}