/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:52:29 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/14 16:22:36 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>

class Span
{
private:
	unsigned int    _N;
	std::list<int>  _list;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &copy);
	Span& operator=(const Span &copy);
	~Span();
	
	void    addNumber(int i);
	const   std::list<int>& getList()const;

	int     shortestSpan();
	int     longestSpan();

	void    addNumber(std::list<int>::iterator begin, std::list<int>::iterator end);
};

std::ostream&   operator<<(std::ostream& out, const Span &ob);

#endif
