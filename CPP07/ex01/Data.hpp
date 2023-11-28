/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:25:12 by mel-moun          #+#    #+#             */
/*   Updated: 2023/11/21 17:21:44 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
private:
	std::string _name;

public:
	Data();
	Data(const Data& copy);
	Data& operator=(const Data &copy);
	~Data();

	const std::string&	getName() const;
	void				setName(const std::string &change);
};

std::ostream&	operator<<(std::ostream& out, const Data& obj);

#endif
