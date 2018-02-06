 /*

@author gabriel boorse

Savings Account class for WA3_exercise2

*/


class SavingsAccount
{
	static double annualInterestRate;
	double savingsBalance;

  public:
  	SavingsAccount(double balance)
  	{
  		savingsBalance = balance;
  	}
  	double getSavingsBalance()
  	{
  		return savingsBalance;
  	}
  	void addInterestToSavingsBalance(double interest)
  	{
  		savingsBalance += interest;
  	}
  	double calculateMonthlyInterest()
  	{
  		return savingsBalance * (SavingsAccount::annualInterestRate / 12);
  	}

  	static void modifyInterestRate (double newAnnualInterestRate)
  	{
  		annualInterestRate = (newAnnualInterestRate / 100);
  	}
	
};


double SavingsAccount::annualInterestRate = 0;