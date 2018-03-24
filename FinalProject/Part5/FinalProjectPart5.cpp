/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++11 FinalProjectPart5.cpp -o FinalProjectPart5
./FinalProjectPart5



Output:

[gboorse@localhost Part5]$ ./FinalProjectPart5
Square, side = 20, area = 400
Cube, side = 20, volume = 8000

*/

#include <iostream>
#include "Square.hpp"
#include "Cube.hpp"
using namespace std;

//simple program to test the Square and Cube
int main()
{

	Square s;
	s.setSide(20); //square of side = 20

	Cube c;
	c.setSide(20); //square of side = 20

	cout << s;
	cout << c;
	

	return 0;

}