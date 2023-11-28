/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:06:09 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 17:47:33 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
    ScalarConverter();

public:
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter& operator=(const ScalarConverter &copy);
    ~ScalarConverter();
    static void convert(const std::string& input);
};

#endif
