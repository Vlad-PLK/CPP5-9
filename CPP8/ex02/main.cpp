/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:58:56 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/07 09:59:08 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <algorithm>
#include "MutantStack.hpp"

int	main(void)
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.front() << std::endl;
	mstack.pop_front();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3); 
	mstack.push_back(5); 
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin(); 
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) 
	{
	    std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int> s;
	std::cout << "\n";
	MutantStack<int> _mstack;
	_mstack.push(17);
	_mstack.push(5);
	std::cout << _mstack.top() << std::endl;
	_mstack.pop();
	std::cout << _mstack.size() << std::endl;
	_mstack.push(3); 
	_mstack.push(5); 
	_mstack.push(737);
	_mstack.push(0);
	MutantStack<int>::iterator it1 = _mstack.begin(); 
	MutantStack<int>::iterator ite1 = _mstack.end();
	++it1;
	--it1;
	while (it1 != ite1) 
	{
	    std::cout << *it1 << std::endl;
		++it1; 
	}
	std::stack<int> s1(_mstack);
}