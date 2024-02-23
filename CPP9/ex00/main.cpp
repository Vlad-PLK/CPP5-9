/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:19:37 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/09 15:53:05 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iomanip>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 2)
		try_file(argv[1]);
	else
		std::cout << "Error: Could not open file !" << std::endl;
	return (0);
}