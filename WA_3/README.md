**Written Assignment 3**

Written Assignment 3 includes two programming exercises. Both are required to gain credit for Written Assignment 3.

**Exercise 1 for Written Assignment 3**

Create a class called Complex for performing arithmetic with complex numbers. Complex numbers have the form:

realPart + imaginaryPart * *i*

where *i* is

√-1

Use double variables to represent the private data of the class. Provide a constructor that enables an object of this class to be initialized when it’s declared. The constructor should contain default values of (1,1) i.e. 1 for the real part and 1 for the imaginary part. Provide public member functions that perform the following tasks:

(a) add – Adds two Complex numbers: The real parts are added together and the imaginary parts are added together. 
(b) subtract – Subtracts two Complex numbers. The real part of the right operand is subtracted from the real part of the left operand, and the imaginary part of the right operand is subtracted from the imaginary part of the left operand. 
(c) toString – Returns a string representation of a Complex number in the form (a,b), where a is the real part andb is the imaginary part.

Write a main program to test your class. Your program should prompt the user to enter two Complex numbers. If the user hits enter without entering anything, then the default value of (1,1) used by the default constructor should be used. It should then print out the sum and difference of the two Complex numbers entered. The following is a sample run:

Enter a Complex number with the real and imaginary parts separated by a comma: 4,5 
Enter a Complex number with the real and imaginary parts separated by a comma: 3,2

The sum of the two complex numbers is (7,7) and the difference is (1,3).

Another sample run would be:

Enter a complex number with the real and imaginary parts separated by a comma: 
Enter a complex number with the real and imaginary parts separated by a comma: 3,2

The sum of the two Complex numbers is (4,3) and the difference is (-2,-1).



**Exercise 2 for Written Assignment 3**

Create a SavingsAccount class. Use a static data member annualInterestRate to store the annual interest rate for each of the savers. Each member of the class contains a private data member savingsBalance indicating the amount the saver currently has on deposit. Provide member function calculateMonthlyInterest that calculates the monthly interest by multiplying the savingsBalance by annualInterestRate divided by 12; this interest should be added to savingsBalance. Provide a static member function modifyInterestRate that sets the static annualInterestRate to a new value.

Write a main program to test your class. Your program should prompt the user to enter the savingsBalance for two different accounts. It should ask for the annualInterestRate.

It should then compute and print the new balance for both the accounts. A sample run would be:

Please enter the savings balance of account 1: 2000 
Please enter the savings balance of account 2: 3000

Please enter the annual interest rate: 3

The interest for account 1 would be \$5.00 and the balance after one month would be $2005.00 
The interest for account 2 would be \$7.50 and the balance after one month would be $3007.50

Would you like to change the interest rate? (Y or N): Y

Please enter the annual interest rate: 6

The interest for account 1 would be \$10.00 and the balance after one month would be $2010.00 
The interest for account 2 would be \$15.00 and the balance after one month would be $3015.00

Would you like to change the interest rate? (Y or N): N

Goodbye!