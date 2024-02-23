/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:53:00 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/06 15:51:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "Span.hpp"

int	main(void)
{
	Span	sp = Span(100);
	srand(time(NULL));
		// big span haha //
	//Span	sp = Span(100000);
	std::vector<int>	vec;
	for (int i = 0; i != 105; i++)
		vec.push_back(i);
		// random numbers //
	//for (int i = 0; i != 100; i++)
	//	vec.push_back(rand() % 100);
		// a lot of numbers //
	//for (int i = 0; i != 100000; i++)
	//	vec.push_back(i);
	sp.addRange(vec.begin(), vec.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "\n";
	Span sp2 = Span(5);
  	sp2.addNumber(6);
  	sp2.addNumber(3);
  	sp2.addNumber(17);
  	sp2.addNumber(9);
  	sp2.addNumber(11);
  	std::cout << sp2.shortestSpan() << std::endl;
  	std::cout << sp2.longestSpan() << std::endl;
	std::cout << "\n";
	try
	{
		sp2.addNumber(5);
	}
	catch(const Span::SpanException &e)
	{
		std::cerr << e.SpaceExc() << '\n';
	}
	std::cout << "\n";
	Span sp3(5);
	try
	{
		sp3.longestSpan();
	}
	catch(const Span::SpanException &e)
	{
		std::cerr << e.DistExc() << '\n';
	}
	try
	{
		sp3.shortestSpan();
	}
	catch(const Span::SpanException &e)
	{
		std::cerr << e.DistExc() << '\n';
	}
	
	return (0);
}