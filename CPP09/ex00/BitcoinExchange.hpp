/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:35:14 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 11:25:45 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <ctime>

class BitcoinExchange
{
private:
	std::map<std::string, double> _btc;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange&	operator=(const BitcoinExchange& copy);
	~BitcoinExchange();

	void	open_file(const std::string& input);
	void	parsing(std::fstream& file);
	void	valid_format(const std::string& content);
	int		syntax_date(const std::string& date);
	int		valid_date(const std::string& date);
	int		syntax_value(const std::string& value);
	void	store_data(std::fstream &data);
	void	multiplication(const std::string& date, const std::string& value);
	int		is_leap_year(int value);
};

#endif
