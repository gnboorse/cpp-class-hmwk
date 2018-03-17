/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA6_exercise2.cpp -o WA6exercise2
./WA6exercise2


Output:

[gboorse@localhost WA_6]$ ./WA6exercise2




*/

#include <iostream>
#include "DivByZero.h"
using namespace std;

int quotient(int a, int b);

int main()
{
	int a;
	int b;
	cout << "You are going to divide two integers." << endl;

	cout << "Input first integer: ";
	cin >> a;
	cout << "Input second integer: ";
	cin >> b;


	try 
	{
		cout << "Quotient is " << quotient(a, b) << endl;
	}
	catch (DivByZero& ex)
	{
		cout << ex.what() << endl;
	}

	cout << "Goodbye!" << endl;
	return 0;
}

int quotient(int a, int b)
{
	if (b == 0)
	{
		DivByZero divByZeroException;
		throw divByZeroException;
	}

	return a / b;
}