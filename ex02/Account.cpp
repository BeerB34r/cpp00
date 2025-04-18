#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts;
int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::_totalAmount;
int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::_totalNbDeposits;
int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::_totalNbWithdrawals;
int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << ++_nbDeposits;
	_totalNbDeposits++;
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal > _amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << ";withdrawal:" << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << ++_nbWithdrawals;
	_totalNbWithdrawals++;
	std::cout << std::endl;
	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::_displayTimestamp() {	
	std::time_t tstamp = std::time(&tstamp);
	std::tm tm = *std::localtime(&tstamp);
	std::cout << "[" << tm.tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << tm.tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << tm.tm_mday;
	std::cout << "_" << std::setw(2) << std::setfill('0') << tm.tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << tm.tm_min;
	std::cout << std::setw(2) << std::setfill('0') << tm.tm_sec << "]";
}

Account::Account() {
	_nbAccounts++;
}
