/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literals.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:20:56 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/22 17:00:05 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

void	was_literal(const std::string& input)
{
	std::string		w[12] = {"inf", "+inf", "inff", "+inff", "-inf", "-inff", "nan", "+nan", "nanf", "+nanf", "-nan", "-nanf"};
	int				i = 0;

	for (; i < 12; i++)
	{
		if (input == w[i])
			break;
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (i >= 0 && i <= 3)
	{
		std::cout << "float: " << "inff" << std::endl;
		std::cout << "double: " << "inf" << std::endl;
	}
	else if (i == 4 || i == 5)
	{
		std::cout << "float: " << "-inff" << std::endl;
		std::cout << "double: " << "-inf" << std::endl;
	}
	else
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}
