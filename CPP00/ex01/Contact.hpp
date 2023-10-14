/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:58:42 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/12 11:06:06 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBook.hpp"
#include <iostream>

class Contact
{
private:
    std::string _first_name;
    std::string _last_name;
    std::string _phone;
    std::string _nickname;
    std::string _darkest_secret;

public:
	Contact create_contact();
    void    show_contact(int i);
    void    show();
    int     not_empty();
    Contact();
    ~Contact();
};

#endif