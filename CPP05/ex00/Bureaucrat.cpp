/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:24:35 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 09:46:16 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/************** Orthodox Form    ******************/

Bureaucrat::Bureaucrat() : _name("D-Bureaucrat"), _range(1) {}

Bureaucrat::Bureaucrat(const std::string &name, const int &range) : _name(name)
{
    if (range < 1)
        throw GradeTooHighException();
    if (range > 150)
        throw GradeTooLowException();
    this->_range = range;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _range(copy._range) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
        this->_range = copy._range;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

/************** Getters **************************/

const std::string&  Bureaucrat::getName() const
{
    return (this->_name);
}

const int&          Bureaucrat::getGrade() const
{
    return (this->_range);
}

/**************** Operator<<    ************************/

std::ostream&   operator<<(std::ostream &out, const Bureaucrat& a)
{
    out << a.getName() << ", bureaucrat grade " << a.getGrade() << std::endl;
    return (out);
}

/************** Increment / Decrement ***********************/

void    Bureaucrat::increment()
{
    if (this->_range == 1)
        throw GradeTooHighException();
    this->_range--;
}

void    Bureaucrat::decrement()
{
    if (this->_range == 150)
        throw GradeTooLowException();
    this->_range++;
}

/*************** Exception classes **********/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}
