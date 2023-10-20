/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:57:05 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 18:27:33 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl ob;

    ob.complain("WARNING");
    ob.complain("INFO");
    ob.complain("ERROR");
    ob.complain("DEBUG");
}