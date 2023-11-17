/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:35:25 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/15 14:10:13 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

/***************  Orhotodox Canonical Form   ***************/

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("D-Shrubbery", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
	: AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {}

ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		AForm::operator=(copy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/****************** It's own  ***************************/

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!this->getSigned())
        throw(AForm::NotSignedException());

    if (executor.getGrade() > this->getExecute())
        throw(AForm::GradeTooLowException());

	std::string		name = this->getName() + "_shrubbery";
	std::ofstream	file(name, std::ios::in | std::ios::out | std::ios::trunc);

	if (!file.is_open())
	{
		std::cout << "Problem while opening the file 💀" << std::endl;
		return ;
	}

	file << "                     . . ." << std::endl
	<< "                   .        .  .     ..    ." << std::endl
	<< "                .                 .         .  ." << std::endl
	<< "                                ." << std::endl
	<< "                               .                .." << std::endl
	<< "               .          .            .              ." << std::endl
	<< "               .            '.,        .               ." << std::endl
	<< "               .              'b      *" << std::endl
	<< "                .              '$    #.                .." << std::endl
	<< "               .    .           $:   #:               ." << std::endl
	<< "             ..      .  ..      *#  @ :        .   . ." << std::endl
	<< "                          .     :@,@ :   ,.**:'   ." << std::endl
	<< "              .      .,         :@@*: ..**'      .   ." << std::endl
	<< "                       '#o.    .:@'.@*\"\'  ." << std::endl
	<< "               .  .       \'bq,..:,@@*'   ,*      .  ." << std::endl
	<< "                          ,p$q8,:@ '  .p*'      ." << std::endl
	<< "                   .     '  . '@@Pp@@*'    .  ." << std::endl
	<< "                    .  . ..    Y7'.'     .  ." << std::endl
	<< "                              :@: ." << std::endl
	<< "                             .:@:'." << std::endl
	<< "                           .::@:.   " << std::endl;

	file.close();
}
