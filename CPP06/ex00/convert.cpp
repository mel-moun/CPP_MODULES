/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:32:47 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 15:24:30 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Utils.hpp"

void	was_unkown()
{
	std::cout << "Unkown Type" << std::endl;
}

void	was_char(const std::string &input)
{
	vars	all;
	all.c = input[0];
	all.i = static_cast<int>(all.c);
	all.f = static_cast<float>(all.c);
	all.d = static_cast<double>(all.c);

	if (all.c >= '0' && all.c <= '9')
	{
		std::cout << "char: Non displayable" << std::endl;
		all.i -= 48;
		all.f -= 48;
		all.d -= 48;
	}
	else
		std::cout << "char: \'" << all.c << "\'" << std::endl;
	std::cout << "int: " << all.i << std::endl;
	std::cout << "float: " << all.f << ".0f" << std::endl;
	std::cout << "double: " << all.d << ".0" << std::endl;
}

void	was_int(const std::string &input, vars *all)
{
	all->i = static_cast<int>(std::strtod(input.c_str(), NULL));
	all->c = static_cast<char>(all->i);
	all->f = static_cast<float>(all->i);
	all->d = static_cast<double>(all->i);
}

void	was_float(const std::string &input, vars *all)
{
	all->f = static_cast<float>(std::strtod(input.c_str(), NULL));
	all->c = static_cast<char>(all->f);
	all->i = static_cast<int>(all->f);
	all->d = static_cast<double>(all->f);
}

void	was_double(const std::string &input, vars *all)
{
	all->d = std::strtod(input.c_str(), NULL);
	all->c = static_cast<char>(all->d);
	all->i = static_cast<int>(all->d);
	all->f = static_cast<float>(all->d);
}
