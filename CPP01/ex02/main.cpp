/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:01:17 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 15:05:26 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *stringPTR = &name;
    std::string &stringREF=name;

    std::cout << "Address of name: " << &name << std::endl; 
    std::cout << "Address of stringPTR: " << stringPTR << std::endl; 
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    std::cout << "Value of name: " << name << std::endl; 
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl; 
    std::cout << "Value of stringREF: " << stringREF << std::endl;
}