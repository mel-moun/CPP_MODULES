/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:54:03 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/12 18:32:27 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        std::string str;
        for (int i = 1; av[i]; i++)
        {
            str = av[i];
            for (int j = 0; str[j]; j++)
            {
                std::cout << (char)(toupper(str[j]));
            }
        }
    }
    std::cout << std::endl;
}
