/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:19:03 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 16:10:19 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\033[0m " <<  j->getType() << " " << std::endl;
    std::cout << "\033[0m " << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    std::cout << "----------------- Wrong Animals ----------------------------------"<< std::endl;

    const WrongAnimal* jj = new WrongAnimal();
    const WrongAnimal* ii = new WrongCat();

    std::cout << "\033[0m " << jj->getType() << " " << std::endl;
    std::cout << "\033[0m " << ii->getType() << " " << std::endl;
    
    ii->makeSound();
    jj->makeSound();

    delete jj;
    delete ii;
}
