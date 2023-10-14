/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:58:49 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/14 09:58:22 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void  PhoneBook::add_contact(int index)
{
    Contact contact;

    _array[index] = contact.create_contact();
}

int only_num(const std::string& str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return (1);
    }
    return (0);
}

void    PhoneBook::search(PhoneBook all)
{
    std::string         str;
    std::istringstream  iss;
    int                 index;

    if (!all._array[0].not_empty())
    {
        std::cout << std::setw(10) << "Index " << "|" \
        << "First Name" << "|" << std::setw(10) << "Last Name" << "|"\
        << std::setw(10) << "Nickname" << std::endl;
        for (int i = 0; i < 8 && !all._array[i].not_empty(); i++)
        {
            all._array[i].show_contact(i);
        }
        std::cout << "Please enter an index: ";
        std::getline(std::cin, str);
        iss.str(str);
        iss >> index;
        if (only_num(str) || !(index >= 1 && index <= 8))
        {
            std::cout << "INVALID INDEX" << std::endl;
            return;
        }
        if (!all._array[index - 1].not_empty())
            all._array[index - 1].show();
        else
            std::cout << "An empty contact can not be displayed" << std::endl;
    }
    else
        std::cout << "An empty phonebook can not be displayed" << std::endl;
}

PhoneBook::PhoneBook()
{
    for (int i = 0; i < 8; i++)
    {
        _array[i] = Contact();
    }
}

PhoneBook::~PhoneBook()
{
    
}