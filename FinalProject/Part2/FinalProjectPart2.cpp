/*

@author gabriel boorse

Compiled using g++ on CentOS 7 Linux
s
Use:

g++ -std=c++11 FinalProjectPart2.cpp -o FinalProjectPart2
./FinalProjectPart2



Output:

[gboorse@localhost Part2]$ ./FinalProjectPart2
---
Alarm: 12:00:00 AM
Clock: 11:59:54 PM
---
---
Alarm: 12:00:00 AM
Clock: 11:59:55 PM
---
---
Alarm: 12:00:00 AM
Clock: 11:59:56 PM
---
---
Alarm: 12:00:00 AM
Clock: 11:59:57 PM
---
---
Alarm: 12:00:00 AM
Clock: 11:59:58 PM
---
---
Alarm: 12:00:00 AM
Clock: 11:59:59 PM
---
---
WAKE UP!!!
Alarm: 12:00:00 AM
Clock: 12:00:00 AM
---
---
Alarm: 12:00:00 AM
Clock: 12:00:01 AM
---

*/

#include <iostream>
#include <chrono>
#include <thread>
#include "AlarmClock.hpp"
using namespace std;


int main()
{
	// this is obviously a trivial example of how to use the class
	// there's a lot more you could do with it


	AlarmClock a; //this is our alarm clock, defaults to midnight alarm
	a.set_clock_time(11, 59, 53, true); //set "actual time" to 11:59:53 pm

	a.on(); //turn on the alarm, otherwise won't alert us

	for (int i = 0; i < 8; i++) //tick for 8sec
	{
		this_thread::sleep_for(chrono::milliseconds(1000)); //sleep 1 second
		cout << "---" << endl;
		a.tick(); //incrememt clock by 1 sec
		a.print_alarm_time(); //output times
		a.print_clock_time();
		cout << "---" << endl;

	}

	return 0;

}