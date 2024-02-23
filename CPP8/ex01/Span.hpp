/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:56:07 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/06 11:02:27 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <algorithm>

class Span
{
  private:
	unsigned int	N;
	std::vector<int>	tab;
  public:
	Span(int _N);
	Span(Span const &_copy);
	Span &operator=(Span const &_OpCopy);
	~Span();
	void	addNumber(int number);
	void	addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
	int		shortestSpan(void);
	int		longestSpan(void);
	class SpanException : public std::exception
	{
		public:
			const char *SpaceExc() const throw();
			const char *DistExc() const throw();
	};
};

#endif