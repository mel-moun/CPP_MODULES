/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:14 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 10:14:07 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "\033[36m Dog: " << type << " has been created" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->type = copy.getType();
	std::cout << "\033[36m Copy Dog: " << type << " has been created" << std::endl;
}

Dog&	Dog::operator=(const Dog& copy)
{
	if (this != &copy)
		this->type = copy.type;
	std::cout << "\033[36m Assignment Dog for: " << type << " has been called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "\033[36m Dog: " << type << " has been destroyed" << std::endl;
}
