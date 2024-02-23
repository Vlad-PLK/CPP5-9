/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:12:19 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/20 09:18:08 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Serializer.hpp"

Serializer::Serializer(){
	//std::cout << "construct" << std::endl;
}

Serializer::Serializer(const Serializer& copy){
	//std::cout << "construct" << std::endl;
	*this = copy;
}

Serializer	&Serializer::operator=(const Serializer& ope)
{
	(void)ope;
	return (*this);
}

Serializer::~Serializer(){
	//std::cout << "construct" << std::endl;
}

uintptr_t	Serializer::_serialize(Data* ptr)
{
	uintptr_t a;

	a = reinterpret_cast<uintptr_t>(ptr);
	return (a);
}

Data	*Serializer::_deserialize(uintptr_t raw)
{
	Data	*ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}