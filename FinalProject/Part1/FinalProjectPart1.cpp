/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux
s
Use:

g++ -std=c++0x WA1_exercise1.cpp -o WA1exercise1
./WAexercise1


Output:

[gboorse@localhost WA_1]$ ./WA1exercise1
Enter 15 numbers
Enter a number [1]:1
Enter a number [2]:2
Enter a number [3]:4
Enter a number [4]:3
Enter a number [5]:7
Enter a number [6]:1
Enter a number [7]:1
Enter a number [8]:1444
Enter a number [9]:66
Enter a number [10]:3
Enter a number [11]:1
Enter a number [12]:1
Enter a number [13]:43
Enter a number [14]:48
Enter a number [15]:3
1 2 4 3 7 1 1 1444 66 3 1 1 43 48 3
The largest number is 1444

*/

#include <iostream>
using namespace std;


double larger (double x, double y);


int main()
{

	cout << "Enter 15 numbers" << endl;


	double numbersEntered[15]; //this is my array of numbers


	//iterate and get input
	for (int i = 0; i < sizeof(numbersEntered)/sizeof(numbersEntered[0]) ; i++ )
	{
		cout << "Enter a number [" << i + 1 << "]:";
		cin >> numbersEntered[i];


	}

	//iterate and get largest number
	double max = 0;
	for (int i = 0; i < sizeof(numbersEntered)/sizeof(numbersEntered[0]) ; i++ )
	{
		if (i == 0)
		{
			max = numbersEntered[i];
		}
		//store larger one in max so that when we're done max is the biggest number
		max = larger(max, numbersEntered[i]);

		//output numbers as we go along
		cout << numbersEntered[i] << " ";
	}

	//output which one was largest
	cout << endl << "The largest number is " << max << endl;

	return 0;

}


//comparison function
double larger(double x, double y)
{

	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}