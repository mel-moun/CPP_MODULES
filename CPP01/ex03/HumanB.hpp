/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:08:16 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/19 18:42:05 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB 
{
private:
    std::string _name;
    Weapon      *_weaponB;

public:
    HumanB(const std::string &name);
    ~HumanB();
    void    attack();
    void    setWeapon(Weapon &w);
};

#endif