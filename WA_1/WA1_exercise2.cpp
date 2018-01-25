/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA1_exercise2.cpp -o WA1exercise2
./WAexercise2


Output:

[gboorse@localhost WA_1]$ ./WA1exercise2
Enter a number in the range 1-5: 5
You entered the number five

*/

#include <iostream>
#include <string>
using namespace std;


string nameCheck(int num);

int main()
{

	int num = 0;

	cout << "Enter a number in the range 1-5: ";

	cin >> num;

	if (num > 0 && num < 6)
	{
		cout << "You entered the number " << nameCheck(num) << endl;
	}
	else
	{
		cout << "You entered a number outside the range 1-5." << endl;
	}
}

string nameCheck(int num)
{

	if (num == 1)
	{
		return "one";
	}
	else if (num == 2)
	{
		return "two";
	}
	else if (num == 3)
	{
		return "three";
	}
	else if (num == 4)
	{
		return "four";
	}
	else if (num == 5)
	{
		return "five";
	}
	else
	{
		return "bad entry";
	}
}