/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:20:18 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/12 14:21:13 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <ctime>

class BitcoinExchange
{
  private:
	std::map<std::time_t, float>	tab;
	char							*file_name;
	char							date[11];
  public:
	const char						*date_details;
	const char						*format;
	struct tm						tm;

	void	set_name(char *_file_name);
	char	*get_name(void) const;
	void	set_map();
	void	search_input(std::string raw_time, time_t input, float quantity);
	bool	parse_args(std::string raw_time, time_t key, float quantity);

	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &_copy);
	BitcoinExchange &operator=(BitcoinExchange const &_OpCopy);
	~BitcoinExchange();
};

void	try_file(char *input);

#endif