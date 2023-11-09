/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:53 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 10:13:54 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "\033[34m Cat: " << type << " has been created" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	this->type = copy.getType();
	std::cout << "\033[34m Copy Cat: " << type << " has been created" << std::endl;
}

Cat&	Cat::operator=(const Cat &copy)
{
	if (this != &copy)
		this->type = copy.getType();
	std::cout << "\033[34m Assignment Cat for: " << type << " has been called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "\033[34m Cat: " << type << " has been destroyed" << std::endl;
}
