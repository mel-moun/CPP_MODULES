/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoFrag.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:13:30 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 17:43:41 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->_name = "D-FragTrap";
    this->_hit_points = 100;
    this->_damage = 30;
    std::cout << "\033[36m Default FragTrap: " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->_name = name;
    this->_hit_points = 100;
    this->_damage = 30;
    std::cout << "\033[36m FragTrap: " << _name << " has been created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    this->_name = copy._name;
    this->_hit_points = copy._hit_points;
    this->_energy = copy._energy;
    this->_damage =  copy._damage;
    std::cout << "\033[36m Copy FragTrap: " << _name << " has been created" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy = copy._energy;
        this->_damage =  copy._damage;
    }
    std::cout << "\033[36m Assignment FragTrap for: " << _name << " has been called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "\033[36m FragTrap: " << _name << " has been destroyed" << std::endl;
}
