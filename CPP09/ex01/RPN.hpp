/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:15:10 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 13:26:43 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN
{
private:
	std::stack<double>	_rpn;

public:
	RPN();
	RPN(const RPN& copy);
	RPN& operator=(const RPN  &copy);
	~RPN();

	void	rpn(const std::string &arg);
	int		is_operator(const char &c);
	void	perform_operation(const char &c);
	void	to_stack(const std::string &arg);
	void	valid_chars(const char& c);
};

#endif
