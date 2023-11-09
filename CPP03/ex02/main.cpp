/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:43:33 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/02 11:55:16 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap    p1("Robot");
    ScavTrap    p2("Demon");

    p1.attack("Demon");
    p2.takeDamage(90);
    p2.attack("Robot");
    p1.takeDamage(110);
    p2.beRepaired(250);
    p1.beRepaired(15);
}
