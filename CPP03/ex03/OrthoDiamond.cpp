/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OrthoDiamond.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:36:12 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 17:45:09 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("D-DiamondTrap_clap_name"), FragTrap("D-DiamondTrap"), ScavTrap("D-DiamondTrap")
    , _name("D-DiamondTrap")
{
    ClapTrap::_name = "D-DiamondTrap_clap_name";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy = ScavTrap::_energy;
    this->_damage = FragTrap::_damage;
    std::cout << "\e[35m Default DiamondTrap: " << _name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name),
    _name(name)
{
    ClapTrap::_name = name + "_clap_name";
    this->_hit_points = FragTrap::_hit_points;
    this->_energy = ScavTrap::_energy;
    this->_damage = FragTrap::_damage;
    std::cout << "\e[35m Diamond: " << _name << " has been created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
    : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
    this->_name = copy._name;
    this->_hit_points = copy._hit_points;
    this->_energy = copy._energy;
    this->_damage = copy._damage;
    std::cout << "\e[35m Copy Diamond: " << _name << " has been created" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copy)
{
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hit_points = copy._hit_points;
        this->_energy = copy._energy;
        this->_damage = copy._damage;
    }
    std::cout << "\e[35m Assignmemt Diamond for: " << _name << " has been called" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\e[35m Diamond: " << _name << " has been destroyed" << std::endl;
}