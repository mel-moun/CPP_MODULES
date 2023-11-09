/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:14 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/03 16:17:38 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->dog_brain = new Brain;
	std::cout << "\033[36m Dog: " << type << " has been created" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->type = copy.getType();
	this->dog_brain = new Brain;
	std::cout << "\033[36m Copy Dog: " << type << " has been created" << std::endl;
}

Dog&	Dog::operator=(const Dog& copy)
{
	if (this != &copy)
	{
		this->type = copy.type;
		delete dog_brain;
		dog_brain = new Brain(*copy.dog_brain);
	}
	std::cout << "\033[36m Assignment Dog for: " << type << " has been called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete dog_brain;
	std::cout << "\033[36m Dog: " << type << " has been destroyed" << std::endl;
}
