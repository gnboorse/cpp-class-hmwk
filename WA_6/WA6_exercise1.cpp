/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++11 WA6_exercise1.cpp -o WA6exercise1
./WA6exercise1

Example output: 

[gboorse@localhost WA_6]$ ./WA6exercise1
Enter a file name to read: input.txt
Enter a file name to write to: output.txt
Goodbye!
[gboorse@localhost WA_6]$ cat output.txt 
This is just a test.

Some more text is needed.

The number of lines in the file is 3

A appears 1 times in file 
D appears 2 times in file 
E appears 7 times in file 
H appears 1 times in file 
I appears 3 times in file 
J appears 1 times in file 
M appears 2 times in file 
N appears 1 times in file 
O appears 2 times in file 
R appears 1 times in file 
S appears 6 times in file 
T appears 6 times in file 
U appears 1 times in file 
X appears 1 times in file 

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

const int UPPERCASE_OFFSET = 65; //'A' = ascii 65
const int LOWERCASE_OFFSET = 97; //'a' = ascii 97

//templates
int countLinesFromFile(string filename);
vector<string> getLinesFromFile(string filename, int file_lines);
// void writeLinesToFile(string filename, vector<string> lines);

int main()
{
	//get filenames from user
	string infile;
	string outfile;
	cout << "Enter a file name to read: ";
	cin >> infile;
	cout << "Enter a file name to write to: ";
	cin >> outfile;

	//get stuff from file
	int file_lines = countLinesFromFile(infile);
	vector<string> myLines = getLinesFromFile(infile, file_lines);

	fstream myFile;
	myFile.open(outfile, ios::out);
	myFile << "---" << endl;
	int character_distribution[26];
	for (int i = 0; i < 26; i++) { character_distribution[i] = 0;}
	for(vector<string>::size_type i = 0; i < myLines.size(); i++) 
	{
		string line = myLines[i];
		for (int j = 0; j < 26; j++)
		{
			//using algorithm::count for this because I'm lazy
			character_distribution[j] += count(line.begin(), line.end(), (char)(j+UPPERCASE_OFFSET)); 
			character_distribution[j] += count(line.begin(), line.end(), (char)(j+LOWERCASE_OFFSET)); 
		}

		if (myLines[i].length() > 0) //no empty strings here allowed 
		{
			if (myLines[i].at(myLines[i].length() - 1) == '\n')
			{
				myFile << myLines[i];
			}
			else
			{
				myFile << myLines[i] << endl;
			}
		}
		else 
		{
			myFile << myLines[i] << endl;
		}
	}
	myFile << "---" << endl;
	myFile << endl;
	myFile << "The number of lines in the file is " << (int)file_lines << endl;
	myFile << endl;

	//output the character counts
	for (int i = 0; i < 26; i++)
	{

		if (character_distribution[i] > 0)
		{
			myFile << (char)(i +UPPERCASE_OFFSET) << " appears " << character_distribution[i] << " times in file " << endl;

		}
	}

	myFile.close();

	cout << "Goodbye!" << endl;
	return 0;
}

// return the number of lines in a file
int countLinesFromFile(string filename)
{
	fstream myFile;
	myFile.open(filename, ios::in);

	int counter;
	
	for( string item; getline(myFile, item ); )
	{
		counter++;	
	}

	myFile.close();

	return counter;
}

//get all lines from file as a vector of string
vector<string> getLinesFromFile(string filename, int file_lines)
{
	vector<string> lines;
	lines.reserve(file_lines);

	fstream myFile;
	myFile.open(filename, ios::in);
	
	for( string item; getline(myFile, item ); )
	{
		lines.push_back(item);
	}

	myFile.close();

	return lines;
}
//unused...
// void writeLinesToFile(string filename, vector<string> lines)
// {
// 	fstream myFile;
// 	myFile.open(filename, ios::out);
// 	for(vector<string>::size_type i = 0; i < lines.size(); i++) 
// 	{
// 		//we are writing lines[i] to the file
// 		// cout << lines[i] << " (" << lines[i].length() << ") " << endl;
// 		if (lines[i].length() > 0) //no empty strings here allowed 
// 		{
// 			if (lines[i].at(lines[i].length() - 1) == '\n')
// 			{
// 				myFile << lines[i];
// 			}
// 			else
// 			{
// 				myFile << lines[i] << endl;
// 			}
// 		}
// 		else 
// 		{
// 			myFile << lines[i] << endl;
// 		}
// 	}
// 	myFile.close();

// }

