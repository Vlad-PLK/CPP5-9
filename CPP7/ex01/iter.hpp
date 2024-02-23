/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:22:43 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/22 14:10:18 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstdlib>

// two type -> one for the array address and one for the function to use on the array
template< typename Adr, typename F>
void	iter(Adr *arr, int length, F f)
{
	for (int i=0; i != length; i++)
		f(arr[i]);
}
#endif