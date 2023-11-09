/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:35:08 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 14:30:07 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int     Fixed::getRawBits(void) const
{
    return (_fixed);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}
