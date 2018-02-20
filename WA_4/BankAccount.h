#pragma once

#include <iostream>
using namespace std;

class BankAccount
{
  protected:
	double balance;
  public:
  	BankAccount(double initialBalance)
  	{
  		if (initialBalance >= 0.0)
  		{
  			balance = initialBalance;
  		}
  		else
  		{
  			cout << "Invalid initial balance." << endl;
  		}
  	}

  	virtual bool credit(double amount)
  	{
  		balance += amount;
  		return true;
  	}

  	virtual bool debit(double amount)
  	{
  		if (amount <= balance)
  		{
  			balance -= amount;
  			return true;
  		}
  		else
  		{
  			cout << "The balance is less than the debit amount." << endl;
  			return false;
  		}
  	}

  	double getBalance() { return balance; }

};
