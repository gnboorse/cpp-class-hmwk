#include "BankAccount.h"

class Checking: public BankAccount
{
	double transactionFee;
  public:
  	Checking(double initialBalance, double initialFee) : BankAccount(initialBalance)
  	{
  		transactionFee = initialFee;
  	}
  	
  	bool credit(double amount)
  	{
  		bool parent_success = BankAccount::credit(amount);
  		if (parent_success)
  		{
  			balance -= transactionFee;
  		}
  	}

  	bool debit(double amount)
  	{
  		bool parent_success = BankAccount::debit(amount);
  		if (parent_success)
  		{
  			balance -= transactionFee;
  		}
  	}
};