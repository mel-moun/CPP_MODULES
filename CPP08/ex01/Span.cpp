/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:18:48 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/15 16:59:25 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/************* Canonical From **********************/

Span::Span() : _N(0), _list() {}

Span::Span(unsigned int i) : _N(i), _list() {}

Span::Span(const Span &copy) : _N(copy._N), _list(copy._list) {}

Span& Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_N = copy._N;
		_list = copy._list;
	}
	return (*this);
}
	
Span::~Span() {_list.clear();}

/************* Getter ******************************/

const std::list<int>& Span::getList()const
{
	return (_list);
}

/************* Operator ****************************/

std::ostream&   operator<<(std::ostream& out, const Span &ob)
{
    std::list<int> list = ob.getList();
    if (!list.empty())
    {
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
        	std::cout << *it << " ";
        std::cout << std::endl;
    }
    else
        std::cout << "List is empty !" << std::endl;
	list.clear();
    return (out);
}

/************* It's own ****************************/

void	Span::addNumber(int i)
{
	if (_list.size() >= _N)
		throw std::runtime_error("Maximum N is already stored");
	_list.push_back(i);
}

int	Span::shortestSpan()
{
	if (_list.size() <= 1)
		throw(std::runtime_error("It should me at least 2 elements"));
	std::list<int> 				tmp_list(_list);
	std::list<int>::iterator	tmp;
	std::list<int>::iterator	it;
	int							min;

	tmp_list.sort();
	it = tmp_list.begin();
	it++;
	min = *it - *tmp_list.begin();
	for (; it != tmp_list.end(); it++)
	{
        tmp = it++;
        if (it != tmp_list.end() && (*it - *tmp) < min)
            min = *it - *tmp;
        --it;
	}
	return (min);
}

int	Span::longestSpan()
{
	if (_list.size() <= 1)
		throw(std::runtime_error("It should me at least 2 elements"));
	std::list<int>	tmp_list(_list);
	tmp_list.sort();
	return (tmp_list.back() - tmp_list.front());
}

void	Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	if (_list.size() >= _N)
		throw(std::runtime_error("Can't insert more"));
	_list.insert(_list.end(), begin, end);
	_list.resize(_N + 1);
}
