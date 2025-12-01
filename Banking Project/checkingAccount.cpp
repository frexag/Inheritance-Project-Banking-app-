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