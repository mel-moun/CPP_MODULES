/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:37:06 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 13:37:07 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():_x(0),_y(0){}

Point::~Point(){}

Point::Point(const Fixed x, const Fixed y):_x(x), _y(y){}

Point::Point(const Point &copy):_x(copy._x), _y(copy._y){}

Point& Point::operator=(const Point &copy)
{
    if (this != &copy)
    {
        *this = copy;
    }
    return (*this);
}

const Fixed& Point::get_X()const
{
    return (this->_x);
}

const Fixed& Point::get_Y()const
{
    return (this->_y);
}