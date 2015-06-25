#include "MoneyMarketTransactions.h"

MMTransactions::MMTransactions() : MoneyMarket()
{
	m_balance = 0;
}
MMTransactions::~MMTransactions()
{}

int MMTransactions::withdraw(double amount)
{
	if (amount > 0 && amount <= m_balance)
	{
		std::cout << "\tWITHDRAW COMPLETE" << std::endl;
		transaction.insert(pair<int, double>(++m_key, amount));
		m_balance -= amount;
	}
	else if (amount < 0)
	{
		return false;
	}
	else if (amount > m_balance)
	{
		return false;
	}
	return true;
}

int MMTransactions::deposit(double amount)
{
	if (amount > 0)
	{
		m_balance += amount;
		std::cout << "\tDEPOSIT COMPLETE" << std::endl;
		transaction.insert(pair<int, double>(++m_key, amount));
		return true;
	}
	else
	{
		return false;
	}
}
void MMTransactions::output()
{
	std::cout << "\nYou have $" << get_balance() << " in your account" << std::endl;
	map<int, double>::iterator pos;
	for (pos = transaction.begin(); pos != transaction.end(); ++pos)
	{
		std::cout << "Key: " << pos->first << " value: $" << pos->second << std::endl;
	}
	std::cout << std::endl;
}
double MMTransactions::get_balance()
{
	return m_balance;
}
