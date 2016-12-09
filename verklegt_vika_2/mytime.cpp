#include "mytime.h"

MyTime::MyTime()
{

    //now = time(0);
    //ltm = localtime(&now);
    intMonth = 1 + (ltm->tm_mon);
    getMonth(intMonth);
    intDay = ltm->tm_mday;
    day = to_string(intDay);
    intYear = 1900 + ltm->tm_year;
    sYear = to_string(intYear);
    date = day + "." + month + "." + sYear;
    intHours = ltm->tm_hour;
    hours = to_string(intHours);
    intMin = 1 + ltm->tm_min;
    if (intMin < 10)
    {
        min = "0"+to_string(intMin);
    }
    else
    {
       min = to_string(intMin);
    }
    intSec = 1 + ltm->tm_sec;
    sec = to_string(intSec);
    wholeTime = hours + ":" + min;
}

MyTime::~MyTime() { }

void MyTime::getMonth(int choice)
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

string MyTime::pullDate ()
{
    return date;
}

string MyTime::pullTime ()
{
    return wholeTime;
}
