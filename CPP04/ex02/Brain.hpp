/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:43:17 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 15:11:48 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class   Brain
{
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &copy);
    Brain&  operator=(const Brain& copy);
    ~Brain();
};

#endif
