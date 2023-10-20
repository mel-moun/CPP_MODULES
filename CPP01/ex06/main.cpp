/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:57:05 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 18:28:37 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Please enter one level: DEBUG, INFO, WARNING or ERROR" << std::endl;
        return (1);
    }
    std::string level = av[1];
    Harl        ob;

    ob.complain(level);
}