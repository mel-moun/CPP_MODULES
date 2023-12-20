/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:52:27 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/15 17:06:14 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "--------- TEST ONE ------------" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "--------- TEST TWO ------------" << std::endl;

		int            arr[6] = {1337, 42, 31, 4, 34, 65};
		std::list<int> another(6);
		std::copy(arr, arr + 6, another.begin());
		Span span(5);
		span.addNumber(75);
		span.addNumber(another.begin(), another.end());
		std::cout << span;
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
		span.addNumber(34);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
