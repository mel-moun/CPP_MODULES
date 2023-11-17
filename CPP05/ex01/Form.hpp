/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:17:34 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 09:56:15 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _sign;
    const int           _execute;

public:
    Form();
    Form(const std::string& name, const int& sign, const int &execute);
    Form(const Form &copy);
    Form& operator=(const Form &copy);
    ~Form();

    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    const std::string&  getName() const;
    int                 getSigned() const;
    int                 getSign() const;
    int                 getExecute() const;

    void    beSigned(const Bureaucrat& ob);
};

std::ostream&   operator<<(std::ostream &out, const Form &ob);

#endif
