/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:27:36 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 16:13:17 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void    DiamondTrap::whoAmI()
{
    std::cout << "\e[35m Diamond's name: " << _name << " && ClapTrap's name: " << ClapTrap::_name << std::endl;
}