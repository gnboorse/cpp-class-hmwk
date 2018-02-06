 /*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA3_exercise1.cpp -o WA3exercise1
./WA3exercise1


Output:

[gboorse@localhost WA_3]$ ./WA3exercise1
Enter a Complex number with the real and imaginary parts separated by a comma: 4,5
Enter a Complex number with the real and imaginary parts separated by a comma: (3,2)
The sum of the two Complex numbers is (7.000000, 7.000000) and the difference is (1.000000, 3.000000)
[gboorse@localhost WA_3]$ ./WA3exercise1
Enter a Complex number with the real and imaginary parts separated by a comma:
Enter a Complex number with the real and imaginary parts separated by a comma: 3,2
The sum of the two Complex numbers is (4.000000, 3.000000) and the difference is (-2.000000, -1.000000)
[gboorse@localhost WA_3]$



*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <vector>
#include <iostream>
#include <iomanip>
#include <regex>
using namespace std; 

#include "Complex.h"

int main()
{

	//this is messy, I know.
	//But it can handle actual ordered pairs with parentheses! :) 


	//1
	cout << "Enter a Complex number with the real and imaginary parts separated by a comma: ";
	string input1_s, real1_s, imaginary1_s;
	double real1 = 1;
	double imaginary1 = 1;
	
	getline(cin, input1_s);

	if (!input1_s.empty())
	{
		bool found_comma = false;
		//before we find the comma, add chars to real number
		// after we find the comma, add chars to imaginary number
		for (int i = 0; i < input1_s.length(); i++)
		{
			char c = input1_s[i];
			if (c == ',')
			{
				found_comma = true;
			}
			else if (c != ' ' && c != '(' && c != ')')
			{
				if (found_comma)
				{
					imaginary1_s += c;
				}
				else
				{
					real1_s += c;
				}
			}
		}
		//convert to double
		real1 = stod(real1_s);
		imaginary1 = stod(imaginary1_s);
	}

	//2	
	cout << "Enter a Complex number with the real and imaginary parts separated by a comma: ";
	string input2_s, real2_s, imaginary2_s;
	double real2 = 1;
	double imaginary2 = 1;
	
	getline(cin, input2_s);

	if (!input2_s.empty())
	{
		bool found_comma = false;
		//before we find the comma, add chars to real number
		// after we find the comma, add chars to imaginary number
		for (int i = 0; i < input2_s.length(); i++)
		{
			char c = input2_s[i];
			if (c == ',')
			{
				found_comma = true;
			}
			else if (c != ' ' && c != '(' && c != ')')
			{
				if (found_comma)
				{
					imaginary2_s += c;
				}
				else
				{
					real2_s += c;
				}
			}
		}
		//convert to double
		real2 = stod(real2_s);
		imaginary2 = stod(imaginary2_s);
	}

	Complex a(real1, imaginary1);
	Complex b(real2, imaginary2);

	// cout << a.toString() << endl;
	// cout << b.toString() << endl;


	cout << "The sum of the two Complex numbers is " << a.add(a, b).toString() 
		 << " and the difference is " << a.subtract(a, b).toString() << endl;






}

