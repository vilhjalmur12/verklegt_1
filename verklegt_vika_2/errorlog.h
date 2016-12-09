#ifndef ERRORLOG_H
#define ERRORLOG_H

#include "database.h"
#include <fstream>
#include "mytime.h"


using namespace std;

class errorLog
{
public:
    errorLog();
    errorLog(string username, string tmpError, bool tmpBrute);
    ~errorLog();
    void openInStream();
    void openOutStream();
    void pushError();

private:
    string user;
    string error;
    string warning = "*WARNING*";
    bool brute;
    ifstream errorInput;
    ofstream errorOutput;
    myTime time;
    string date;
    string timeNow;
};

#endif // ERRORLOG_H
