/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:36:12 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 13:36:14 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed abs(const Fixed &some)
{
    if (some < 0)
        return (some * (-1));
    return (some);
}

Fixed area(Point const a, Point const b, Point const c)
{
    return (Fixed(abs((a.get_X()*(b.get_Y()-c.get_Y()) + b.get_X()*(c.get_Y()-a.get_Y())+ c.get_X()*(a.get_Y()-b.get_Y()))/2)));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed ABC = area(a, b, c);
    Fixed APB = area(a, point, b);
    Fixed APC = area(a, point, c);
    Fixed BPC = area(b, point, c);

    if (APB == 0 || APC == 0 || BPC == 0)
        return (0);
    return (ABC == (APB + APC + BPC));
}