/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:13:31 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 13:46:47 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "Enter please at least two numbers to sort them" << std::endl;
	else
	{
		try
		{
			is_input_valid(av, ac);
			print_args(av);
			PmergeMe ob;
			ob.FordJohsonVector(av, ac);
			ob.FordJohsonList(av, ac);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
