/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:58:51 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/14 11:28:08 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

class PhoneBook
{
private:
	Contact _array[8];

public:
	void		add_contact(int i);
	void    	search(PhoneBook all);
	PhoneBook();
	~PhoneBook();
};

int 		only_num(const std::string& str);
std::string new_contact(const std::string &str);
int			all_spaces(std::string str);
int			all_alpha(std::string str);
std::string new_number(const std::string &str);

#endif