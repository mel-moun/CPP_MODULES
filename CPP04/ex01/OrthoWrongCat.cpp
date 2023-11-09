/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoWrongCat.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:27:27 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 11:34:50 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "\033[34m WrongCat: " << type << " has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	this->type = copy.getType();
	std::cout << "\033[34m Copy WrongCat: " << type << " has been created" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &copy)
{
	if (this != &copy)
		this->type = copy.getType();
	std::cout << "\033[34m Assignment WrongCat for: " << type << " has been called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "\033[34m WrongCat: " << type << " has been destroyed" << std::endl;
}
