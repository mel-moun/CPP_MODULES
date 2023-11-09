/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incre_decrement.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:00:43 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/17 10:21:24 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed&  Fixed::operator++()
{
    _fixed++;
    return (*this);
}

Fixed&  Fixed::operator--()
{
    _fixed--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   tmp(toFloat());

    _fixed++;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed   tmp(toFloat());

    _fixed--;
    return (tmp);
}