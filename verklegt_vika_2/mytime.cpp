#include "mytime.h"

myTime::myTime()
{
    // now = time(0);
    // ltm = localtime(&now);
    intMonth = 1 + (ltm->tm_mon);
    getMonth(intMonth);
    intDay = ltm->tm_mday;
    day = to_string(intDay);
    intYear = 1900 + ltm->tm_year;
    sYear = to_string(intYear);
    date = day + "." + month + "." + sYear;
    intHours = 1 + ltm->tm_hour;
    hours = to_string(intHours);
    intMin = 1 + ltm->tm_min;
    min = to_string(intMin);
    intSec = 1 + ltm->tm_sec;
    sec = to_string(intSec);
    wholeTime = hours + ":" + min;
}

myTime::~myTime() { }

void myTime::getMonth(int choice)
{
    switch (choice)
    {
        case 1:
            month = "January";
            break;
        case 2:
            month = "February";
            break;
        case 3:
            month = "March";
            break;
        case 4:
            month = "April";
            break;
        case 5:
            month = "May";
            break;
        case 6:
            month = "June";
            break;
        case 7:
            month = "July";
            break;
        case 8:
            month = "August";
            break;
        case 9:
            month = "September";
            break;
        case 10:
            month = "October";
            break;
        case 11:
            month = "November";
            break;
        default:
            month = "December";
            break;
    }
}

string myTime::pullDate ()
{
    return date;
}

string myTime::pullTime ()
{
    return wholeTime;
}
