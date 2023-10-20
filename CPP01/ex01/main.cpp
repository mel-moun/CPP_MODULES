/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:56:25 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 16:51:12 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie  *a_lot = zombieHorde(5, "mel-moun");
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Zombie: " <<  i + 1 << " ";
        a_lot[i].announce();
    }
    delete[] a_lot;
}