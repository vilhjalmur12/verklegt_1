#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include "database.h"
#include <fstream>
#include "mytime.h"

class activityLog
{
public:
    activityLog();
    activityLog(string username);
    ~activityLog();
    void pushActivity (string action, Scientist _scientistFrom, Scientist _scientistTo);

private:
    string user;
    ifstream activityInput;
    ofstream activityOutput;
    myTime time;
    string date;
    string timeNow;

    void openInStream();
    void openOutStream();

};

#endif // ACTIVITYLOG_H
