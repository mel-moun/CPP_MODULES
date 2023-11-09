/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:53 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/03 16:14:20 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->cat_brain = new Brain;
	std::cout << "\033[34m Cat: " << type << " has been created" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->type = copy.getType();
	this->cat_brain = new Brain(*copy.cat_brain);
	std::cout << "\033[34m Copy Cat: " << type << " has been created" << std::endl;
}

Cat&	Cat::operator=(const Cat &copy)
{
	if (this != &copy)
	{
		this->type = copy.getType();
		delete cat_brain;
		this->cat_brain = new Brain(*copy.cat_brain);
	}
	std::cout << "\033[34m Assignment Cat for: " << type << " has been called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete cat_brain;
	std::cout << "\033[34m Cat: " << type << " has been destroyed" << std::endl;
}
