/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:53:00 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/05 11:15:20 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <algorithm>
#include "easyfind.hpp"

int	main(void)
{
	std::list<int> l_list;
	l_list.push_front(12);
	l_list.push_front(1);
	l_list.push_front(42);
	l_list.push_front(50);
	l_list.push_front(21);
	std::array<int, 5> arr = {3, 21, 12, 55, 64};
	std::array<int, 5> arr2 = {1, 13, 98, 51, 22};
	std::vector<int> V1;
	V1.push_back(3);
	V1.push_back(98);
	V1.push_back(124);
	V1.push_back(456);
	V1.push_back(8);
	try
	{
		std::cout << "using easyfind with list container" << std::endl;
		easyfind< std::list<int> >(l_list, 42);
		easyfind< std::list<int> >(l_list, 45);
	}
	catch(const NotFindException& e)
	{
		std::cerr << e.NFexception() << '\n';
	}
	try
	{
		std::cout << "using easyfind with array container" << std::endl;
		easyfind< std::array<int, 5> >(arr, 12);
		::easyfind(arr2, 121);
	}
	catch(const NotFindException& e)
	{
		std::cerr << e.NFexception() << '\n';
	}
	try
	{
		std::cout << "using easyfind with vector container" << std::endl;
		easyfind< std::vector<int> >(V1, 8);
		::easyfind(V1, 12);
	}
	catch(const NotFindException& e)
	{
		std::cerr << e.NFexception() << '\n';
	}
	
	return (0);
}