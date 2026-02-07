#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{

public:

	Account(double amount, double balance){}

	virtual void deposit(double amount);
	virtual bool withdraw(double amount);
	virtual void display() const;

private:
	double amount;
	double balance;
};

#endif

