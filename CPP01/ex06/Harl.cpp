/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:57:03 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 12:15:12 by mel-moun         ###   ########.fr       */
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
    int         i = 0;

    for (i = 0; level != levels[i] && i < 4; i++)
    {
        
    }
    switch (i)
    {
        case 0:
            (ob.*all[0])();
        case 1:
            (ob.*all[1])();
        case 2:
            (ob.*all[2])();
        case 3:
        {
            (ob.*all[3])();
            break;
        }
        default:
            std::cout << "HUH ?" << std::endl;
    }
}