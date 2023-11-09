/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:46:55 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 15:11:55 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "D-Brain";
    std::cout << "\e[35m Brain has been created" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = copy.ideas[i];
    std::cout << "\e[35m Copy Brain has been created" << std::endl;
}

Brain&  Brain::operator=(const Brain& copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    std::cout << "\e[35m Assignment Brain has been called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "\e[35m Brain has been destroyed" << std::endl;
}
