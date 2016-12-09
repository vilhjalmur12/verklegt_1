#ifndef MYTIME_H
#define MYTIME_H

#include <database.h>

using namespace std;


class MyTime
{
public:
    MyTime();
    virtual ~MyTime();

    //kalla í allt
    string pullDate ();
    string pullTime ();

private:
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
