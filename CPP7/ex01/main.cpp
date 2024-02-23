/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:22:18 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/23 14:26:28 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

void	add(int a)
{
	a++;
	std::cout << a;
}

void	s_add(std::string a)
{
	a.append("vpolojie");
	std::cout << a << std::endl;
}

void	c_add(char c)
{
	c++;
	std::cout << c;
}


int	main(void)
{
	int tab[] = {1, 2, 3};
	char ctab[] = {'a', 'n', 'm', 'i', 'n', 't', 'q'};
	std::string a;
	a.assign("vlad");
	for (int i=0; i != 3; i++)
		std::cout << tab[i];
	std::cout << "\n";
	for (int i=0; i != 7; i++)
		std::cout << ctab[i];
	std::cout << "\n";
	std::cout << a << std::endl;
	std::cout << "\n";
	::iter(tab, 3, add);
	std::cout << "\n";
	::iter(ctab, 7, c_add);
	std::cout << "\n";
	::iter(&a, 1, s_add);
	return (0);
}