#ifndef MYTIME_H
#define MYTIME_H

#include <database.h>

using namespace std;


class myTime
{
public:
    myTime();
    ~myTime();

    //kalla í allt
    string pullDate ();
    string pullTime ();

private:
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int intMonth = 1 + (ltm->tm_mon);
    void getMonth(int choice);
    string month;
    int intDay = ltm->tm_mday;
    string day = to_string(intDay);
    int intYear = 1900 + ltm->tm_year;
    string sYear = to_string(intYear);
    string date = day + "." + month + "." + sYear;

    int intHours = 1 + ltm->tm_hour;
    string hours = to_string(intHours);
    int intMin = 1 + ltm->tm_min;
    string min = to_string(intMin);
    int intSec = 1 + ltm->tm_sec;
    string sec = to_string(intSec);
    string wholeTime = hours + ":" + min;
};

#endif // MYTIME_H
