/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:04:32 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 12:09:46 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    Intern& operator=(const Intern &copy);
    ~Intern();

    AForm*  makeForm(const std::string &name, const std::string &target);
    AForm*  shrubbery(const std::string &target);
    AForm*  robotomy(const std::string &target);
    AForm*  presidential(const std::string &target);
};

#endif
