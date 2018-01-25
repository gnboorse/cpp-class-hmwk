 /*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA2_exercise1.cpp -o WA2exercise1
./WA2exercise1


Output:

[gboorse@localhost WA_1]$ ./WA2exercise1
| Array 1  +  Array 2  =  Array 3 |
| 543      |  739      |  1282    |
| 371      |  1767     |  2138    |
| 12       |  224      |  236     |
| 553      |  1802     |  2355    |
| 349      |  1001     |  1350    |
| 144      |  1460     |  1604    |
| 285      |  1377     |  1662    |
| 38       |  963      |  1001    |
| 99       |  471      |  570     |
| 184      |  693      |  877     |
| 422      |  1186     |  1608    |
| 397      |  1104     |  1501    |
| 979      |  1264     |  2243    |
| 324      |  375      |  699     |
| 35       |  694      |  729     |
| 909      |  577      |  1486    |
| 785      |  280      |  1065    |
| 696      |  796      |  1492    |
| 503      |  600      |  1103    |
| 950      |  1203     |  2153    |
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
using namespace std;

//using pointers here because that's what I used to do in C
void addArrays(int* first_array, int* second_array, int* third_array, int total_length);

int main()
{

	//initialize the arrays
	int array_one[20];
	int array_two[20];
	int array_three[20];
	
	//seed the random to input data for the numbers
	srand (time(NULL));
	
	for (int i = 0; i < sizeof(array_one)/sizeof(array_one[0]); i++)
	{
		

		array_one[i] = rand() % 1000 + 1;
		array_two[i] = rand() % 2000 + 1;
	}

	//Do the actual adding
	addArrays(array_one, array_two, array_three, sizeof(array_one)/sizeof(array_one[0]));

	cout << "| Array 1  +  Array 2  =  Array 3 |" << endl;


	// print the arrays
	for (int i = 0; i < sizeof(array_one)/sizeof(array_one[0]); i++)
	{
		//for each item, calculate the number of spaces that should trail the number
		// i.e., for 1, 3 spaces
		//       for 250, 1 space
		//       for 1000, 0 spaces

		int spaces_one = 4 - to_string(array_one[i]).length();
		int spaces_two = 4 - to_string(array_two[i]).length();
		int spaces_three = 4 - to_string(array_three[i]).length();

		// output array_one item
		cout << "| " << array_one[i];

		//print the trailing spaces
		for (int j = 0; j < spaces_one; j++)
		{
			cout << " ";
		}

		cout << "     |  ";

		// output array_two item
		cout << array_two[i];

		//print the trailing spaces
		for (int j = 0; j < spaces_two; j++)
		{
			cout << " ";
		}

		cout << "     |  ";
		
		// output array_three item
		cout << array_three[i];

		//print the trailing spaces
		for (int j = 0; j < spaces_three; j++)
		{
			cout << " ";
		}

		cout << "    |" << endl; //end of line
		
		//Pretty proud of this table printing! :) 
	}

}


void addArrays(int* first_array, 
	int* second_array, 
	int* third_array, 
	int total_length)
{

	for (int i = 0; i < total_length; i++)
	{
		//assign to the value at (dereferenced location of pointer + i)
		*(&third_array[i]) = *(&first_array[i]) + *(&second_array[i]);
	}
}