/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:53:35 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/23 13:01:01 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/**************** Orthodox Canonical form *********************/

Data::Data() : _name("mel-moun") {}

Data::Data(const Data& copy) : _name(copy._name) {}

Data&   Data::operator=(const Data &copy)
{
	if (this != &copy)
		this->_name = copy.getName();
	return (*this);
}

Data::~Data(){}

/************** Getter and Setter *****************************/

const std::string&	Data::getName() const
{
	return (this->_name);
}

void	Data::setName(const std::string &change)
{
	this->_name = change;
}

/************** Operator << ***********************************/

std::ostream&	operator<<(std::ostream& out, const Data& obj)
{
	out << "Name: " << obj.getName() << std::endl;
	return (out);
}
