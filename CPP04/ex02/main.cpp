/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:19:03 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/07 10:44:50 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main()
{
    const   Animal* j = new Dog();
    const   Animal* meta = new Cat();

    j->makeSound();
    meta->makeSound();

    delete j;
    delete meta;

    std::cout << "----------------------------------" << std::endl;

    int     size = 3;
    int     ii = 0;
    const   Animal* array[size];

    for (; ii < size / 2; ii++)
        array[ii] = new Dog;

    for (; ii < size; ii++)
        array[ii] = new Cat;

    for (int i = 0; i < size; i++)
        std::cout << "\033[0m " << array[i]->getType() << std::endl;

    for (int i = 0; i < size; i++)
        array[i]->makeSound();

    for (int i = 0; i < size; i++)
        delete array[i];
}
