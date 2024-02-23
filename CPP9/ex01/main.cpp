/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:20:30 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/12 15:56:41 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
        parse_arg(argv[1]);
    else
        std::cout << "Error : incorrect arguments" << std::endl;
}