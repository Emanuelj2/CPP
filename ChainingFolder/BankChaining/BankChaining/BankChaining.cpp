// BankChaining.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankAccount.h"

int main()
{
    BankAccount ba;
    ba.setOwner("Emanuel")
        .deposit(500)
        .withdraw(120)
        .withdraw(1000)
        .deposit(-50)
        .withdraw(50)
        .print();

    BankAccount ba2;
    ba2.print();


}