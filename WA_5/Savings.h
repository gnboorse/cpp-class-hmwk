#include "BankAccount.h"

class Savings: public BankAccount
{
	double interestRate;
  public:
  	Savings(double initialBalance, double initialInterest) : BankAccount(initialBalance)
  	{
  		interestRate = initialInterest;
  	}
  	double calculateInterest()
  	{
  		return interestRate * balance;
  	}

};