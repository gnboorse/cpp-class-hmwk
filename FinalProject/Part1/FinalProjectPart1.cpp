/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux

Use:

g++ -std=c++11 FinalProjectPart1.cpp -o FinalProjectPart1
./FinalProjectPart1


Output is at the end of the file. Scroll down.

*/

#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <time.h>

#define TRACK_SIZE 70

// 1 + 2 = 3 ;)
#define EMPTY_VALUE 0
#define HARE_VALUE 1
#define TORT_VALUE 2
#define BOTH_VALUE 3

//types of movement
#define FAST_PLOD 3
#define SLIP -6
#define SLOW_PLOD 1
#define SLEEP 0
#define BIG_HOP 9
#define BIG_SLIP -12
#define SMALL_HOP 1
#define SMALL_SLIP -2

//for sleeps
#define SLEEP_AMOUNT 500

using namespace std;

bool take_turn(int squares[TRACK_SIZE]);
void print_track(int squares[TRACK_SIZE]);
int delta(int rand_num, int animal);

int main()
{
	//this is the track
	int squares[TRACK_SIZE];

	for (int i = 0; i < TRACK_SIZE; i++) {squares[i] = EMPTY_VALUE;} //zero out array just in case (?)
	squares[0] = BOTH_VALUE; //first square is both hare and tortoise at the beginning 

	cout << "Bang! Off they go!" << endl;
	int counter = 1;
	cout << "-----" << " TURN " << counter << "-----" << endl;
	while (!take_turn(squares))
	{
		this_thread::sleep_for(chrono::milliseconds(SLEEP_AMOUNT));

		//comment out these two if you just want to watch
		cout << "Press Enter to continue: ";
		cin.get();

		cout << endl;

		counter++;
		cout << "-----" << " TURN " << counter << "-----" << endl;
	}
	//race is over
	cout << "Goodbye!" << endl;
	return 0;

}

bool take_turn(int squares[TRACK_SIZE])
{
	srand (time(NULL)); //seed your random every time to make it more interesting
	int hare_delta = delta(rand() % 10 + 1, HARE_VALUE);
	int tort_delta = delta(rand() % 10 + 1, TORT_VALUE);

	int tort_pos = 0;
	int hare_pos = 0;

	//search for both hare and tortoise positions
	for (int i = 0; i < TRACK_SIZE; i++)
	{
		if (squares[i] == BOTH_VALUE)
		{
			tort_pos = i;
			hare_pos = i;
		}
		else if (squares[i] == HARE_VALUE)
		{
			hare_pos = i;
		}
		else if (squares[i] == TORT_VALUE)
		{
			tort_pos = i;
		}
	}
	
	int hare_future = hare_pos + hare_delta;
	if (hare_future < 0) { hare_future = 0; } //don't let them go off the track

	int tort_future = tort_pos + tort_delta;
	if (tort_future < 0) { tort_future = 0; }	

	//check win conditions
	bool hare_win = hare_future >= TRACK_SIZE;
	bool tort_win = tort_future >= TRACK_SIZE;
	
	if (hare_win && tort_win) //both tie
	{
		cout << "Tie score -- no winner!";
		return true;
	}
	else if (hare_win) //hare wins
	{
		cout << "Yay! The rabbit won! He hops the fastest!" << endl;
		return true;
	}
	else if (tort_win) //tortoise wins
	{
		cout << "Woo-hooo! Slow and steady wins the race! Congratulations, turtle!" << endl;
		return true;
	}
	else //no win yet
	{
		squares[tort_pos] -= TORT_VALUE;
		squares[hare_pos] -= HARE_VALUE;
		squares[tort_future] += TORT_VALUE;
		squares[hare_future] += HARE_VALUE;
		print_track(squares);
		cout << "[" << hare_future + 1 << ", " << tort_future + 1 << "]";
		if (tort_future == hare_future)
		{
			cout << " (BUMP) " << endl;
		}
		else
		{
			cout << endl;
		}
		return false;
	}

	
}

void print_track(int squares[TRACK_SIZE])
{
	for (int i = 0; i < TRACK_SIZE; i++)
	{
		if (squares[i] == EMPTY_VALUE)
		{
			cout << ".";
		}
		else if (squares[i] == HARE_VALUE)
		{
			cout << "H";
		}
		else if (squares[i] == TORT_VALUE)
		{
			cout << "T";
		}
		else if (squares[i] == BOTH_VALUE)
		{
			cout << "B";
		}
	}
}

//this function computes how far an animal should travel based on given random numbers
int delta(int rand_num, int animal)
{
	if (animal == TORT_VALUE) //rules for tortoise
	{
		if (rand_num % 2 == 0) //50% of the time
		{
			cout << "TORTOISE: Fast Plod, " << FAST_PLOD << " squares." << endl;
			return FAST_PLOD; //+3 steps
		}
		else if (rand_num == 1 || rand_num == 3) //20%
		{
			cout << "TORTOISE: Slip, " << SLIP << " squares." << endl;
			return SLIP;
		}
		else //remaining 30%
		{
			cout << "TORTOISE: Slow Plod, " << SLOW_PLOD << " squares."<< endl;
			return SLOW_PLOD;
		}
	}
	else if (animal == HARE_VALUE) //rules for hare
	{
		if (rand_num <= 2)  //first 20%
		{
			cout << "HARE: Sleep, " << SLEEP << " squares."<< endl;
			return SLEEP;
		}
		else if (rand_num <= 4) //second 20%
		{
			cout << "HARE: Big Hop, " << BIG_HOP << " squares."<< endl;
				return BIG_HOP;
		}
		else if (rand_num <= 5) //next 10%
		{
			cout << "HARE: Big Slip, " << BIG_SLIP << " squares."<< endl;
			return BIG_SLIP;
		}
		else if (rand_num <= 8) //next 30%
		{
			cout << "HARE: Small Hop, " << SMALL_HOP << " squares."<< endl;
			return SMALL_HOP;
		}
		else //remaining 20%
		{
			cout << "HARE: Small Slip, " << SMALL_SLIP << " squares."<< endl;
			return SMALL_SLIP;
		}
	}
	else
	{
		return 0;
	}
}
/*

SAMPLE_OUTPUT

Gabriels-MBP:Part1 gboorse$ ./FinalProjectPart1 
Bang! Off they go!
----- TURN 1-----
HARE: Small Hop, 1 squares.
TORTOISE: Slow Plod, 1 squares.
.B....................................................................[2, 2] (BUMP) 
Press Enter to continue: 

----- TURN 2-----
HARE: Sleep, 0 squares.
TORTOISE: Slow Plod, 1 squares.
.HT...................................................................[2, 3]
Press Enter to continue: 

----- TURN 3-----
HARE: Small Hop, 1 squares.
TORTOISE: Slip, -6 squares.
T.H...................................................................[3, 1]
Press Enter to continue: 

----- TURN 4-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
...T.......H..........................................................[12, 4]
Press Enter to continue: 

----- TURN 5-----
HARE: Small Slip, -2 squares.
TORTOISE: Fast Plod, 3 squares.
......T..H............................................................[10, 7]
Press Enter to continue: 

----- TURN 6-----
HARE: Small Hop, 1 squares.
TORTOISE: Slip, -6 squares.
T.........H...........................................................[11, 1]
Press Enter to continue: 

----- TURN 7-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
...T...............H..................................................[20, 4]
Press Enter to continue: 

----- TURN 8-----
HARE: Sleep, 0 squares.
TORTOISE: Slip, -6 squares.
T..................H..................................................[20, 1]
Press Enter to continue: 

----- TURN 9-----
HARE: Small Hop, 1 squares.
TORTOISE: Fast Plod, 3 squares.
...T................H.................................................[21, 4]
Press Enter to continue: 

----- TURN 10-----
HARE: Big Slip, -12 squares.
TORTOISE: Slow Plod, 1 squares.
....T...H.............................................................[9, 5]
Press Enter to continue: 

----- TURN 11-----
HARE: Sleep, 0 squares.
TORTOISE: Fast Plod, 3 squares.
.......TH.............................................................[9, 8]
Press Enter to continue: 

----- TURN 12-----
HARE: Small Slip, -2 squares.
TORTOISE: Slow Plod, 1 squares.
......H.T.............................................................[7, 9]
Press Enter to continue: 

----- TURN 13-----
HARE: Small Hop, 1 squares.
TORTOISE: Slow Plod, 1 squares.
.......H.T............................................................[8, 10]
Press Enter to continue: 

----- TURN 14-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
............T...H.....................................................[17, 13]
Press Enter to continue: 

----- TURN 15-----
HARE: Small Slip, -2 squares.
TORTOISE: Slow Plod, 1 squares.
.............TH.......................................................[15, 14]
Press Enter to continue: 

----- TURN 16-----
HARE: Small Hop, 1 squares.
TORTOISE: Fast Plod, 3 squares.
...............HT.....................................................[16, 17]
Press Enter to continue: 

----- TURN 17-----
HARE: Big Hop, 9 squares.
TORTOISE: Slow Plod, 1 squares.
.................T......H.............................................[25, 18]
Press Enter to continue: 

----- TURN 18-----
HARE: Big Hop, 9 squares.
TORTOISE: Slow Plod, 1 squares.
..................T..............H....................................[34, 19]
Press Enter to continue: 

----- TURN 19-----
HARE: Big Slip, -12 squares.
TORTOISE: Fast Plod, 3 squares.
.....................B................................................[22, 22] (BUMP) 
Press Enter to continue: 

----- TURN 20-----
HARE: Small Slip, -2 squares.
TORTOISE: Slip, -6 squares.
...............T...H..................................................[20, 16]
Press Enter to continue: 

----- TURN 21-----
HARE: Small Hop, 1 squares.
TORTOISE: Fast Plod, 3 squares.
..................T.H.................................................[21, 19]
Press Enter to continue: 

----- TURN 22-----
HARE: Big Hop, 9 squares.
TORTOISE: Slip, -6 squares.
............T................H........................................[30, 13]
Press Enter to continue: 

----- TURN 23-----
HARE: Big Hop, 9 squares.
TORTOISE: Slip, -6 squares.
......T...............................H...............................[39, 7]
Press Enter to continue: 

----- TURN 24-----
HARE: Small Slip, -2 squares.
TORTOISE: Fast Plod, 3 squares.
.........T..........................H.................................[37, 10]
Press Enter to continue: 

----- TURN 25-----
HARE: Small Hop, 1 squares.
TORTOISE: Slow Plod, 1 squares.
..........T..........................H................................[38, 11]
Press Enter to continue: 

----- TURN 26-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
.............T................................H.......................[47, 14]
Press Enter to continue: 

----- TURN 27-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
................T......................................H..............[56, 17]
Press Enter to continue: 

----- TURN 28-----
HARE: Sleep, 0 squares.
TORTOISE: Fast Plod, 3 squares.
...................T...................................H..............[56, 20]
Press Enter to continue: 

----- TURN 29-----
HARE: Small Hop, 1 squares.
TORTOISE: Slow Plod, 1 squares.
....................T...................................H.............[57, 21]
Press Enter to continue: 

----- TURN 30-----
HARE: Big Slip, -12 squares.
TORTOISE: Fast Plod, 3 squares.
.......................T....................H.........................[45, 24]
Press Enter to continue: 

----- TURN 31-----
HARE: Big Slip, -12 squares.
TORTOISE: Fast Plod, 3 squares.
..........................T.....H.....................................[33, 27]
Press Enter to continue: 

----- TURN 32-----
HARE: Sleep, 0 squares.
TORTOISE: Slow Plod, 1 squares.
...........................T....H.....................................[33, 28]
Press Enter to continue: 

----- TURN 33-----
HARE: Small Slip, -2 squares.
TORTOISE: Fast Plod, 3 squares.
..............................B.......................................[31, 31] (BUMP) 
Press Enter to continue: 

----- TURN 34-----
HARE: Small Hop, 1 squares.
TORTOISE: Slow Plod, 1 squares.
...............................B......................................[32, 32] (BUMP) 
Press Enter to continue: 

----- TURN 35-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
..................................T.....H.............................[41, 35]
Press Enter to continue: 

----- TURN 36-----
HARE: Small Slip, -2 squares.
TORTOISE: Slip, -6 squares.
............................T.........H...............................[39, 29]
Press Enter to continue: 

----- TURN 37-----
HARE: Small Hop, 1 squares.
TORTOISE: Slow Plod, 1 squares.
.............................T.........H..............................[40, 30]
Press Enter to continue: 

----- TURN 38-----
HARE: Small Hop, 1 squares.
TORTOISE: Slow Plod, 1 squares.
..............................T.........H.............................[41, 31]
Press Enter to continue: 

----- TURN 39-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
.................................T...............H....................[50, 34]
Press Enter to continue: 

----- TURN 40-----
HARE: Sleep, 0 squares.
TORTOISE: Slip, -6 squares.
...........................T.....................H....................[50, 28]
Press Enter to continue: 

----- TURN 41-----
HARE: Small Hop, 1 squares.
TORTOISE: Fast Plod, 3 squares.
..............................T...................H...................[51, 31]
Press Enter to continue: 

----- TURN 42-----
HARE: Small Hop, 1 squares.
TORTOISE: Fast Plod, 3 squares.
.................................T.................H..................[52, 34]
Press Enter to continue: 

----- TURN 43-----
HARE: Big Slip, -12 squares.
TORTOISE: Slip, -6 squares.
...........................T...........H..............................[40, 28]
Press Enter to continue: 

----- TURN 44-----
HARE: Sleep, 0 squares.
TORTOISE: Fast Plod, 3 squares.
..............................T........H..............................[40, 31]
Press Enter to continue: 

----- TURN 45-----
HARE: Small Slip, -2 squares.
TORTOISE: Slow Plod, 1 squares.
...............................T.....H................................[38, 32]
Press Enter to continue: 

----- TURN 46-----
HARE: Small Slip, -2 squares.
TORTOISE: Slow Plod, 1 squares.
................................T..H..................................[36, 33]
Press Enter to continue: 

----- TURN 47-----
HARE: Small Hop, 1 squares.
TORTOISE: Slip, -6 squares.
..........................T.........H.................................[37, 27]
Press Enter to continue: 

----- TURN 48-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
.............................T...............H........................[46, 30]
Press Enter to continue: 

----- TURN 49-----
HARE: Big Hop, 9 squares.
TORTOISE: Fast Plod, 3 squares.
................................T.....................H...............[55, 33]
Press Enter to continue: 

----- TURN 50-----
HARE: Small Slip, -2 squares.
TORTOISE: Slow Plod, 1 squares.
.................................T..................H.................[53, 34]
Press Enter to continue: 

----- TURN 51-----
HARE: Small Hop, 1 squares.
TORTOISE: Fast Plod, 3 squares.
....................................T................H................[54, 37]
Press Enter to continue: 

----- TURN 52-----
HARE: Big Hop, 9 squares.
TORTOISE: Slow Plod, 1 squares.
.....................................T........................H.......[63, 38]
Press Enter to continue: 

----- TURN 53-----
HARE: Big Hop, 9 squares.
TORTOISE: Slow Plod, 1 squares.
Yay! The rabbit won! He hops the fastest!
Goodbye!
Gabriels-MBP:Part1 gboorse$ 
*/