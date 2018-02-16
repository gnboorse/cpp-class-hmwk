/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x CPA_exercise3.cpp -o CPAexercise3
./CPAexercise3


Output:

[gboorse@localhost CPA]$ ./CPAexercise3
Demand is 2000
Price is 2
---
RevenueValue is 4000

*/

#include <iostream>

#include "Revenue.h"

using namespace std;

int main()
{

	Revenue revenue(2000, 2);
	cout << "Demand is " << revenue.getDemand() << endl;
	cout << "Price is " << revenue.getPrice() << endl << "---" << endl;
	cout << "RevenueValue is " << revenue.getRevenueValue() << endl;

	return 0;
}