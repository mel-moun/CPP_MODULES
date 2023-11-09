/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:23:21 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 13:35:10 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed& Fixed::min(Fixed &A, Fixed &B)
{
    if (A < B)
        return (A);
    return (B);
}

Fixed& Fixed::max(Fixed &A, Fixed &B)
{
    if (A > B)
        return (A);
    return (B);
}

const Fixed& Fixed::min(const Fixed &A, const Fixed &B)
{
    if (A < B)
        return (A);
    return (B);
}

const Fixed& Fixed::max(const Fixed &A, const Fixed &B)
{
    if (A > B)
        return (A);
    return (B);
}