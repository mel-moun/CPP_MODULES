/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:46:37 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/17 13:10:46 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::operator<(const Fixed& b) const
{
    return (toFloat() < b.toFloat());
}

bool Fixed::operator<=(const Fixed& b) const
{
    return (toFloat() <= b.toFloat());
}

bool Fixed::operator>(const Fixed& b) const
{
    return (toFloat() > b.toFloat());
}

bool Fixed::operator>=(const Fixed& b) const
{
    return (toFloat() >= b.toFloat());
}

bool Fixed::operator==(const Fixed& b) const
{
    return (toFloat() == b.toFloat());
}

bool Fixed::operator!=(const Fixed& b) const
{
    return (toFloat() != b.toFloat());
}