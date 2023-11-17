/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:17:37 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 09:59:20 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/******** Orthodox Form    ****************/

Form::Form() 
    : _name("D-Form"), _signed(false),
    _sign(1), _execute(1) {}

Form::Form(const std::string& name, const int& sign, const int &execute)
    : _name(name),_signed(false),
    _sign(sign), _execute(execute)
{
    if (sign < 1 || execute < 1)
        throw GradeTooHighException();
    if (sign > 150 || execute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy) 
    : _name(copy._name), _signed(copy._signed)
    , _sign(copy._sign), _execute(copy._execute) {}

Form& Form::operator=(const Form &copy)
{
    if (this != &copy)
        this->_signed = copy._signed;
    return (*this);
}

Form::~Form() {}

/**************  Getters *********************/

const std::string&  Form::getName() const
{
    return (this->_name);
}

int          Form::getSigned() const
{
    return (this->_signed);
}

int          Form::getSign() const
{
    return (this->_sign);
}

int          Form::getExecute() const
{
    return (this->_execute);
}

/********** Operator<< ****************************/

std::ostream&   operator<<(std::ostream &out, const Form &ob)
{
    out << "Form: " << ob.getName() << std::endl;
    out << "Signed? (0 for no, 1 for yes): " << ob.getSigned() << std::endl;
    out << "Grade to sign: " << ob.getSign() << std::endl;
    out << "Grade to execute: " << ob.getExecute() << std::endl;
    return (out);
}

/**************** Exception classes *****************/

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high exception");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low exception");
}

/************* Should sign or not *****************************/

void    Form::beSigned(const Bureaucrat& ob)
{
    if (ob.getGrade() > this->_sign)
        throw GradeTooLowException();
    this->_signed = true;
}
