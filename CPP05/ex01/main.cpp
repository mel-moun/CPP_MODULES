/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:24:39 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 10:50:38 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b("BureOne", 2);
        Form a("FormOne", 13, 37);
        a.beSigned(b);
        std::cout << a;
        b.signForm(a);
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
