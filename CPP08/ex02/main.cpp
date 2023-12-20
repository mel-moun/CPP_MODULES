/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:12:56 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/15 17:10:34 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
    /****************************** STACK **************************/
    std::cout << "-------------------- STACK -----------------" << std::endl;

    MutantStack<int, std::vector<int> > mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "TOP: " << mstack.top() << std::endl;
    mstack.pop();

    std::cout << "SIZE: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
    MutantStack<int, std::vector<int> >::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int, std::vector<int> > s(mstack);

    /****************************** LIST ***************************/
    std::cout << "-------------------- LIST ------------------" << std::endl;
    std::list<int> list;

    list.push_back(5);
    list.push_back(17);

    std::cout << "TOP: " << list.back() << std::endl;
    list.pop_back();

    std::cout << "SIZE: " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator it_list = list.begin();
    std::list<int>::iterator ite_list = list.end();

    ++it_list;
    --it_list;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }
    std::list<int> s_list(list);

    /****************************** REVERSE STACK ITERATOR *********/
    std::cout << "------------- CONST REVERSE STACK ITERATOR -" << std::endl;

    MutantStack<int> rmstack;

    rmstack.push(5);
    rmstack.push(17);

    std::cout << "TOP: " << rmstack.top() << std::endl;

    rmstack.pop();

    std::cout << "SIZE: " << rmstack.size() << std::endl;
    rmstack.push(3);
    rmstack.push(5);
    rmstack.push(737);
    rmstack.push(0);
    MutantStack<int>::const_reverse_iterator rit = rmstack.rbegin();
    MutantStack<int>::const_reverse_iterator rite = rmstack.rend();

    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    return 0;
}
