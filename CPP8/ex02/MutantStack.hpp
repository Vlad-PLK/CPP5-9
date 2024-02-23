/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:01:36 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/06 17:12:20 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>
#include <algorithm>
#include <iterator>

template< typename T, typename _Container = std::deque <T > >
class MutantStack : public std::stack<T, _Container>
{ 
  private:
	
  public:
  	MutantStack(){

	};
	MutantStack(const MutantStack &_copy){
		*this = _copy;
	}
	MutantStack	&operator=(const MutantStack &_opecopy){
		std::stack<T, _Container>::operator=(_opecopy);
		return (*this);
	}
	~MutantStack(){

	};
	typedef typename _Container::iterator iterator;
	iterator	begin()
	{
		return (this->c.begin());
	}
 	iterator	end()
	{
		return (this->c.end());
	}
};

#endif