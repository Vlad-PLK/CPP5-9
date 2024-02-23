/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:54:01 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/05 11:14:34 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <string>
#include <iostream>
#include <exception>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <algorithm>

class	NotFindException : public std::exception
{
	public:
		const char *NFexception() const throw();
};

const	char *NotFindException::NFexception() const throw()
{
	return ("There is not any occurence of this int in this container");
}

template< typename T>
typename T::iterator easyfind(T &arg, int snd_arg)
{
	typename T::iterator	it;
	//int						find;

	it = std::find(arg.begin(), arg.end(), snd_arg);
	if (it != arg.end())
	{
		std::cout << *it << " is in this container"<< std::endl;
		return (it);
	}
	else
		throw NotFindException();

	/*
			// simple for loop with iterator to find snd_arg //
					works too !
		for (it = arg.begin(); it != arg.end(); it++)
		{
			if (*it == snd_arg)
			{
				std::cout << snd_arg << " is in this container"<< std::endl;
				return (it);
			}
		}
		throw NotFindException();
	*/

	//	count method also works to find an occurence //
	/*find = std::count(arg.begin(), arg.end(), snd_arg);
	if (find == 1)
	{
		std::cout << snd_arg << " is in this container"<< std::endl;
		return (it);
	}*/
}

#endif