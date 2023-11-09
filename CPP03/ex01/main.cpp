/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:33 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 11:07:43 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap    p1("meriem");
    ScavTrap    p2("mel-moun");

    p1.attack("mel-moun");
    p2.takeDamage(15);
    p2.attack("meriem");
    p1.takeDamage(37);
    p1.beRepaired(24);
    p2.beRepaired(12);
}
