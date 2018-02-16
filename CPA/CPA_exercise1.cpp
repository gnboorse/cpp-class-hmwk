/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x CPA_exercise1.cpp -o CPAexercise1
./CPAexercise1


Output:

[gboorse@localhost CPA]$ ./CPAexercise1
Enter a letter [1]: d
Enter a letter [2]: h
Enter a letter [3]: f
Enter a letter [4]: b
Enter a letter [5]: w
Enter a letter [6]: d
Enter a letter [7]: u
Enter a letter [8]: z
Enter a letter [9]: q
Enter a letter [10]: s
The first (alphabetic) letter you entered is: b

*/

#include <iostream>

using namespace std;

char firstletter(char x, char y)
{
	if (x > y)
	{
		return y;
	}
	
	return x;
	
}

int main()
{

	char first;
	char current;
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			cout << "Enter a letter [" << i + 1 << "]: ";
			cin >> first;
		}
		else 
		{
			cout << "Enter a letter [" << i + 1 << "]: ";
			cin >> current;
			first = tolower(firstletter(tolower(current), tolower(first)));
		}	
	}

	cout << "The first (alphabetic) letter you entered is: " << first << endl;

	return 0;
}