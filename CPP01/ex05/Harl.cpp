/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:57:03 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 12:12:04 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug(void)
{
    std::cout << "DEBUG FUNCTION" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO FUNCTION" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING FUNCTION" << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR FUNCTION" << std::endl;
}

void    Harl::complain(std::string level)
{
    Harl        ob;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*all[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            (ob.*all[i])();
    }
}