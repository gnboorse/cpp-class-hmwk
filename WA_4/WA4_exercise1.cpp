 /*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA4_exercise1.cpp -o WA4exercise1
./WA4exercise1



Output:

[gboorse@localhost WA_4]$ ./WA4exercise1
1. Show that we can output fractions:
5/1
2. Show that we can add fractions:
2/21 + 3/14 = 13/42
3. Show that we can subtract fractions:
3/4 - 1/2 = 1/4
4. Show that we can multiply fractions:
1/3 * 2/7 = 2/21
5. Show that we can divide fractions:
1/3 / 2/7 = 7/6
6. Show that we can compare fractions:
1/3 == 1/3
1/3 != 5/1
1/3 < 5/1
7. Show that we can easily simplify fractions:
Simplify 33/11 to 3/1



*/

#include <iostream>
#include "Rational.h"
using namespace std; 

int main()
{

	cout << "1. Show that we can output fractions: " << endl;
	Rational r1(30, 6);
	cout << r1 << endl;

	cout << "2. Show that we can add fractions: " << endl;
	Rational r2(2, 21);
	Rational r3(3, 14);
	Rational r4 = r2 + r3; // 1/7 + 3/14

	cout << r2 << " + " << r3 << " = " << r4 << endl;

	cout << "3. Show that we can subtract fractions: " << endl;
	Rational r5(3, 4);
	Rational r6(1, 2);
	Rational r7 = r5 - r6;

	cout << r5 << " - " << r6 << " = " << r7 << endl;	

	Rational r8(1, 3);
	Rational r9(2, 7);
	Rational r10 = r8 * r9;
	Rational r11 = r8 / r9;
	cout << "4. Show that we can multiply fractions: " << endl;
	cout << r8 << " * " << r9 << " = " << r10 << endl;	
	cout << "5. Show that we can divide fractions: " << endl;
	cout << r8 << " / " << r9 << " = " << r11 << endl;		

	cout << "6. Show that we can compare fractions: " << endl;

	Rational r12(1, 3);
	if (r12 == r8)
	{
		cout << r12 << " == " << r8 << endl;
	}

	if (r12 != r1)
	{
		cout << r12 << " != " << r1 << endl;
	}

	if (r12 < r1)
	{
		cout << r12 << " < " << r1 << endl;
	}

	if (r12 >= r1)
	{
		cout << r12 << " >= " << r1 << endl;
	}

	cout << "7. Show that we can easily simplify fractions: " << endl;
	Rational r13;
	r13.setNumerator(33); //using setters here because constructor simplifies automatically
	r13.setDenominator(11);
	cout << "Simplify " << r13 << " to ";
	r13.simplify();
	cout << r13 << endl;

	return 0;

}

