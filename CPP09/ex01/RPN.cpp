/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:13:55 by mel-moun          #+#    #+#             */
/*   Updated: 2023/12/17 15:20:36 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/***************** Orthodox Form *********************************************/

RPN::RPN() {}

RPN::RPN(const RPN &copy) : _rpn(copy._rpn) {}

RPN&	RPN::operator=(RPN const& copy)
{
	if (this != &copy)
		_rpn = copy._rpn;
	return *this;
}

RPN::~RPN() {}

/***************** It's own **************************************************/

void	RPN::rpn(const std::string &arg)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (!std::isdigit(arg[i]) && !is_operator(arg[i]) && arg[i] != 32 && arg[i] != '\t')
			throw std::runtime_error("Error");
		if (arg[i] == 32 || arg[i] == '\t')
			i++;
		if (std::isdigit(arg[i]))
		{
			if (std::isdigit(arg[i + 1]))
				throw std::runtime_error("Error");
			to_stack(arg.substr(i, 1));
		}
		if (is_operator(arg[i]))
			perform_operation(arg[i]);
	}
	if (_rpn.size() != 1)
		throw std::runtime_error("Error");
	std::cout << static_cast<int>(_rpn.top()) << std::endl;
}

int		RPN::is_operator(const char &c) 
{
    return (c == '-' || c == '+' || c == '/' || c == '*');
}

void	RPN::perform_operation(const char &c)
{
    double	a, b;

	if (_rpn.size() < 2)
		throw std::runtime_error("Error");
    a = _rpn.top();
    _rpn.pop();
    b = _rpn.top();
    _rpn.pop();
    switch (c) 
	{
        case '-':
			_rpn.push(b - a);
            break;
        case '+':
			_rpn.push(b + a);
            break;
        case '/':
		{
			if (a == 0)
				throw std::runtime_error("Error");
			_rpn.push(b / a);
            break;
		}
        case '*':
			_rpn.push(b * a);
    }
}

void	RPN::to_stack(const std::string& arg)
{
	_rpn.push(std::strtod(arg.c_str(), NULL));
}

void	RPN::valid_chars(const char& c)
{
	if (!(std::isdigit(c) || c == 32 || c == '\t' || c == '\0' || is_operator(c)))
		throw std::runtime_error("Error");
}
