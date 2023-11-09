/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:29:42 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 10:36:30 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void    ScavTrap::guardGate()
{
    std::cout << "\033[34m ScavTrap: " << _name << " is now in Gate keeper mode." << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (_hit_points > 0 && _energy > 0)
    {
        _energy--;
        std::cout << "\033[34m ScavTrap: " << _name << " attacks: " << target << " causing: " << _damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "\033[34m ScavTrap: " << _name << " couldn't attack ! 💀" << std::endl;
}
