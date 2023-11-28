/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:06:11 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 17:35:08 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"

/*************** Orthodox Canonical From **************************/

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

/********************* Convert method *****************************/

void    ScalarConverter::convert(const std::string& input)
{
	vars	all;
	switch (exacte_type(input))
	{
		case LITERALS:
			was_literal(input);
			return ;
		case NONE:
			was_unkown();
			return ;
		case CHAR:
			was_char(input);
			return ;
		case INT:
			was_int(input, &all);
			break;
		case FLOAT:
			was_float(input, &all);
			break;
		case DOUBLE:
			was_double(input, &all);
	}
	display_converted(&all, input);
}
