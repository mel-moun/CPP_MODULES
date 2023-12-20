/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:09:03 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 11:28:04 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error("Please enter 2 arguments!");
		RPN ob;
		ob.rpn(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}
