/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:34:32 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 11:40:58 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("Error: could not open file.");
		BitcoinExchange ob;
		ob.open_file(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
