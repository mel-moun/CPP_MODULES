/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:30:48 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/10 12:24:14 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <class T>
void	easyfind(T& v, int s)
{
	typename T::iterator	it = std::find(v.begin(), v.end(), s);
	if (it == v.end())
		throw (std::runtime_error("No occurence is found"));
	std::cout << "The occurence of: " << *it  << " is found" << std::endl;
}

#endif
