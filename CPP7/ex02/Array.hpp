/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:14:08 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/22 16:27:34 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
#include <exception>

template< typename T>
class Array
{
private:
	T				*tab;
	unsigned int	_size;
public:
	Array<T>(void) : tab(new T[0]), _size(0)
	{
		std::cout << "Default Template constructor called" << std::endl;
	}
	Array<T>(unsigned int n) : tab(new T[n]), _size(n)
	{
		std::cout << "Default Parameterized Template constructor called" << std::endl;
	}
	Array<T>(const Array &copy) : tab(new T[copy._size]), _size(copy._size)
	{
		std::cout << "Default Copy Template constructor called" << std::endl;
		for (unsigned int i=0; i != copy._size; i++)
			tab[i] = copy.tab[i];
	}
	Array<T>	&operator=(const Array &ope)
	{
		std::cout << "Default Assignement Template constructor called" << std::endl;
		if (this != ope)
		{
			delete[] this->tab;
			this->tab = new T[ope._size];
			this->_size = ope._size;
			for (unsigned int i=0; i != ope._size; i++)
				this->tab[i] = ope.tab[i];
		}
		return (*this);
	}
	T&	operator[](unsigned int index)
	{
		if (index >= this->_size)
			throw OutofBounds();
		return tab[index];
	}
	~Array<T>(void)
	{
		std::cout << "Default Destructor called" << std::endl;
		delete[] this->tab;
	}
	unsigned int	size(void)
	{
		return (this->_size);
	}

	class OutofBounds : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Element is out of range of array");
			}
	};
};

#endif