/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:24:39 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 11:07:31 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat              bureaucrat("socrate", 2);
        ShrubberyCreationForm   shru("shruru");
        RobotomyRequestForm     robot("robot");
        PresidentialPardonForm  mr_president("monsieur");
        AForm*  sons[3] = {&shru, &robot, &mr_president};

        for (int i = 0; i < 3; i++)
        {
            sons[i]->beSigned(bureaucrat);
            sons[i]->execute(bureaucrat);
        }

        std::cout << "---------------------------------------------------------" << std::endl;

        Bureaucrat  ob("apaah", 6);
        mr_president.beSigned(ob);
        ob.executeForm(mr_president);

        std::cout << "---------------------------------------------------------" << std::endl;

        Bureaucrat              ob1("another", 3);
        PresidentialPardonForm  president;
        ob1.executeForm(president);
        president.beSigned(ob1);
        ob1.executeForm(president);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
