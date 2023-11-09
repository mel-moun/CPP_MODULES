/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:46:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/06 17:41:48 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy._materias[i])
            this->_materias[i] = copy._materias[i];
        else
            this->_materias[i] = NULL;
    }
}

MateriaSource&  MateriaSource::operator=(const MateriaSource &copy)
{
    for (int i = 0; i < 4; i++)
    {
        if (copy._materias[i])
            this->_materias[i] = copy._materias[i];
        else
            this->_materias[i] = NULL;
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i])
            delete this->_materias[i];
    }
}

void        MateriaSource::learnMateria(AMateria* ptr)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = ptr;
            break;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return (this->_materias[i]->clone());
    }
    return (NULL);
}
