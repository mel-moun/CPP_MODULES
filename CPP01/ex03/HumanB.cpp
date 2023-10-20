/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:56:47 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 11:42:39 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name):_name(name)
{
    _weaponB = NULL;
}

HumanB::~HumanB()
{
    
}

void    HumanB::attack()
{
    if (_weaponB)
        std::cout << this->_name << " attacks with their " << this->_weaponB->getType() << std::endl;
    else
        std::cout << this->_name << " attacks with their " << std::endl;
}

void    HumanB::setWeapon(Weapon &w)
{
    this->_weaponB = &w;
}