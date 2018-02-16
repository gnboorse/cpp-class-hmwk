/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x CPA_exercise2.cpp -o CPAexercise2
./CPAexercise2


Output:

[gboorse@localhost CPA]$ ./CPAexercise2
Input a temperature (degrees F): 44
You entered 44 degrees Fahrenheit.
The activity will be basketball!
[gboorse@localhost CPA]$ ./CPAexercise2
Input a temperature (degrees F): 55
You entered 55 degrees Fahrenheit.
The activity will be basketball!
[gboorse@localhost CPA]$ ./CPAexercise2
Input a temperature (degrees F): 555
You entered 555 degrees Fahrenheit.
The activity will be swimming!
[gboorse@localhost CPA]$ ./CPAexercise2
Input a temperature (degrees F): 67
You entered 67 degrees Fahrenheit.
The activity will be basketball!
[gboorse@localhost CPA]$ ./CPAexercise2
Input a temperature (degrees F): 72
You entered 72 degrees Fahrenheit.
The activity will be baseball!
[gboorse@localhost CPA]$ ./CPAexercise2
Input a temperature (degrees F): 82
You entered 82 degrees Fahrenheit.
The activity will be baseball!

*/

#include <iostream>
#include <string>

using namespace std;

void getTemp(int &temp);
void printActivity(int temp);

int main()
{
	
	int temp;
	
	getTemp(temp);

	cout << "You entered " << temp << " degrees Fahrenheit." << endl;

	printActivity(temp);
	
	return 0;
}

void getTemp(int &temp)
{
	cout << "Input a temperature (degrees F): ";
	cin >> temp;
}

void printActivity(int temp)
{
	string activity;
	if (temp > 85)
	{
		activity = "swimming";
	}
	else if (temp > 70)
	{
		activity = "baseball";
	}
	else if (temp > 32)
	{
		activity = "basketball";
	}
	else //temp  <= 32
	{
		activity = "GO HOME";
	}
	cout << "The activity will be " << activity << "!" << endl;
}