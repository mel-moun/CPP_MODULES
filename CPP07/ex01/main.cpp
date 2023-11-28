/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:26:09 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 17:12:00 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data		data;
	uintptr_t	ptr = Serializer::serialize(&data);
	Data		*pointer = Serializer::deserialize(ptr);

	if (pointer == &data)
		std::cout << "Serialization was successfull" << std::endl;
	else
		std::cout << "Serialization wasn't successfull" << std::endl;

	std::cout << data;
	pointer->setName("MERIEM");
	std::cout << data;
}
