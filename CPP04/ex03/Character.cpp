/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:29:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 11:43:09 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("D-Character")
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_uninventory[i] = NULL;
	}
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_uninventory[i] = NULL;
	}
}

Character::Character(const Character &copy) : _name(copy._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
		if (copy._uninventory[i])
			this->_uninventory[i] = copy._uninventory[i]->clone();
		else
			this->_uninventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
			if (this->_uninventory[i])
				delete this->_uninventory[i];
			if (copy._uninventory[i])
				this->_uninventory[i] = copy._uninventory[i]->clone();
			else
				this->_uninventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character() 
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (this->_uninventory[i])
			delete this->_uninventory[i];
	}
}

std::string const&	Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->_uninventory[idx])
			{
				this->_uninventory[idx] = this->_inventory[idx];
				this->_inventory[idx] = NULL;
				return ;
			}
		}
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
