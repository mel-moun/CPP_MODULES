/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:24:39 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 12:31:46 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern      nerd;
    const int   size = 4;
    AForm       *forms[size];

    for (int i = 0; i < size; i++)
        forms[i] = NULL;

    std::string types[4] = {"shrubbery creation", "robotomy request", "presidential pardon", "nothing"};
    std::string names[4] = {"strawberry", "alien", "mr_president", "nothing"};

    try
    {
        Bureaucrat ob("freud", 2);
        for (int i = 0; i < 4; i++)
        {
            forms[i] = nerd.makeForm(types[i], names[i]);
            forms[i]->beSigned(ob);
            forms[i]->execute(ob);
        }
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "Please enter one of those types: ";
        std::cout << "presidential pardon || robotomy request || shrubbery creation" << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        if (forms[i])
            delete forms[i];
    }
}
