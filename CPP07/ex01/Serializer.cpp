/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:48:30 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/22 15:33:28 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**************** Orthodox Canonical form *********************/

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy)
{
	*this = copy;    
}

Serializer& Serializer::operator=(const Serializer& copy)
{
	if (this != &copy)
		return (*this);
	return (*this);
}

Serializer::~Serializer() {}

/**************** It's own ************************************/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
