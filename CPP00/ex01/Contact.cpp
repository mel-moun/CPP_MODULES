/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:58:40 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/14 12:08:10 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int all_spaces(std::string str)
{
    int i;

    for (i = 0; str[i] && (str[i] == ' ' || str[i] == '\t'); i++){}
    if (str[i] == '\0')
        return (1);
    return (0);
}

int all_alpha(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ' && str[i] != '\t')
            return (1);
    }
    return (0);
}

std::string new_contact(const std::string &str)
{
    std::string tmp = "";
    while ((tmp.empty() || all_spaces(tmp)|| all_alpha(tmp)) && !std::cin.eof())
    {
        std::cout << str;
        std::getline(std::cin, tmp);
    }
    return (tmp);
}

std::string new_number(const std::string &str)
{
    std::string tmp = "";
    while ((tmp.empty() || all_spaces(tmp)|| only_num(tmp)) && !std::cin.eof())
    {
        std::cout << str;
        std::getline(std::cin, tmp);
    }
    return (tmp);
}

Contact Contact::create_contact()
{
    Contact add;

    add._first_name = new_contact("First name: ");
    add._last_name = new_contact("Last name: ");
    add._nickname = new_contact("Nickname: ");
    add._phone = new_number("Phone number: ");
    add._darkest_secret = new_contact("Darkest Secret: ");
    return (add);
}

std::string display(const std::string &str)
{
    if (str.size() > 10)
        return (str.substr(0, 9) + ".");
    return (str);   
}

void    Contact::show_contact(int i)
{
    std::cout << std::setw(10) << i + 1 << "|" << std::setw(10) << display(this->_first_name) << "|" << std::setw(10) \
    << display(this->_last_name) << "|" << std::setw(10) << display(this->_nickname) << std::endl;
}

void    Contact::show()
{
    std::cout << "First Name: " << _first_name << std::endl;
    std::cout << "Last Name: " << _last_name << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone Number: " << _phone << std::endl;
    std::cout << "Darkest Secret: " << _darkest_secret << std::endl;  
}

int Contact::not_empty()
{
    if (this->_first_name.empty() && this->_last_name.empty()
    && this->_nickname.empty() && this->_phone.empty()
    && this->_darkest_secret.empty())
        return (1);
    return (0);
}

Contact::Contact(): _first_name(""), _last_name(""), _phone(""), _darkest_secret("")
{
    
}

Contact::~Contact()
{
    
}