/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:12:43 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/20 09:25:17 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include <iostream>

struct Data;

class Serializer
{
  private:
	Serializer();
	Serializer(Serializer const &_copy);
	Serializer &operator=(Serializer const &_OpCopy);
	~Serializer();
  public:
	static uintptr_t	_serialize(Data* ptr);
	static Data*		_deserialize(uintptr_t raw);
};

#endif