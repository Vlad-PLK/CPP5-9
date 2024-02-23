/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:44:45 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/25 08:45:34 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>

#define MAX_VAL 750
int main(void)
{
	srand(time(NULL));
    Array<int>	tab(5);
	int	*mirror = new int(5);
	for (unsigned int i=0; i!=5; i++)
	{
		const int value = rand() % 10;
		tab[i] = value;
		mirror[i] = value;
	}
	for (unsigned int i=0; i!=5; i++)
	{
		std::cout << "template array : " << tab[i] << std::endl;
		std::cout << "basic int array : " << tab[i] << std::endl;
	}
	std::cout << "Size of the array : " << tab.size() << std::endl;
	try
	{
		std::cout << tab[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << tab[12] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete mirror;
    return 0;
}