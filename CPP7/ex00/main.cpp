/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:22:34 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/23 14:10:41 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Template.hpp"	// include of the template
#include <string>
#include <iostream>

int main(void)
{
	int a = 2;
	int b = 3;
	swap<int>( a, b );	// explicit call
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl; // implicit call
	std::cout << "max( a, b ) = " << max<int>( a, b ) << std::endl; // explicit call
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);		// implicit call
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return (0);
}