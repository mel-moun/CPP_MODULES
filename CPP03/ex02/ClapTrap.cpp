/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 11:54:02 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string& target)
{
    if (_hit_points > 0 && _energy > 0)
    {
        _energy--;
        std::cout << "\033[37m ClapTrap: " << _name << " attacks: " << target << " causing: " << _damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "\033[37m ClapTrap: " << _name << " couldn't attack ! 💀" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hit_points >= amount && _hit_points > 0)
    {
        _hit_points -= amount;
        std::cout << "\033[37m Target: " << _name << " lost this amount of hit points: " << amount << std::endl;
    }
    else
    {
        std::cout << "\033[37m Target: " << _name << " is dead! 💀" << std::endl;
        _hit_points = 0;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hit_points > 0 && _energy > 0)
    {
        _hit_points += amount;
        _energy--;
        std::cout << "\033[37m ClapTrap: " << _name << " repaired this amount of hit points! " << amount << std::endl;
    }
    else
        std::cout << "\033[37m ClapTrap: " << _name << " is dead" << std::endl;
}
