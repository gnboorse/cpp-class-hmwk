/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++11 FinalProjectPart3.cpp -o FinalProjectPart3
./FinalProjectPart3



Output to output.txt should be:
5 5 5 3 5 11 10 5 3 2 7 6 10 2 6 2 6 5 7 2 4 2 5 7 4 7 12 7 7 4 2 7 2 2 7 10 4 4 5 5 2 13 2 9 5 4 6 6 2 6 5 9 9 4 8 9 3 9 4 2 5 3 7 8 6 4 2 3 8 3 2 12 4 5 4 5 5 3 10 11 10 11 5 3 8 5 4 4 2 4 9 9 2 5 10 6 5 5 4 10 4 4 5 10 4 8 3 10 3 4 3 6 3 4 12 5 7 3 3 7 10 5 9 5 5 8 4 3 7 5 4 5 3 5 12 8 6 3 4 3 7 4 4 7 8 2 6 2 6 6 7 7 11 2 4 2 6 7 4 7 14 5 8 8 11 4 2 7 2 2 7 12 4 5 3 3 4 13 3 2 2 9 5 4 4 5 9 12 3 5 3 7 3 6 3 8 5 9 

*/

#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	fstream inFile;
	fstream outFile;
	
	string filenameIn = "input.txt";
	string filenameOut = "output.txt";

	inFile.open(filenameIn, ios::in);
	outFile.open(filenameOut, ios::out);

	string word;
	while (inFile >> word) //read in by word
	{
		//output word [word length] to stdout
		cout << word << " [" << word.length() << "]" << endl;
		//output lengths to output.txt
		outFile << word.length() << " ";
	}

	inFile.close();
	outFile.close();

	return 0;

}