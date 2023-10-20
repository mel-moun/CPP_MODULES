/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:08:31 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 18:39:35 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
    std::string _type;

public:
    Weapon();
    Weapon(const std::string &name);
    ~Weapon();
    const   std::string& getType()const;
    void    setType(const std::string &name);
};

#endif