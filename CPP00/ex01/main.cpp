/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:58:07 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/13 23:01:53 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    std::string input;
    PhoneBook   phonebook;
    int         index;
    
    index = 0;
    if (ac == 1)
    {
        while (!std::cin.eof() && input != "EXIT")
        {
            std::cout << "Please enter ADD, SEARCH or EXIT: ";
            std::getline(std::cin, input);
            if (input == "ADD")
            {
                phonebook.add_contact(index % 8);
                index++;
            }
            else if (input == "SEARCH")
                phonebook.search(phonebook);
        }
    }
    (void)av;
}
