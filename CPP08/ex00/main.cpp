/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:36:55 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/14 16:21:37 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::cout << "--------------- Vector --------------------------" << std::endl;
    int             arr[] = {13, 25, 34, 34, 15};
    std::vector<int> v(arr, arr + 5);
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try 
    {
        easyfind(v, 34);
        easyfind(v, 10);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    v.clear();

    std::cout << "-------------- List -----------------------------" << std::endl;
    int            ar[4] = {1337, 42, 31, 4};
    std::list<int>l(4);
    std::copy(ar, ar + 4, l.begin());
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    try
    {
        easyfind(l, 31);
        easyfind(l, 123);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    l.clear();
}
