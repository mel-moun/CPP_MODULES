/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:35:20 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 17:58:39 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

const int Fixed::_frac = 8;

int main()
{
    Point A(2, 1), B(4, 6), C(6, 1), P(4, 2);

    if (!bsp(A, B, C, P))
        std::cout << "P is outside the triangle" << std::endl;
    else
        std::cout << "P is inside the triangle" << std::endl;
}