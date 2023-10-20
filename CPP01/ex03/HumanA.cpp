/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:39:29 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 11:41:27 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &A):_name(name), _weaponA(A)
{
    
}

HumanA::~HumanA()
{
    
}

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weaponA.getType() << std::endl;
}
