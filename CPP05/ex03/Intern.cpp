/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:08:02 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 12:34:57 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*********** Orthodox Canonical Form *****************/

Intern::Intern() {}

Intern::Intern(const Intern &copy)
{
    *this = copy;
}

Intern& Intern::operator=(const Intern &copy)
{
    if (this != &copy)
        return (*this);
    return (*this);
}
    
Intern::~Intern(){}

/*************  It's own *********************/

AForm*  Intern::shrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::robotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::presidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(const std::string &name, const std::string &target)
{
    int         i;
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*ptr[3])(const std::string&) = {&Intern::shrubbery, &Intern::robotomy, &Intern::presidential};

    for (i = 0; i < 3 && name != names[i]; i++) {}

    if (i == 3)
        throw(NULL);
    
    for (i = 0; i < 3; i++)
    {
        if (names[i] == name)
        {
            std::cout << "Intern creates " << target << std::endl;
            return (this->*ptr[i])(target);
        }
    }
    return (NULL);
}
