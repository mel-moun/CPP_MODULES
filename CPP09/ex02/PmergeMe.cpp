/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:13:36 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 15:26:14 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/***************** Orthodox Form *********************************************/

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_size = copy._size;
		_vector = copy._vector;
		_vcs = copy._vcs;
		_main = copy._main;
		_rest = copy._rest;
		_pend = copy._pend;
		_list = copy._list;
		_lls = copy._lls;
		_list_main = copy._list_main;
		_list_rest = copy._list_rest;
		_list_pend = copy._list_pend;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {_vector.clear(); _list.clear();}

/***************** Take Input ************************************************/

void	PmergeMe::take_input(char **av, int ac)
{
	for (int i = 1; i < ac; i++)
		_vector.insert(_vector.end(), static_cast<int>(std::strtod(av[i], NULL)));
}

/***************** Is Input Valid ********************************************/

void	is_input_valid(char **av, int ac)
{
	char		*ptr;
	double		num;

	for (int i = 1; i < ac; i++)
	{
		valid_input(av[i]);
		num = std::strtod(av[i], &ptr);
		if (ptr[0] != '\0' || num > INT_MAX)
			throw std::runtime_error("Error");
	}
}

void	valid_input(char *str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if (!(std::isdigit(str[i]) || str[i] == 32
		|| str[i] == '\t' || str[i] == '+'))
			throw std::runtime_error("Error");
	}
}

/***************** Print Containers ******************************************/

void    PmergeMe::print_vector(std::vector<int>& vec, const std::string& str)
{
	if (!vec.empty())
	{
		std::cout << str;
		std::vector<int>::iterator it = vec.begin();
		for (; it != vec.end(); it++)
		{
			std::cout << *it;
			if (it + 1 != _vector.end())
				std::cout << ", ";
		}
		std::cout << std::endl << std::endl;
	}
	else
		std::cout << "Vector is empty" << std::endl;
}

void	print_args(char **av)
{
	std::cout << "before: ";
	for (int i = 1; av[i]; i++)
	{
		std::cout << static_cast<std::string>(av[i]);
		if (av[i + 1] != NULL)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

/***************** Ford-Johnson **********************************************/

void	PmergeMe::FordJohsonVector(char **av, int ac)
{
	_size = 1;
	clock_t start, end;
	start = std::clock();
	this->take_input(av, ac);
	this->merge_sort();
	end = std::clock();
	this->print_vector(_vector, "after : ");
	double final = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 100;
	std::cout << "Time to process a range of " << PmergeMe::size_vector() \
	<< " elements with std::vector: " << std::setprecision(5) << final << "us" << std::endl;
}

/***************** First Step  ***********************************************/

void	PmergeMe::merge_sort()
{
	if (_vector.size() == 1)
		return;
	this->create_vector_of_vectors();
	this->sort_vector_of_vectors();
	this->copy_to_vector(_vcs);
	if (_size == _vcs[0].size() && _size == _vcs[1].size())
	{
		if (_size == _vcs[2].size() && _size == _vcs[3].size())
		{
			_vcs.clear();
			_size *= 2;
			merge_sort();
		}
	}
	_vcs.clear();
	this->insert();
	_main.clear();
	_pend.clear();
	_rest.clear();
	_size /= 2;
}

void	PmergeMe::create_vector_of_vectors()
{
	std::vector<int> tmp;

	for (size_t i = 0; i < _vector.size(); i += _size)
	{
		tmp.clear();
		for (size_t j = 0; j < _size && i + j < _vector.size(); j++)
			tmp.push_back(_vector[i + j]);
		_vcs.push_back(tmp);
	}
}

void	PmergeMe::sort_vector_of_vectors()
{
	for (size_t i = 0; i < _vcs.size() - 1 ; i+= 2)
	{
		if (_vcs[i].size() == _vcs[i + 1].size())
		{
			if (_vcs[i].back() > _vcs[i + 1].back())
				swap(_vcs[i], _vcs[i + 1]);
		}
	}
}

void	PmergeMe::copy_to_vector(std::vector<std::vector<int> > &_vcs)
{
	_vector.clear();
	for (size_t i = 0; i < _vcs.size(); i++)
	{
		for (size_t j = 0; j < _vcs[i].size(); j++)
			_vector.push_back(_vcs[i][j]);
	}
}

/***************** Second Step  **********************************************/

bool	comp(std::vector<int> x, std::vector<int> y)
{
	return (x.back() <= y.back());
}

void	PmergeMe::insert_pend_in_mainchain()
{
	long JACOB[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, 10922, 21846, 43690,
    87382, 174762, 349526, 699050, 1398102, 2796202, 5592406, 11184810, 22369622,
    44739242, 89478486, 178956970, 357913942, 715827882, 1431655766, 2863311530,
    5726623062, 11453246122, 22906492246, 45812984490, 91625968982, 183251937962};

	pend::iterator	b, end;
	std::vector<std::vector<int> >::iterator it_m;
	int				count = 0, i = 0;

	while (!_pend.empty())
	{
		b = _pend.begin();
		end = _pend.begin();
		while (count < JACOB[i] - 1 && b != _pend.end())
		{
			b++;
			count++;
		}
		if (b == _pend.end())
			b--;
		while (true)
		{
			it_m = std::lower_bound(_main.begin(), b->second, b->first, comp);
			_main.insert(it_m, b->first);
			for (pend::iterator it = _pend.begin(); it != _pend.end(); it++)
			{
				if (it->second >= it_m)
					it->second++;
			}
			_pend.erase(b);
			if (b == end)
				break;
			b--;
		}
		count = 0;
		i++;
	}
}

void	PmergeMe::insert()
{
	create_vector_of_vectors();
	_main.reserve(_vector.size());
	_main.clear();
	_pend.reserve(_vector.size());
	_pend.clear();
	create_mainchain_pend();
	insert_pend_in_mainchain();
	if (!_rest.empty())
	{
		_main.push_back(_rest.front());
		_rest.clear();
	}
	copy_to_vector(_main);
}

void	PmergeMe::create_mainchain_pend()
{
	if (_vcs.back().size() != _size)
	{
		_rest.push_back(_vcs.back());
		_vcs.pop_back();
	}
	_main.push_back(_vcs[0]);
	_main.push_back(_vcs[1]);
	std::vector<std::vector<int> >::iterator it_a;
	for (unsigned int i = 2; i < _vcs.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (i == _vcs.size() - 1)
				_pend.push_back(std::make_pair(_vcs[i], _main.end()));
			else
			{
				it_a = _main.insert(_main.end(), _vcs[i + 1]);
				_pend.push_back(std::make_pair(_vcs[i], it_a));
			}
		}
	}
} 

size_t	PmergeMe::size_vector()
{
	return _vector.size();
}
