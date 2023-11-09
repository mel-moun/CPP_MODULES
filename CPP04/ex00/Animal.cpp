/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:04:32 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 10:09:17 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

const std::string&	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << "\033[37m Sound from Animal 🎠 \033[37m" << std::endl;
}
