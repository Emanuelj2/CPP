#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount
{
private:
	std::string m_name{};
	double m_balance{};
public:

	BankAccount(std::string_view name = "Bob", double balance = 0.0);

	BankAccount& setOwner(std::string_view name);
	BankAccount& deposit(double amount);
	BankAccount& withdraw(double amount);

	void print()const;
};

#endif

