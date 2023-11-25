/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:57:51 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/22 16:40:04 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Base_HPP
#define Base_HPP

#include <iostream>

class Base
{
public:
    virtual ~Base();
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
