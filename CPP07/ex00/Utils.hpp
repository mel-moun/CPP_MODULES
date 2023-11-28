/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:02:08 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 17:38:53 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <iomanip>
#include <sstream>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERALS,
	NONE,
};

struct vars
{
	int     i;
	char    c;
	float   f;
	double  d;
	int     f_i;
	float   diff;
	int		d_i;
	double  diff1;
};

// Check Errors
int		unkown_type(const std::string &input);
int		check_chars(const std::string &input);
int		check_special_chars(const std::string &input);
int		minus_plus(const std::string &input);
int		number_syntax(const std::string &input);

// Type of input detector
int		exacte_type(const std::string &input);
int		is_literal(const std::string& input);
int		is_char(const std::string &input);
int		is_int(const std::string &input);
int		is_float(const std::string &input);

// Converting one type to others
void	was_unkown();
void	was_literal(const std::string& input);
void	was_char(const std::string &input);
void	was_int(const std::string &input, vars *all);
void	was_float(const std::string &input, vars *all);
void	was_double(const std::string &input, vars *all);

// Displaying after convert
void	display_converted(vars *all, const std::string &input);
void	display_char(int i, char c);
void	display_int(vars *all);
void    display_float(vars *all, const std::string &input);
void	display_double(vars *all, const std::string &input);

// Impossible
int		impossible(const std::string &input);

#endif
