/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA4_exercise2.cpp -o WA4exercise2
./WA4exercise2


Output:

[gboorse@localhost WA_4]$ ./WA4exercise2
BankAccount balance 3200.03
Savings balance 5412.44
Checking balance 325.15

Debiting 231.75 from all accounts
BankAccount balance 2968.28
Savings balance 5180.69
Checking balance 93.38

Crediting 131.01 to all accounts
BankAccount balance 3099.29
Savings balance 5311.7
Checking balance 224.37

Crediting interest of 106.234 to savings account.
Savings balance 5417.93

Goodbye!



*/

#include <iostream>

#include "BankAccount.h"
#include "Savings.h"
#include "Checking.h"
using namespace std;


int main()
{
	BankAccount b(3200.03);
	Savings s(5412.44, 0.02);
	Checking c(325.15, 0.02);

	cout << "BankAccount balance " << b.getBalance() << endl;
	cout << "Savings balance " << s.getBalance() << endl;
	cout << "Checking balance " << c.getBalance() << endl << endl;

	double toDebit = 231.75;
	cout << "Debiting " << toDebit << " from all accounts" << endl;

	b.debit(toDebit);
	s.debit(toDebit);
	c.debit(toDebit);

	cout << "BankAccount balance " << b.getBalance() << endl;
	cout << "Savings balance " << s.getBalance() << endl;
	cout << "Checking balance " << c.getBalance() << endl << endl;

	double toCredit = 131.01;
	cout << "Crediting " << toCredit << " to all accounts" << endl;

	b.credit(toCredit);
	s.credit(toCredit);
	c.credit(toCredit);

	cout << "BankAccount balance " << b.getBalance() << endl;
	cout << "Savings balance " << s.getBalance() << endl;
	cout << "Checking balance " << c.getBalance() << endl << endl;

	cout << "Crediting interest of " << s.calculateInterest() << " to savings account." << endl;
	s.credit(s.calculateInterest());
	cout << "Savings balance " << s.getBalance() << endl << endl;

	cout << "Goodbye!" << endl;

	return 0;
}