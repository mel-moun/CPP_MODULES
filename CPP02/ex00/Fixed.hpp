/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:50:27 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 17:59:04 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _fixed;
    static const int   _frac;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &copy);
    Fixed& operator=(const Fixed &copy);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif