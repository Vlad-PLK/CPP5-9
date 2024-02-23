/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:57:09 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/23 14:12:39 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP
#include <string>

template< typename T> // that's how you define a template
void	swap(T &x, T &y) // T will be replaced by the real type of the variable when you will call this template
{
	T	temp;
	temp = x;
	x = y;
	y = temp;
}

template< typename T1>
T1	min(T1 const &x, T1 const &y)
{
	if (x < y)
		return(x);
	else
		return(y);
}

template< typename T3>
T3	max(T3 const &x, T3 const &y)
{
	if (x > y)
		return(x);
	else
		return(y);
}

#endif