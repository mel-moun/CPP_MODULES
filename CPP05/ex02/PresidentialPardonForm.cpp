/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:35:14 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/15 13:24:45 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

/*******************   Orthodox Canonical Form *********************/

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("D-President", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
    : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    : AForm(copy) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
    if (this != &copy)
        AForm::operator=(copy);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

/*******************  It's own ********************************/

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw(AForm::NotSignedException());

    if (executor.getGrade() > this->getExecute())
        throw(AForm::GradeTooLowException());

    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
