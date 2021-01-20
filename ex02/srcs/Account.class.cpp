/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:08:16 by juligonz          #+#    #+#             */
/*   Updated: 2021/01/20 13:12:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <ctime>
#include <iostream>


int		Account::getNbAccounts( void ){
	return _nbAccounts;
}
int		Account::getTotalAmount( void ){
	return _totalAmount;
}
int		Account::getNbDeposits( void ){
	return _totalNbDeposits;
}
int		Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void ){
	
}

Account::Account( int initial_deposit ) {
	this->makeDeposit(initial_deposit);
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created";
}
Account::~Account( void ){
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed";
	
}

void	Account::makeDeposit( int deposit ){
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ){
	if (_totalAmount < withdrawal || withdrawal <= 0)
		return false;
	this->_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	return true;
}

int		Account::checkAmount( void ) const{
	return _amount;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << " accounts:" << _accountIndex
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ){
	char	buffer[20];
	time_t rawtime;
	struct tm * timeinfo;
	
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	std::strftime(buffer, 20, "[%Y%m%d_%H%M%s]", timeinfo);
	std::cout << buffer;
}
