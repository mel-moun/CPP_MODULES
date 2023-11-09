/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:09:08 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 11:11:41 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "\033[37m Animal: " << type << " has been created" << std::endl;
}

Animal::Animal(const Animal &copy) : type(copy.type)
{
    std::cout << "\033[37m Copy Animal: " << type << " has been created" << std::endl;
}

Animal& Animal::operator=(const Animal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    std::cout << "\033[37m Assignment Animal for: " << type << " has been called" << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "\033[37m Animal: " << type << " has been destroyed" << std::endl;
}
