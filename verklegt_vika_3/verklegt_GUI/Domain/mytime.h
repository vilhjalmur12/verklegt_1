#ifndef MYTIME_H
#define MYTIME_H

#include "../DATA/database.h"

using namespace std;


class MyTime
{
public:
    MyTime();
    virtual ~MyTime();
/**************************************************

**************************************************/
    string pullDate ();
    string pullTime ();

private:
/**************************************************
                 Meðlimabreytur
**************************************************/
    time_t now;
    tm *ltm;
    int intMonth;
    void getMonth(int choice);
    string month;
    int intDay;
    string day;
    int intYear;
    string sYear;
    string date;

    int intHours;
    string hours;
    int intMin;
    string min;
    int intSec;
    string sec;
    string wholeTime;
};

#endif // MYTIME_H
