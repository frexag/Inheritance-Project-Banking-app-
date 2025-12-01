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