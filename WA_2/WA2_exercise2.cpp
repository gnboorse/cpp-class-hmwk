/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++0x WA2_exercise2.cpp -o WA2exercise2
./WAexercise2


Output:

[gboorse@localhost WA_1]$ ./WA2exercise2
Enter a numberic score: 86
You entered the score of 86 and earned a grade of B. Good work!

[gboorse@localhost WA_1]$ ./WA2exercise2
Enter a numberic score: 99
You entered the score of 99 and earned a grade of A. Excellent!


*/

#include <iostream>

using namespace std;


void getScore(int* score);
void printGrade(int score);

int main()
{

	int my_score;

	getScore(&my_score);

	printGrade(my_score);
}

// get input into pointer at &score
void getScore(int* score)
{
	cout << "Enter a numberic score: ";
	cin >> *score; // read into value
	cout << "You entered the score of " << *score << "% and "; //print value
}


//find the char representation of calculated score
void printGrade(int score)
{
	char calculated;
	if (score > 100)
	{
		calculated = 'E';
	}
	else if (score >= 90) // A
	{
		calculated = 'A';
	}
	else if (score >= 80) // B
	{
		calculated = 'B';
	}
	else if (score >= 70) // C
	{
		calculated = 'C';
	}
	else if (score >= 60) // D
	{
		calculated = 'D';
	}
	else if (score >= 0) // F
	{
		calculated = 'F';
	}
	else
	{
		calculated = 'E';
	}
	
	//output the letter grade
	cout << "earned a grade of " << calculated << ". ";
	switch (calculated) //print a message
	{
		case 'A':
			cout << "Excellent!";
			break;
		case 'B':
			cout << "Good work!";
			break;
		case 'C':
			cout << "Okay.";
			break;
		case 'D':
			cout << "You passed.";
			break;
		case 'F':
			cout << "Dishonor on your family."; //life's tough
			break;
		default:
			cout << "Invalid input!";
	}
	cout << endl; //new line

}