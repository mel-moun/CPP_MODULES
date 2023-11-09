/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:29:35 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/06 17:06:35 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string	_name;
	AMateria	*_inventory[4];
	AMateria	*_uninventory[4];

public:
	Character();
	Character(const std::string &name);
	Character(const Character &copy);
	Character&	operator=(const Character &copy);
	~Character();

    std::string const&	getName() const;

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};

#endif
