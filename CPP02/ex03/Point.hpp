/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:37:12 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 13:37:35 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point();
    Point(const Fixed x, const Fixed y);
    Point(const Point &copy);
    Point& operator=(const Point &copy);
    ~Point();
    const Fixed& get_X()const;
    const Fixed& get_Y()const; 
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);
Fixed   abs(const Fixed &some);
Fixed   area(Point const a, Point const b, Point const c);

#endif