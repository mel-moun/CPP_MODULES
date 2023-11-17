/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:17:34 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 09:58:13 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _sign;
    const int           _execute;

public:
    AForm();
    AForm(const std::string& name, const int& sign, const int &execute);
    AForm(const AForm &copy);
    AForm& operator=(const AForm &copy);
    virtual ~AForm();

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

    class NotSignedException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    const std::string&  getName() const;
    int                 getSigned() const;
    int                 getSign() const;
    int                 getExecute() const;

    void            beSigned(const Bureaucrat& ob);
    virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream&   operator<<(std::ostream &out, const AForm &ob);

#endif
