/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:56:25 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 16:47:15 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *zombie = newZombie("mel-moun");
    zombie->announce();

    randomChump("Meriem");

    Zombie  another("l-zombie");
    another.announce();

    delete zombie;
}
