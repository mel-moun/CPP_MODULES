/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:56:41 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 10:57:58 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name):_name(name)
{
    
}

Zombie::~Zombie()
{
    std::cout << "Zombie: " << this->_name << " has been destroyed" << std::endl;   
}

void	Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie():_name("")
{
    
}

void	Zombie::set_name(std::string name)
{
    _name = name;
}