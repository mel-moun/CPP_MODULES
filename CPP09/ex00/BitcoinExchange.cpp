/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:35:11 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 15:20:12 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/***************** Orthodox Form *********************************************/

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : _btc(copy._btc) {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		this->_btc = copy._btc;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {_btc.clear();}

/***************** First Part ************************************************/

void	BitcoinExchange::open_file(const std::string& input)
{
	std::fstream	file(input), data("data.csv");

	if (!file.is_open() || !data.is_open())
		throw std::runtime_error("Error: could not open file.");
	BitcoinExchange::store_data(data);
	BitcoinExchange::parsing(file);
	file.close();
	data.close();
}

void	BitcoinExchange::store_data(std::fstream &data)
{
	std::string			tmp, one, two;
	std::istringstream	ss;

	std::getline(data, tmp);
	while (std::getline(data, tmp))
	{
		ss.clear();
		ss.str(tmp);
		std::getline(ss, one, ',');
		std::getline(ss, two, ',');
		_btc.insert(std::make_pair(one, std::strtod(two.c_str(), NULL)));
	}
}

void	BitcoinExchange::parsing(std::fstream& file)
{
	std::string		content;

	std::getline(file, content);
	if (content != "date | value")
		throw std::runtime_error("Error: file must start with \"date | value\".");
	if (file.eof())
		throw std::runtime_error("Error: file contains no data.");
	while (!file.eof())
	{
		std::getline(file, content);
		valid_format(content);
	}
}

int	BitcoinExchange::is_leap_year(int value)
{
	return (value % 4 == 0 && (value % 100 != 0 || value % 400 == 0));
}

void	BitcoinExchange::valid_format(const std::string& content)
{
	std::string			date, value;
	int 				check;
	std::istringstream	ss(content);

	std::getline(ss, date, '|');
	std::getline(ss, value, '|');
	check = syntax_value(value);
	if (!date[0] || !value[0] || syntax_date(date)
	|| valid_date(date) || check == 13)
	{
		std::cout << "Error: bad input => " << content << std::endl;
		return ;
	}
	if (check == 37)
		return ;
	multiplication(date, value);
}

int	BitcoinExchange::syntax_date(const std::string& date)
{
	if (date.length() != 11 || date[date.length() - 1] != 32)
		return (1);
	struct tm time;
	if (!strptime(date.c_str(), "%Y-%m-%d", &time))
		return (1);
	return (0);
}

int	BitcoinExchange::valid_date(const std::string& date)
{
	struct tm time;
	strptime(date.c_str(), "%Y-%m-%d", &time);
	if ((time.tm_year + 1900) < 2009)
		return (1);
	if ((time.tm_mon + 1) == 2)
	{
		if (is_leap_year(time.tm_year + 1900) && !(time.tm_mday >= 1 && time.tm_mday <= 29))
			return (1);
		else if (!is_leap_year(time.tm_year + 1900) && !(time.tm_mday >= 1 && time.tm_mday <= 28))
			return (1);
	}
	return (0);
}

int	BitcoinExchange::syntax_value(const std::string& value)
{
	if (!(value[0] == 32 && (value[1] == '+' || value[1] == '-' || std::isdigit(value[1]) || value[1] == '.')))
		return (13);

	char	*ptr;
	double	i = std::strtod(value.c_str(), &ptr);
	if (value[value.length() -1 ] == '.' || !(ptr == NULL || ptr[0] == '\0'))
		return (13);
	if (i < 0 || !((i >= 0 && i <= 1000)))
	{
		if (i < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return (37);
	}
	return (0);
}

/***************** Second Part ***********************************************/

void	BitcoinExchange::multiplication(const std::string& date, const std::string& value)
{
	double		num = std::strtod(value.c_str(), NULL);
	std::map<std::string, double>::iterator it = _btc.lower_bound(date);

	if (it->first != date)
		it--;
	std::cout << date << " => " << num << " = " << (num * it->second) << std::endl;
}
