/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:24:39 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/16 10:40:54 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("meriem", 3);
        a.decrement();
        std::cout << a;
        a.increment();
        std::cout << a;
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
