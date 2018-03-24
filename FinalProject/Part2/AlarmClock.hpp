#pragma once

#include <time.h>
#include <iostream>
#include <stdio.h>

using namespace std;


class AlarmClock
{
    //"Actual" clock time
    int clock_hours;
    int clock_minutes;
    int clock_seconds;
    bool clock_AM_PM; //true is PM

    //alarm clock set time
    int alarm_hours;
    int alarm_minutes;
    int alarm_seconds;
    bool alarm_AM_PM;

    bool alarm_activated;

    void output_alarm()
    {
        cout << "WAKE UP!!!" << endl;
    }

    //should we sound the alarm?
    bool check_alarm()
    {
        return alarm_activated && 
            (clock_hours == alarm_hours) &&
            (clock_minutes == alarm_minutes) &&
            (clock_seconds == alarm_seconds) &&
            (clock_AM_PM == alarm_AM_PM);
    }

  public:

    //alarm is set to midnight by default
    //deactivated
    AlarmClock()
    {
        alarm_hours = 12;
        alarm_minutes = 0;
        alarm_seconds = 0;
        alarm_AM_PM = false;

        alarm_activated = false;

        set_current_time();

    }

    //create alarm clock with custom alarm time
    //deactivated
    AlarmClock(int hours, int mins, int seconds, bool am_pm)
    {
        alarm_hours = hours;
        alarm_minutes = mins;
        alarm_seconds = seconds;
        alarm_AM_PM = am_pm;

        alarm_activated = false;

        set_current_time();

    }

    void on() //activated alarm
    {
        alarm_activated = true; 
    }
    void off() //deactivated alarm
    {
        alarm_activated = false;
    }

    void tick() //increment clock time by 1 second
    {
        clock_seconds++; 

        if (clock_seconds >= 60)
        {
            clock_seconds = 0;
            clock_minutes++;
        }

        bool hour_change = (clock_minutes >= 60);

        if (hour_change)
        {
            clock_minutes = 0;
            clock_hours++;

            if (clock_hours > 12)
            {
                clock_hours = 1;
            }
        }

        if (hour_change && clock_hours == 12)
        {
            clock_AM_PM = !clock_AM_PM; //switch AM/PM flag
        }

        if (check_alarm()) //is it time yet?
        {
            //if we have ticked until the alarm time, ring the alarm
            output_alarm();
        }

    }

    //set clock time based on actual time
    void set_current_time()
    {
        time_t theTime = time(NULL);
        struct tm *aTime = localtime(&theTime);
        clock_hours = aTime->tm_hour;
        clock_minutes = aTime->tm_min;    
        clock_seconds = aTime->tm_sec; 

        if (clock_hours == 0)
        {
            clock_hours = 12;
            clock_AM_PM = false;
        }
        if (clock_hours > 12)
        {
            clock_hours -= 12;
            clock_AM_PM = true;
        }
    }

    //manually set clock time
    void set_clock_time(int hours, int mins, int seconds, bool am_pm)
    {
        clock_hours = hours;
        clock_minutes = mins;
        clock_seconds = seconds;
        clock_AM_PM = am_pm;
    }

    //manually set alarm time
    void set_alarm_time(int hours, int mins, int seconds, bool am_pm)
    {
        alarm_hours = hours;
        alarm_minutes = mins;
        alarm_seconds = seconds;
        alarm_AM_PM = am_pm;
    }

    //output alarm time
    void print_alarm_time()
    {
        printf ("Alarm: %02d:%02d:%02d ", alarm_hours, alarm_minutes, alarm_seconds);
        if (alarm_AM_PM)
        {
            printf("PM\n");
        }
        else
        {
            printf("AM\n");
        }
    }

    //output clock time
    void print_clock_time()
    {
        printf ("Clock: %02d:%02d:%02d ", clock_hours, clock_minutes, clock_seconds);
        if (clock_AM_PM)
        {
            printf("PM\n");
        }
        else
        {
            printf("AM\n");
        }
    }

    //individual getters if we want them

    //clock

    int cHours() { return clock_hours; }

    int cMinutes() { return clock_minutes; }

    int cSeconds() { return clock_seconds; }

    bool cAMPM() { return clock_AM_PM; }

    //alarm

    int aHours() { return alarm_hours; }

    int aMinutes() { return alarm_minutes; }

    int aSeconds() { return alarm_seconds; }

    bool aAMPM() { return alarm_AM_PM; }
    

};

