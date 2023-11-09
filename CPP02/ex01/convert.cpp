/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:34:57 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/17 08:57:01 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

float Fixed::toFloat(void) const
{
    return ((float) getRawBits() / (1 << _frac));
}

int Fixed::toInt(void) const
{
    return (getRawBits() / (1 << _frac));
}

std::ostream& operator<<(std::ostream &out, Fixed const &n)
{
    out << n.toFloat();
    return (out);
}