/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:53:14 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/14 16:53:29 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack &copy)
	{
		*this = copy;
	}
	MutantStack& operator=(const MutantStack &copy)
	{
		if (this != &copy)
			return (*this);
		return (*this);
	}
	~MutantStack() {}

	typedef typename std::stack<T, container>::container_type::iterator					iterator;
	typedef typename std::stack<T, container>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T, container>::container_type::reverse_iterator			reverse_iterator;
	typedef typename std::stack<T, container>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const
	{
		return this->c.begin();
	}
	const_iterator end() const
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}
	reverse_iterator rend()
	{
		return this->c.rend();
	}

	const_reverse_iterator	rbegin() const
	{
		return this->c.rbegin();
	}
	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}
};

#endif
