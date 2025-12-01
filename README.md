# Inheritance-Project-Banking-app-
Alex Griggs
CISC 192

## main.cpp 
```
#include <iostream>
#include "checkingAccount.h"

using namespace std;

int main() 
{
	int accountNumber, input;
	double amount, interestRate, minBalance, serviceCharge;

	cout << "Enter account number: " << endl;
	cin >> accountNumber;

	cout << "Enter balance (in USD): " << endl;
	cin >> amount;

	cout << "Enter interest rate (in %): " << endl;
	cin >> interestRate;

	cout << "Enter minimum balance (in USD): " << endl;
	cin >> minBalance;

	cout << "Enter service charge (in %): " << endl;
	cin >> serviceCharge;

	checkingAccount account(accountNumber, amount, interestRate, minBalance, serviceCharge);
	do {
		cout << "Which service do you want to use?" << endl;
		cout << "1. Deposit" << endl;
		cout << "2. Withdraw" << endl;
		cout << "3. Print Balance" << endl;
		cout << "4. Print Account Details" << endl;
		cout << "5. Print Daily interest" << endl;
		cout << "0. Exit" << endl;
		cin >> input;
			switch (input) {
			case 0:
				cout << "Thank you. Goodbye" << endl;
				break;
			case 1:
				cout << "Deposit amount: ";
				cin >> amount;
				account.deposit(amount);
				break;
			case 2:
				cout << "Service charge of " << account.getServiceCharge() << "% applies if the withdrawal amount is more than $500 from the checking account" << endl;
				cout << "Enter the withdrawal amount: ";
				cin >> amount;
				account.withdraw(amount);
				break;
			case 3:
				if (account.verifyBalance()) {
					cout << "Your account balance is positive." << endl;
				}
				else {
					cout << "Your account balance is below the minimum balance." << endl;
				}
				break;
			case 4:
				account.print();
				break;
			case 5:
				account.postInterest();
				break;
			default:
				cout << "Invalid input." << endl;
			}
	} while (input != 0);
	return 0;
}
```

## bankAccount.h
```
#pragma once

class bankAccount {
private:
	int accountNumber = 0;
	double balance = 0;

public:
	void setAccountNumber(int accNum);
	int getAccountNumber() const;
	double getAccountBalance() const;
	void deposit(double amount);
	void withdraw(double amount);
	void print() const;
	bankAccount();
	bankAccount(int accountNumber, double balance);
};
```

## bankAccount.cpp
```
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
```

## checkingAccount.h
```
#pragma once
#include "bankAccount.h"

class checkingAccount : public bankAccount {
private:
	double interestRate = 0.0;
	double minBalance = 0.0;
	double serviceCharge = 0.0;
public:
	void setInterestRate(double interestRate);
	double getInterestRate() const;
	void setMinBalance(double minBalance);
	double getMinBalance() const;
	void setServiceCharge(double serviceCharge);
	double getServiceCharge() const;
	void postInterest() const;
	bool verifyBalance() const;
	void deposit(double amount);
	void withdraw(double amount);
	void print() const;
	checkingAccount();
	checkingAccount(int accountNumber, double balance, double interestRate, double minBalance, double serviceCharge);
};
```

## checkingAccount.cpp
```

#include <iostream>
#include <iomanip>

#include "checkingAccount.h"

using namespace std;

void checkingAccount::setInterestRate(double interestRate) {
	this->interestRate = interestRate;
}
double checkingAccount::getInterestRate() const {
	return interestRate;
}
void checkingAccount::setMinBalance(double minBalance) {
	this->minBalance = minBalance;
}
double checkingAccount::getMinBalance() const {
	return minBalance;
}
void checkingAccount::setServiceCharge(double serviceCharge) {
	this->serviceCharge = serviceCharge;
}
double checkingAccount::getServiceCharge() const {
	return serviceCharge;
}
void checkingAccount::postInterest() const {
	cout << "Your daily interest is: " << fixed << setprecision(2) << (getAccountBalance() * (interestRate / 100) / 365) << " USD" << endl;
}
bool checkingAccount::verifyBalance() const {
	if (getAccountBalance() >= minBalance) {
		cout << "Your balance is: " << fixed << setprecision(2) << getAccountBalance() << " USD" << endl;
		return true;
	}
	else {
		cout << "Your balance is: " << fixed << setprecision(2) << getAccountBalance() << " USD" << endl;
		return false;
	}
}
void checkingAccount::deposit(double amount) {
	bankAccount::deposit(amount);
}
void checkingAccount::withdraw(double amount) {
	double fee;
	if (amount > bankAccount::getAccountBalance()) {
		cout << "Not enough balance to withdraw $" << amount << " USD" << endl;
	}
	else if (amount > 500) {
		fee = amount * (serviceCharge / 100.0);
		amount = amount + fee;
		if (amount > bankAccount::getAccountBalance()
			) {
			cout << "Not enough balance to withdraw $" << amount << " USD including service charge of " << fixed << setprecision(2) << fee << " USD" << endl;
			return;
		}
		cout << "A service charge of " << fixed << setprecision(2) << fee << " USD will be applied to this transaction as it is over $500 USD, please confirm (y/n)" << endl;
		char confirm;
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y') {
			bankAccount::withdraw(amount);
			cout << "Your new balance is " << fixed << setprecision(2) << bankAccount::getAccountBalance() << " USD" << endl;
		}
		else {
			cout << "Transaction cancelled." << endl;
		}
	}
	else if (amount <= 500) {
		bankAccount::withdraw(amount);
		cout << "Your new balance is " << fixed << setprecision(2) << bankAccount::getAccountBalance() << " USD" << endl;
	}
}
void checkingAccount::print() const {
	bankAccount::print();
	cout << "Interest Rate (%): " << fixed << setprecision(2) << interestRate << endl;
	cout << "Minimum Balance (USD): " << fixed << setprecision(2) << minBalance << endl;
	cout << "Service Charge (%): " << fixed << setprecision(2) << serviceCharge << endl;
}
checkingAccount::checkingAccount() = default;
checkingAccount::checkingAccount(int accountNumber, double balance, 
								double interestRate, double minBalance, double serviceCharge) :
								bankAccount(accountNumber, balance), interestRate(interestRate), 
								minBalance(minBalance), serviceCharge(serviceCharge) {}

```

## savingsAccount.h
```
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
```

## savingsAccount.cpp
```
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
```
