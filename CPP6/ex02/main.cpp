/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:44:59 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/20 10:37:35 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

int main(void)
{
	Base	c1;
	Base	c2;
	srand(time(NULL));
	std::cout << "identify used with a pointer base class : " << std::endl;
	c1.identify(c1.generate());
	std::cout << "\n";

	Base *ptr = c2.generate();
	std::cout << "identify used with a reference on a base class : " << std::endl;
	c2.identify(*ptr);
	std::cout << "\n";

	return (0);
}