#pragma once
#include "bankAccount.h"

class savingsAccount : public bankAccount {
private:
    double interestRate = 0.0;

public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void postInterest() const;
    void deposit(double amount);
    void withdraw(double amount);
    void print() const;

    savingsAccount();
    savingsAccount(int accountNumber, double balance, double interestRate);
};
