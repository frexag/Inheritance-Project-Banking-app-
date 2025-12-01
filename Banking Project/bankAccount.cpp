#include "bankAccount.h"
#include <iostream>

using namespace std;

void bankAccount::setAccountNumber(int accountNumber) {
	this->accountNumber = accountNumber;
}
int bankAccount::getAccountNumber() const {
	return this->accountNumber;
}
double bankAccount::getAccountBalance() const {
	return this->balance;
}
void bankAccount::deposit(double amount) {
	this->balance += amount; //balance = balance + amount
}
void bankAccount::withdraw(double amount) {
	balance -= amount;
}
void bankAccount::print() const {
	cout << "Account Number: " << this->accountNumber << endl;
	cout << "Balance (USD): " << this->balance << endl;
} 
bankAccount::bankAccount() = default;

bankAccount::bankAccount(int accountNumber, double balance) : 
	accountNumber(accountNumber), balance(balance) {}
