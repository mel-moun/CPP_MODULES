/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:34:21 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 13:36:31 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixed(0){}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::Fixed(const int i): _fixed(i * (1 << _frac)){}

Fixed::Fixed(const float i): _fixed(roundf(i * (1 << _frac))){}

Fixed::~Fixed(){}