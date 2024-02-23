/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:21:45 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/12 14:45:31 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
	///std::cout << "Default BTC constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &_copy)
{
	*this = _copy;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &_opeCopy)
{
	this->file_name = _opeCopy.file_name;
	this->tab = _opeCopy.tab;
	this->tm = _opeCopy.tm;
	this->date_details = _opeCopy.date_details;
	this->format = _opeCopy.format;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){
	///std::cout << "Default BTC destructor" << std::endl;
}

char	*BitcoinExchange::get_name(void) const
{
	return (this->file_name);
}

void	BitcoinExchange::set_name(char *_file_name)
{
	this->file_name = _file_name;
}

void	BitcoinExchange::set_map()
{
	std::fstream		csv;
	std::string			line;
	std::string			tmp_date;
	std::string			tmp_str_value;
	float				tmp_value;

	csv.open("data.csv", std::ios::in);
	this->format = "%Y-%m-%d";
	getline(csv, line);
	while (getline(csv, line))
	{
		std::memset(&this->tm, 0, sizeof(this->tm));
		tmp_date.assign(line, 0, line.find(','));
		this->date_details = tmp_date.c_str();
		tmp_str_value.assign(line, line.find(',') + 1);
		tmp_value = atof(tmp_str_value.c_str());
		strptime(this->date_details, this->format, &this->tm);
		this->tab.insert(std::pair<time_t, float>(mktime(&this->tm), tmp_value));
	}
}

bool	BitcoinExchange::parse_args(std::string raw_time, time_t input, float quantity)
{
	if (this->tab.begin()->first > input || this->tab.rbegin()->first < input)
	{
		std::cout << "Error: bad input => " << raw_time << std::endl;
		return (1);
	}
	else if (quantity < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (1);
	}
	else if (quantity > 1000)
	{
		std::cout << "Error: too large number." << std::endl;
		return (1);
	}
	else 
		return (0);
}

void	BitcoinExchange::search_input(std::string raw_time, time_t input, float quantity)
{
	std::map<time_t, float>::iterator it;

	if (parse_args(raw_time, input, quantity) == 0)
	{
		it = this->tab.lower_bound(input);
		strftime(this->date, sizeof(this->date), "%Y-%m-%d", gmtime(&it->first));
		std::cout << this->date << " => " << quantity << " = " << it->second * quantity << std::endl;
	}
}

void	try_file(char *input)
{
	std::ifstream	file(input);
	std::string		tmp_line;
	std::string		key;
	std::string		quantity;

	if (file.good() == true && file.is_open())
	{
		BitcoinExchange	btc;
		btc.set_name(input);
		btc.set_map();
		getline(file, tmp_line);
		while (getline(file, tmp_line))
		{
			key.assign(tmp_line, 0, tmp_line.find('|') -1);
			btc.date_details = key.c_str();
			quantity.assign(tmp_line, tmp_line.find('|') +1);
			strptime(btc.date_details, btc.format, &btc.tm);
			btc.search_input(key, mktime(&btc.tm), atof(quantity.c_str()));
		}
		file.close();
	}
	else
	{
		std::cout << "Error: Could not open file!" << std::endl;
	}
}