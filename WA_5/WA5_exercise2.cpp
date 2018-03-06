/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA5_exercise2.cpp -o WA5exercise2
./WA5exercise2


Output:

[gboorse@localhost WA_5]$ ./WA5exercise2




*/

#include <iostream>
#include "Array.h"
using namespace std;


int main()
{
	// make an array of ints
	Array<int> myint_arr(10);
	for (size_t i{0}; i < myint_arr.getSize(); i++)
	{
		int n;
		cout << "[" << (i + 1) << "/" << myint_arr.getSize() << "] Input an int: ";
		cin >> n;
		myint_arr[i] = n;
	}
	cout << myint_arr << endl;


	//make an array of strings
	Array<string> mystr_arr(10);
	for (size_t i{0}; i < mystr_arr.getSize(); i++)
	{
		string s;
		cout << "[" << (i + 1) << "/" << mystr_arr.getSize() << "] Input a string: ";
		cin >> s;
		mystr_arr[i] = s;
	}
	cout << mystr_arr << endl;

	cout << "Goodbye!" << endl;
	return 0;
}