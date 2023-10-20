/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:09:55 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 11:38:56 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon():_type("Default")
{

}

Weapon::~Weapon()
{
   
}

Weapon::Weapon(const std::string &name):_type(name)
{

}

const std::string& Weapon::getType()const
{
    return (_type);
}

void    Weapon::setType(const std::string &name)
{
    this->_type = name;
}
