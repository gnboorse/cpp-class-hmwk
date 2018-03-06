/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA5_exercise1.cpp -o WA5exercise1
./WA5exercise1

**
Creates a list of random bank accounts (Savings or Checking)
And then it iterates over those random accounts,
performs operations based on which type they are
And then cleans up memory and exits.
**

Example output:

[gboorse@localhost WA_5]$ ./WA5exercise1
We have 11 accounts
Account with balance $741
  How much do you want to withdraw (debit)? $10
  How much do you want to deposit (credit)? $0
  Account is Savings.
  Added interest = $21.93
 Final balance = $752.93
Account with balance $327
  How much do you want to withdraw (debit)? $12
  How much do you want to deposit (credit)? $2
  Account is Checking.
 Final balance = $316.96
Account with balance $1843
  How much do you want to withdraw (debit)? $223
  How much do you want to deposit (credit)? $1
  Account is Savings.
  Added interest = $81.05
 Final balance = $1702.05
Account with balance $1247
  How much do you want to withdraw (debit)? $224
  How much do you want to deposit (credit)? $33
  Account is Savings.
  Added interest = $21.12
 Final balance = $1077.12
Account with balance $1110
  How much do you want to withdraw (debit)? $44
  How much do you want to deposit (credit)? $211
  Account is Savings.
  Added interest = $63.85
 Final balance = $1340.85
Account with balance $831
  How much do you want to withdraw (debit)? $334
  How much do you want to deposit (credit)? $0
  Account is Savings.
  Added interest = $14.91
 Final balance = $511.91
Account with balance $245
  How much do you want to withdraw (debit)? $22
  How much do you want to deposit (credit)? $11133
  Account is Checking.
 Final balance = $11355.9
Account with balance $585
  How much do you want to withdraw (debit)? $335
  How much do you want to deposit (credit)? $111
  Account is Savings.
  Added interest = $10.83
 Final balance = $371.83
Account with balance $1672
  How much do you want to withdraw (debit)? $2
  How much do you want to deposit (credit)? $0
  Account is Checking.
 Final balance = $1669.94
Account with balance $1505
  How much do you want to withdraw (debit)? $33
  How much do you want to deposit (credit)? $3
  Account is Savings.
  Added interest = $44.25
 Final balance = $1519.25
Account with balance $1452
  How much do you want to withdraw (debit)? $55
  How much do you want to deposit (credit)? $1
  Account is Savings.
  Added interest = $27.96
 Final balance = $1425.96
Goodbye!


*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "BankAccount.h"
#include "Savings.h"
#include "Checking.h"
#include <typeinfo>
using namespace std;

typedef vector<BankAccount*> account_list;

account_list random_accounts();
void free_accounts(account_list* accounts_);

int main()
{
	
	account_list accounts = random_accounts();
	account_list::size_type size_ = accounts.size();
	cout << "We have " << size_ << " accounts" << endl;
	for(account_list::size_type i = 0; i != accounts.size(); i++) 
	{

    	BankAccount* b = accounts[i];
    	double startingBalance = accounts[i]->getBalance();
    	cout << "Account with balance $" << startingBalance << endl;

    	double debit_amount;
    	cout << "  How much do you want to withdraw (debit)? $";
    	cin >> debit_amount;
    	b->debit(debit_amount);

    	double credit_amount;
    	cout << "  How much do you want to deposit (credit)? $";
    	cin >> credit_amount;
    	b->credit(credit_amount);



    	if (dynamic_cast<Savings*>(b)) // check if Savings account
    	{
    		cout << "  Account is Savings." << endl;
    		//calculate interest and add to balance
    		Savings* s = dynamic_cast<Savings*>(b);
    		double interest = s->calculateInterest();
    		s->credit(interest);
    		cout << "  Added interest = $" << interest << endl;
    	}

    	if (dynamic_cast<Checking*>(b)) //check if Checking account
    	{
    		cout << "  Account is Checking." << endl;
    	}
    	double endingBalance = accounts[i]->getBalance();
    	cout << " Final balance = $" << endingBalance << endl;

    	
	}	

	//free up memory from this pointer vector
	free_accounts(&accounts);
	cout << "Goodbye!" << endl;

	return 0;
}

void free_accounts(account_list* accounts_)
{
	account_list accounts = *(accounts_);
	for(account_list::size_type i = 0; i != accounts.size(); i++) 
	{
		BankAccount* b = accounts[i];
		delete b;
	}
}

//get a list of random bank accounts
account_list random_accounts()
{
	srand (time(NULL)); //seed your random
	account_list v;
	int total = rand() % 20 + 1;
	if (total < 5) { total = 5; }
	v.reserve(total);

	for (int i = 0; i < total; i++)
	{
		int _switch = rand() % 2 + 1;

		if (_switch == 1)
		{
			double r = static_cast <double> (rand() % 5 + 1) / (double) 100;

			//checking bank account
			Checking* c = new Checking((double)(rand()%2000 + 1), r);

			v.push_back(c);

		}
		else if (_switch == 2)
		{
			double r = static_cast <double> (rand() % 5 + 1) / (double) 100;

			//savings bank account

			Savings* s = new Savings((double)(rand()%2000 + 1), r);
			v.push_back(s);
		}
		
	}
	return v;
}