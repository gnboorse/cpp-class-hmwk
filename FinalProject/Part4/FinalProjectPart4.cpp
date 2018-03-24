/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++11 FinalProjectPart4.cpp -o FinalProjectPart4
./FinalProjectPart4



Output:

[gboorse@localhost Part4]$ ./FinalProjectPart4
Swapping two ints
Two [10, 100]
Two [100, 10]
Set both ints to 50
Two [50, 50]
Swapping two longs
Two [1000, 10000]
Two [10000, 1000]
Set both longs to 500
Two [500, 500]


*/

#include <iostream>
#include "Two.hpp"
using namespace std;


int main()
{
	int a = 10;
	int b = 100;
	long c = 1000;
	long d = 10000;

	Two<int> t1(&a, &b);
	Two<long> t2(&c, &d);

	cout << "Swapping two ints" << endl;
	cout << t1;
	t1.swap();
	cout << t1;

	cout << "Set both ints to 50" << endl;
	t1.setBoth(50);
	cout << t1;

	cout << "Swapping two longs" << endl;
	cout << t2;
	t2.swap();
	cout << t2;

	cout << "Set both longs to 500" << endl;
	t2.setBoth(500);
	cout << t2;

	return 0;

}