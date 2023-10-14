/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:10:26 by mel-moun          #+#    #+#             */
/*   Updated: 2023/10/12 18:09:24 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit):
    _accountIndex(_nbAccounts), _amount(initial_deposit),
    _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount \
    << ";deposits:" << _totalNbDeposits << ";withdrawals:" \
    << _totalNbWithdrawals << std::endl;
} 
    
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount \
    << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    int tmp;
    
    tmp = _amount;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << tmp\
    << ";deposit:" << deposit << ";amount:" << _amount\
    << ";nb_deposits:" << _nbDeposits << std::endl;
}

int		Account::checkAmount(void) const
{
	return (_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
    int tmp;

    _displayTimestamp();
    if (checkAmount() < withdrawal)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" \
        << _amount << ";withdrawal:refused" << std::endl;
        return (true);
    }
    tmp = _amount;
    _amount = _amount - withdrawal;
    _totalNbWithdrawals++;
   _nbWithdrawals++;
   _totalAmount -= withdrawal;
    std::cout << "index:" << _accountIndex << ";p_amount:" << tmp \
    << ";withdrawal:" << withdrawal << ";amount:" << _amount \
    << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (false);
}

void	Account::_displayTimestamp(void)
{
    time_t  currentTime;
    char    timeString[20];

    time(&currentTime);
    strftime(timeString, sizeof(timeString), "[%Y%m%d_%H%M%S] ", localtime(&currentTime));
    std::cout << timeString;
}
