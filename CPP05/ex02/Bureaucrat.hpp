/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:24:37 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 09:54:32 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _range;
    
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, const int &range);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat& operator=(const Bureaucrat &copy);
    ~Bureaucrat();

    const std::string&  getName() const;
    const int&          getGrade() const;

    void    increment();
    void    decrement();
    
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException :  public std::exception
    {
        public:
            const char* what() const throw();
    };

    void    signForm(AForm &ob) const;
    void    executeForm(AForm const & form);
};

std::ostream&   operator<<(std::ostream &out, const Bureaucrat& a);

#endif
