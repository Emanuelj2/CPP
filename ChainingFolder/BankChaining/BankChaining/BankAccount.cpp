#include "BankAccount.h"
#include <iostream>


BankAccount::BankAccount(std::string_view name, double balance)
	: m_name { name }, m_balance { balance }
{}

BankAccount& BankAccount::setOwner(std::string_view name)
{
	m_name = name;
	return *this;
}
BankAccount& BankAccount::deposit(double amount)
{
	if (amount > 10000 || amount < 0)
	{
		std::cout << "cannot deposite that ammount\n";
		return *this;
	}
	m_balance += amount;
	return *this;
}

BankAccount& BankAccount::withdraw(double amount)
{
	if (amount > m_balance || m_balance < 0)
	{
		std::cout << "insuficient funds\n";
		return *this;
	}
	m_balance -= amount;
}

void BankAccount::print()const
{
	std::cout << "Owner: " << m_name << "\nbalance: " << m_balance << "\n\n";
}
