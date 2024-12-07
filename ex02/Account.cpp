/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:33:33 by dlamark-          #+#    #+#             */
/*   Updated: 2024/12/07 16:45:56 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account:: _totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill('0') << (now->tm_mon + 1);
	std::cout << std::setw(2) << std::setfill('0') << now->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << now->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_sec;
	std::cout << "] ";
}

Account::Account(int initial_deposit)
{
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created" << "\n";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << "\n";

}


bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if ((_amount - withdrawal) < 0)
	{
		std::cout << "refused" << "\n";
		return (0);
	}
	else
	{
		std::cout << withdrawal << ";";
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		_nbWithdrawals += 1;
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
	}
	return (1);
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";closed\n"; 
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}