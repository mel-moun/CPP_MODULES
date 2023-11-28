/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_type.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:24:54 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/22 16:54:59 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"

/****************** Check which type **************************/

int		is_literal(const std::string& input)
{
	std::string		w[12] = {"inf", "+inf", "inff", "+inff",
	"-inf","-inff", "nan", "+nan", "nanf", "+nanf", "-nan", "-nanf"};
	int				i = 0;

	for (; i < 12; i++)
	{
		if (input == w[i])
			return (0);
	}
	return (1);
}

int	is_char(const std::string &input)
{
	if (input.length() == 1)
		return (0);
	return (1);
}

int	unkown_type(const std::string &input)
{
	if (check_chars(input) || check_special_chars(input) \
	|| minus_plus(input) || number_syntax(input))
		return (0);
	return (1);
}

int	is_int(const std::string &input)
{
	size_t i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.length() && std::isdigit(input[i]); i++) {}
	if (input[i])
		return (1);
	return (0);
}

int	is_float(const std::string &input)
{
	size_t i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; i < input.length() && (std::isdigit(input[i]) || input[i] == '.'); i++) {}
	if (input[i] == 'f')
		return (0);
	return (1);
}

/***************** Knowing which one **************************/

int	exacte_type(const std::string &input)
{
	if (!is_literal(input))
		return (LITERALS);
	else if (!is_char(input))
		return (CHAR);
	else if (!unkown_type(input))
		return (NONE);
	else if (!is_int(input))
		return (INT);
	else if (!is_float(input))
		return (FLOAT);
	return (DOUBLE);
}
