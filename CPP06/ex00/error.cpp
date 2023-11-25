/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:01:41 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 15:56:36 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"

int check_chars(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!(std::isdigit(input[i])\
		|| input[i] == '.' || input[i] == 'f'\
		|| input[i] == '+' || input[i] == '-'))
			return (1);
	}
	return (0);
}

int check_special_chars(const std::string &input)
{
	int count_f = 0;
	int count_point = 0;
	for(size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == 'f')
			count_f++;
		else if (input[i] == '.')
			count_point++;
	}
	if ((!count_f || count_f == 1) \
	&& (count_point == 1 || !count_point))
		return (0);
	return (1);
}

int minus_plus(const std::string &input)
{
	int count = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == '+' || input[i] == '-')
			count++;
	}
	if ((input[0] == '-' || input[0] == '+') && count == 1)
		return (0);
	if ((input[0] == '-' || input[0] == '+') && count > 1)
		return (1);
	else if ((input[0] != '+' || input[0] != '-') && count >= 1)
		return (1);
	return (0);
}

int number_syntax(const std::string &input)
{
	size_t  i = 0;

	if (input[0] == '+' || input[0] == '-')
		i++;
	for (; i < input.length() && std::isdigit(input[i]); i++) {}
	if (input[i] == 'f')
		return (1);
	if (input[i] == '.')
	{
		if (!std::isdigit(input[i + 1]))
			return (1);
		for (i++; i < input.length() && std::isdigit(input[i]); i++) {}
		if (input[i] == 'f' && input[i + 1] != '\0')
			return (1);
	}
	return  (0);
}
