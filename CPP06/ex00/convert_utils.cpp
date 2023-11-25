/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:00:15 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 17:39:00 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int		impossible(const std::string &input)
{
	if (std::strtod(input.c_str(), NULL) > INT_MAX
	|| std::strtod(input.c_str(), NULL) < INT_MIN)
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return (1);
	}
	return (0);
}

void	display_char(int i, char c)
{
	if ((i >= 0 && i <= 31) || i == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (i >= 32 && i <= 126)
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void	display_int(vars *all)
{
	std::cout << "int: " << all->i << std::endl;
}

void    display_float(vars *all, const std::string &input)
{
	all->f_i = static_cast<int>(std::strtod(input.c_str(), NULL));
	all->diff = all->f - static_cast<float>(all->f_i);
	if (all->diff == 0)
		std::cout << "float: "  << all->f << ".0f" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(2) << all->f <<  "f" << std::endl;
}

void	display_double(vars *all, const std::string &input)
{
	all->d_i = static_cast<int>(std::strtod(input.c_str(), NULL));
	all->diff1 = all->d - static_cast<double>(all->d_i);
	if (all->diff1 == 0)
		std::cout << "double: "  << all->d << ".0" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(2) << all->d << std::endl;
}

void	display_converted(vars *all, const std::string &input)
{
	display_char(all->i, all->c);
	if (impossible(input))
		return ;
	display_int(all);
	display_float(all, input);
	display_double(all, input);
}
