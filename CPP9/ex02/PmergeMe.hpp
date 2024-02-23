/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:06:58 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/22 08:52:22 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <iostream>

class PmergeMe
{
	private:
		std::vector<int>    vector_tab;
		std::list<int>     	list_tab;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &_copy);
		PmergeMe	&operator=(const PmergeMe &_opeCopy);
		
		bool	setup_tabs(int argc, char **argv);
		bool	parse_args(int argc, char **argv);
		void	show_pairs() const ;
		void	recursive_pairs_sort_vector(std::vector<int> &input);
		int		binary_search_for_vectors(int index, int max, std::vector<int> &tab);
		void	recursive_pairs_sort_list(std::list<int> &input);
		int		binary_search_for_list(int index, int max, std::list<int> &tab);
		void	sort_vector();
		void	sort_list();

		template <typename T>
		void	display_tab(T begin, T end)
		{
			while (begin != end)
			{
				std::cout << *begin++ << " ";
			}
			std::cout << "\n";
		}
};

#endif