/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:05:25 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/22 08:43:37 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe 	merge_me;
	if (argc > 1)
	{
		if (merge_me.setup_tabs(argc, argv) == true) 
		{
			merge_me.sort_vector();
			merge_me.sort_list();
		}
	}
	else
		std::cout << "Error" << std::endl;
	return (0);
}