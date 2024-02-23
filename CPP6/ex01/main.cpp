/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:13 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/20 09:25:41 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data	*ptr;
	Data	*receiver;
	Data	content;
	uintptr_t	raw;

	content.name.assign("vlad");
	content.value = 1;
	ptr = &content;
	std::cout << "Address of ptr : " << ptr << std::endl;
	raw = Serializer::_serialize(ptr);
	receiver = Serializer::_deserialize(raw);
	std::cout << "Address of receiver after deserialization : " <<receiver << std::endl;
	std::cout << "Content inside ptr : "<< ptr->name << " " << ptr->value << std::endl;
	std::cout << "Content inside receiver : "<< receiver->name << " " << receiver->value << std::endl;
	return (0);
}