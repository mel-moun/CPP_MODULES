/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:16:10 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 13:53:26 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/***************** Take Input ************************************************/

void	PmergeMe::take_input_list(char **av, int ac)
{
	for (int i = 1; i < ac; i++)
		_list.insert(_list.end(), static_cast<int>(std::strtod(av[i], NULL)));
}

/***************** Print Lists ***********************************************/

void	PmergeMe::print_list(std::list<int>& list)
{
	if (!list.empty())
	{
		std::list<int>::iterator it = list.begin();
		for (; it != list.end(); it++)
		{
			std::cout << *it;
			std::list<int>::iterator it1 = it;
			it1++;
			if (it1 != list.end())
				std::cout << ", ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "List is empty" << std::endl;
}

/***************** Ford-Johnson **********************************************/

void	PmergeMe::FordJohsonList(char **av, int ac)
{
	_size = 1;
	clock_t start, end;
	start = std::clock();
	this->take_input_list(av, ac);
	this->merge_sort_list();
	end = std::clock();
	double final = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 100;
	std::cout << "Time to process a range of " << PmergeMe::size_list() \
	<< " elements with std::list: " << std::setprecision(5) << final << "us" << std::endl;
}

/***************** First Step  ***********************************************/

void	PmergeMe::merge_sort_list()
{
	if (_list.size() == 1)
		return;
	this->create_list_of_lists();
	this->sort_list_of_lists();
	this->copy_to_list(_lls);
	std::list<std::list<int> >::iterator it1 = _lls.begin();
	std::list<std::list<int> >::iterator it2 = _lls.begin();
	std::advance(it2, 1);
	if (it1->size() == _size && it2->size() == _size)
	{
		std::advance(it2, 1);
		std::advance(it1, 3);
		if (it1->size() == _size && it2->size() == _size)
		{
			_lls.clear();
			_size *= 2;
			merge_sort_list();
		}
	}
	_lls.clear();
	this->insert_list();
	_list_main.clear();
	_list_pend.clear();
	_list_rest.clear();
	_size /= 2;
}

void	PmergeMe::create_list_of_lists()
{
	std::list<int> 				tmp;
	std::list<int>::iterator 	it;

	for (size_t i = 0; i < _list.size(); i += _size)
	{
		tmp.clear();
		for (size_t j = 0; j < _size && i + j < _list.size(); j++)
		{
			it = _list.begin();
			std::advance(it, i + j);
			tmp.push_back(*it);
		}
		_lls.push_back(tmp);
	}
}

void	PmergeMe::sort_list_of_lists()
{
	std::list<std::list<int> >::iterator it = _lls.begin();
	std::list<std::list<int> >::iterator at;

	while (std::distance(it, _lls.end()) >= 2)
	{
		at = it;
		std::advance(at, 1);
		if (it->size() == at->size())
		{
			if (it->back() > at->back())
				std::iter_swap(it, at);
		}
		std::advance(it, 2);
	}
}

void	PmergeMe::copy_to_list(std::list<std::list<int> > &ll)
{
	_list.clear();
	std::list<std::list<int> >::iterator it = ll.begin();
	std::list<int>::iterator it_l;
	
	for (; it != ll.end(); it++)
	{
		for (it_l = it->begin(); it_l != it->end(); it_l++)
			_list.push_back(*it_l);
	}
}

void	PmergeMe::insert_list()
{
	create_list_of_lists();
	create_mainchain_pend_list();
	insert_list_pend_in_mainchain();
	if (!_list_rest.empty())
	{
		_list_main.push_back(_list_rest.front());
		_list_rest.clear();
	}
	copy_to_list(_list_main);
}

void PmergeMe::create_mainchain_pend_list()
{
	if (_lls.back().size() != _size)
	{
		_list_rest.push_back(_lls.back());
		_lls.pop_back();
	}
	std::list<std::list<int> >::iterator it = _lls.begin();
	unsigned int i;
	for (i = 0; i < 2 && it != _lls.end(); it++, i++)
		_list_main.push_back(*it);
	std::list<std::list<int> >::iterator it_a;
	for (i = 2; it != _lls.end(); ++it, ++i) 
	{
		if (i % 2 == 0)
		{
			std::list<std::list<int> >::iterator next_it = it;
			next_it++;
			if (next_it == _lls.end())
				_list_pend.push_back(std::make_pair(*it, _list_main.end()));
			else
			{
				it_a = _list_main.insert(_list_main.end(), *next_it);
				_list_pend.push_back(std::make_pair(*it, it_a));
			}
		}
	}
}

bool	comp_list(std::list<int> x, std::list<int> y)
{
	return (x.back() <= y.back());
}

void PmergeMe::insert_list_pend_in_mainchain() 
{
	long JACOB[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690,
    87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810, 22369622,
    44739242, 89478486, 178956970, 357913942, 715827882, 1431655766, 2863311530,
    5726623062, 11453246122, 22906492246, 45812984490, 91625968982, 183251937962};

	pend_list::iterator b, end;
	std::list<std::list<int> >::iterator it_m;
	int count = 0, i = 0;

	while (!_list_pend.empty())
	{
		b = _list_pend.begin();
		end = _list_pend.begin();
		while (count < JACOB[i] - 1 && b != _list_pend.end())
		{
			b++;
			count++;
		}
		if (b == _list_pend.end())
			b--;
		while (true)
		{
			it_m = std::lower_bound(_list_main.begin(), b->second, b->first, comp_list);
			_list_main.insert(it_m, b->first);
			_list_pend.erase(b);
			if (b == end)
				break;
			b--;
		}
		count = 0;
		i++;
	}
}

size_t	PmergeMe::size_list()
{
	return _list.size();
}
