/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:50:27 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/23 18:01:12 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int                 _fixed;
	static const int    _frac;

public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int integer);
	Fixed(const float floating);
	~Fixed();

	Fixed& operator=(const Fixed &copy);
	void    setRawBits(int const raw);
	int     getRawBits(void) const;
	float   toFloat(void) const;
	int     toInt(void) const;

	//Arithmetic
	Fixed   operator+(const Fixed &b) const;
	Fixed   operator-(const Fixed &b) const;
	Fixed   operator*(const Fixed &b) const;
	Fixed   operator/(const Fixed &b) const;

	//Comparison
	bool    operator<(const Fixed& b) const;
	bool    operator<=(const Fixed& b) const;
	bool    operator>(const Fixed& b) const;
	bool    operator>=(const Fixed& b) const;
	bool    operator==(const Fixed& b) const;
	bool    operator!=(const Fixed& b) const;

	//Increment/decrement 
	Fixed&  operator++();//pre ++a
	Fixed&  operator--();
	Fixed   operator++(int);//post a++
	Fixed   operator--(int);

	//Min / Max
	static Fixed& min(Fixed &A, Fixed &B);
	static Fixed& max(Fixed &A, Fixed &B);
	static const Fixed& min(const Fixed &A, const Fixed &B);
	static const Fixed& max(const Fixed &A, const Fixed &B);
};

std::ostream& operator<<(std::ostream &out, Fixed const &n);

#endif