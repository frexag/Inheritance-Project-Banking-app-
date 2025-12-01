#include <iostream>
#include <iomanip>
#include "savingsAccount.h"

using namespace std;

void savingsAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}

double savingsAccount::getInterestRate() const {
    return interestRate;
}

void savingsAccount::postInterest() const {
    cout << "Your daily interest is: " << fixed << setprecision(2)
        << (getAccountBalance() * (interestRate / 100) / 12)
        << " USD" << endl;
}

void savingsAccount::deposit(double amount) {
    bankAccount::deposit(amount);
}

void savingsAccount::withdraw(double amount) {
    if (amount > bankAccount::getAccountBalance()) {
        cout << "Not enough balance to withdraw $" << amount << " USD" << endl;
    }
    else {
        bankAccount::withdraw(amount);
        cout << "Your new balance is " << fixed << setprecision(2)
            << bankAccount::getAccountBalance() << " USD" << endl;
    }
}

void savingsAccount::print() const {
    cout << "Savings Account Details:" << endl;
    bankAccount::print();
    cout << "Interest Rate: " << fixed << setprecision(2)
        << interestRate << " %" << endl;
}

savingsAccount::savingsAccount() = default;

savingsAccount::savingsAccount(int accountNumber, double balance, double interestRate)
    : bankAccount(accountNumber, balance), interestRate(interestRate) {}
