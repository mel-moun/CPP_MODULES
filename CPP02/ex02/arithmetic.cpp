/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:52:04 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 14:42:16 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed Fixed::operator+(const Fixed &b) const
{
    return (Fixed(toFloat() + b.toFloat()));
}

Fixed Fixed::operator-(const Fixed &b) const
{
    return (Fixed(toFloat() - b.toFloat()));
}

Fixed Fixed::operator*(const Fixed &b) const
{
    return (Fixed(toFloat() * b.toFloat()));
}

Fixed Fixed::operator/(const Fixed &b) const
{
    return (Fixed(toFloat() / b.toFloat()));
}