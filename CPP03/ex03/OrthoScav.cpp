/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoScav.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:01:38 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 17:43:54 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_name = "D-ScavTrap";
    this->_energy = 50;
    std::cout << "\033[34m Default ScavTrap: " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->_name = name;
    this->_energy = 50;
    std::cout << "\033[34m ScavTrap: " << _name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    this->_name = copy._name;
    this->_hit_points = copy._hit_points;
    this->_energy = copy._energy;
    this->_damage = copy._damage;
    std::cout << "\033[34m Copy ScavTrap: " << _name << " has been created" << std::endl; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy = copy._energy;
        this->_damage = copy._damage;
    }
    std::cout << "\033[37m Assignment ScavTrap for: " << _name << " has been called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[34m ScavTrap: " << _name << " has been destroyed" << std::endl;
}
