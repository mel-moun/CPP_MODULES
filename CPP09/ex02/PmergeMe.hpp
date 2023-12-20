/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:13:35 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 11:36:43 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <ctime>
# include <iomanip>

typedef std::vector<std::pair<std::vector<int>, std::vector<std::vector<int> >::iterator> > pend;
typedef std::list<std::pair<std::list<int>, std::list<std::list<int> >::iterator> > pend_list;

class PmergeMe
{
private:
	/*************** In Common *****************/
	size_t			_size;

	/*************** Vector Vars ***************/
	std::vector<int> _vector;
	std::vector<std::vector<int> > _vcs;
	std::vector<std::vector<int> > _main;
	std::vector<std::vector<int> > _rest;
	pend _pend;

	/*************** List Vars *****************/
	std::list<int> _list;
	std::list<std::list<int> > _lls;
	std::list<std::list<int> > _list_main;
	std::list<std::list<int> > _list_rest;
	pend_list _list_pend;

public:
	/* Orthodox Form */
	PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& copy);
	~PmergeMe();

	/*************** Vector ********************/
	/* Taking input and checking it */
	void	take_input(char **av, int ac);

	/* The algorithm */
	void	FordJohsonVector(char **av, int ac);

	/* First Part */
	void	merge_sort();
	void	create_vector_of_vectors();
	void	sort_vector_of_vectors();
	void	copy_to_vector(std::vector<std::vector<int> > &_vcs);

	/* Second Part */
	void	insert();
	void	create_mainchain_pend();
	void	insert_pend_in_mainchain();

	/* Print Vector */
	void	print_vector(std::vector<int>& vec, const std::string& str);

	/* Size of the vector */
	size_t	size_vector();

	/*************** List **********************/
	/* Taking input and checking it */
	void	take_input_list(char **av, int ac);

	/* The algorithm */
	void	FordJohsonList(char **av, int ac);
	
	/* First Part */
	void	merge_sort_list();
	void	create_list_of_lists();
	void	sort_list_of_lists();
	void	copy_to_list(std::list<std::list<int> > &ll);

	/* Second Part */
	void	insert_list();
	void	create_mainchain_pend_list();
	void	insert_list_pend_in_mainchain();

	/* Print List */
	void	print_list(std::list<int>& vec);
	
	/* Size of the list */
	size_t	size_list();
};

bool	comp_list(std::list<int> x, std::list<int> y);
void	is_input_valid(char **av, int ac);
void	valid_input(char *str);
void	print_args(char **av);

#endif
