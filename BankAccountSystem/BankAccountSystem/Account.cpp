#include "Account.h"
#include <iostream>

Account::Account(double amount, double balance){
	this->amount = amount;
	this->balance = balance;
}

void Account::deposit(double amount){
	balance += amount;
}
bool Account::withdraw(double amount){
	balance -= amount;
}
void Account::display() const{
	std::cout << "balance: " << balance;
}