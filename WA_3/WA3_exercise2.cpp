/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA3_exercise2.cpp -o WA3exercise2
./WA3exercise2


Output:

[gboorse@localhost WA_3]$ ./WA3exercise2
Please enter the savings balance of account 1: 2000
Please enter the savings balance of account 2: 3000

Please enter the annual interest rate: 3

The interest for account 1 would be $5 and the balance after one month would be $2005
The interest for account 2 would be $7.5 and the balance after one month would be $3007.5

Would you like to change the interest rate? (Y or N): Y
Please enter the annual interest rate: 6

The interest for account 1 would be $10 and the balance after one month would be $2010
The interest for account 2 would be $15 and the balance after one month would be $3015

Would you like to change the interest rate? (Y or N): N
Goodbye!

*/

#include <iostream>

#include "SavingsAccount.h"

using namespace std;

bool getYN(string yn)
{
	return yn[0] == 'Y' || yn[0] == 'y';
}

int main()
{
	bool repeat = false;

	double account1_d, account2_d, interest_d;
	cout << "Please enter the savings balance of account 1: ";
	cin >> account1_d;

	cout << "Please enter the savings balance of account 2: ";
	cin >> account2_d;

	cout << endl;

	SavingsAccount account1(account1_d);
	SavingsAccount account2(account2_d);

	do
	{
		//MESSY
		if (repeat)
		{
			string yn;
			cout << "Would you like to change the interest rate? (Y or N): ";
			cin >> yn;
			repeat = getYN(yn);
			if (!repeat) break;
			cout << endl;
		} else repeat = true;

		cout << "Please enter the annual interest rate: ";
		cin >> interest_d;
		cout << endl;

		account1.modifyInterestRate(interest_d);
		account2.modifyInterestRate(interest_d);

		double interestAmount1 = account1.calculateMonthlyInterest();
		double interestAmount2 = account2.calculateMonthlyInterest();

		cout << "The interest for account 1 would be $" << interestAmount1 
			 << " and the balance after one month would be $" << account1.getSavingsBalance() + interestAmount1 << endl;

		cout << "The interest for account 2 would be $" << interestAmount2 
			 << " and the balance after one month would be $" << account2.getSavingsBalance() + interestAmount2 << endl;

		cout << endl;


	} while (repeat);

	cout << "Goodbye!" << endl;

	return 0;
}