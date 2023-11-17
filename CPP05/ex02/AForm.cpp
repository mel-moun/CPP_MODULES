/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:17:37 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 09:59:44 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/******** Orthodox Form    ****************/

AForm::AForm() 
    : _name("D-AForm"), _signed(false),
    _sign(1), _execute(1) {}

AForm::AForm(const std::string& name, const int& sign, const int &execute)
    : _name(name),_signed(false),
    _sign(sign), _execute(execute)
{
    if (sign < 1 || execute < 1)
        throw GradeTooHighException();
    if (sign > 150 || execute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) 
    : _name(copy._name), _signed(copy._signed)
    , _sign(copy._sign), _execute(copy._execute) {}

AForm& AForm::operator=(const AForm &copy)
{
    if (this != &copy)
        this->_signed = copy._signed;
    return (*this);
}

AForm::~AForm() {}

/**************  Getters *********************/

const std::string&  AForm::getName() const
{
    return (this->_name);
}

int          AForm::getSigned() const
{
    return (this->_signed);
}

int          AForm::getSign() const
{
    return (this->_sign);
}

int          AForm::getExecute() const
{
    return (this->_execute);
}

/********** Operator<< ****************************/

std::ostream&   operator<<(std::ostream &out, const AForm &ob)
{
    out << "AForm: " << ob.getName() << std::endl;
    out << "Signed? (0 for no, 1 for yes): " << ob.getSigned() << std::endl;
    out << "Grade to sign: " << ob.getSign() << std::endl;
    out << "Grade to execute: " << ob.getExecute() << std::endl;
    return (out);
}

/**************** Exception classes *****************/

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high exception");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low exception");
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed");
}

/************* Should sign or not *****************************/

void    AForm::beSigned(const Bureaucrat& ob)
{
    if (ob.getGrade() > this->_sign)
        throw GradeTooLowException();
    this->_signed = true;
}
