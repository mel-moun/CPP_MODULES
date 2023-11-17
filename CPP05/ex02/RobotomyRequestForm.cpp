/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:35:19 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/15 14:10:07 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/****************** Orthodox Canonical Form ***********************/

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("D-Robot", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
    : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
    if (this != &copy)
        AForm::operator=(copy);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

/********************* It's own  ********************************/

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw(AForm::NotSignedException());

    if (executor.getGrade() > this->getExecute())
        throw(AForm::GradeTooLowException());

    std::cout << "Some drilling noises... 💥" << std::endl;
    std::srand((unsigned int)(std::time(0)));
    int random = rand() % 100;

    if (random % 2 != 0)
        std::cout << this->getName() << " failed robotomism." << std::endl;
    else
        std::cout << this->getName() << " has been robotomized successfully 50\% of the time." << std::endl;
}
