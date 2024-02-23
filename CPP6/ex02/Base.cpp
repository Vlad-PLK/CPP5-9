/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 09:52:11 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/20 10:37:31 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <stdlib.h>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base default destructor called" << std::endl;
}

Base	*Base::generate(void)
{
	Base	*ptr = NULL;
    int i = rand() % 3 + 1;
	switch (i)
	{
	case 1:
		ptr = new A;
		break;
	case 2:
		ptr = new B;
		break;
	case 3:
		ptr = new C;
		break;
	}
	return (ptr);
}

void	Base::identify(Base *ptr)
{
	A	*Aptr;
	B	*Bptr;
	C	*Cptr;
	Aptr = dynamic_cast<A*>(ptr);
	Bptr = dynamic_cast<B*>(ptr);
	Cptr = dynamic_cast<C*>(ptr);
	if (Aptr)
		std::cout << "Base ptr is an A class" << std::endl;
	else if (Bptr)
		std::cout << "Base ptr is an B class" << std::endl;
	else if (Cptr)	
		std::cout << "Base ptr is an C class" << std::endl;
}

void	Base::identify(Base &ptr)
{
	try
	{
		A &Aref = dynamic_cast<A&>(ptr);
		std::cout << "this class is an A class" << std::endl;
		(void)Aref;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			B &Bref = dynamic_cast<B&>(ptr);
			std::cout << "this class is an B class" << std::endl;
			(void)Bref;
		}
		catch(const std::bad_cast& e)
		{
			C &Cref = dynamic_cast<C&>(ptr);
			std::cout << "this class is an C class" << std::endl;
			(void)Cref;
		}
		
	}
	
}