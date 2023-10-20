/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:53:00 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 17:12:35 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4 || !av[2][0])
    {
        std::cout << "Please enter 4 arguments" << std::endl;
        return (1);
    }
    std::string name = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    
    std::ifstream file;
    file.open(name, std::ios::in);
    if (!file.is_open())
    {
        std::cout << "File can not be opened" << std::endl;
        return (1);
    }

    std::fstream out;
    out.open(name + ".replace", std::ios::in | std::ios::out | std::ios::trunc);
    if (!out.is_open())
    {
        std::cout << "Failure of the .replace file" << std::endl;
        return (1);
    }

    std::string input;
    while (std::getline(file, input))
    {
        size_t  found = input.find(s1);
        while (found != std::string::npos)
        {
            input.erase(found, s1.length());
            input.insert(found, s2);
            found = input.find(s1, found + s2.length());
        }
        out << input;
        if (!file.eof())
            out << "\n";
    }

    out.close();
    file.close();
}