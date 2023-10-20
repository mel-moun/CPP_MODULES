/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:47:11 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 16:52:52 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie*  zombies = new Zombie[N];

    for (int i =0; i < N; i++)
    {
        zombies[i].set_name(name);
    }
    return (zombies);
}
