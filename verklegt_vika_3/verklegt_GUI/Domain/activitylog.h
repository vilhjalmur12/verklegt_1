#ifndef ACTIVITYLOG_H
#define ACTIVITYLOG_H

#include "../DATA/database.h"
#include <fstream>
#include "mytime.h"

class activityLog
{
public:
    activityLog();
    activityLog(string username);
    ~activityLog();
    void pushActivity (string action, Scientist _scientistFrom, Scientist _scientistTo);
    void pushActivity (string action, Scientist _scientistFrom);
    void pushActivity (string action, Computer _computerFrom, Computer _computerTo);
    void pushActivity (string action, Computer _computerFrom);
    void pushActivity (string action, CpuType _cpuType);

private:
    string user;
    ifstream activityInput;
    ofstream activityOutput;
    MyTime time;
    string date;
    string timeNow;

    void openInStream();
    void openOutStream();

};

#endif // ACTIVITYLOG_H
