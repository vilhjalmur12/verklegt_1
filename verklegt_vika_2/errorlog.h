#ifndef ERRORLOG_H
#define ERRORLOG_H

#include "database.h"
#include <fstream>
#include "mytime.h"

using namespace std;

class ErrorLog
{
public:
    ErrorLog();
    ErrorLog(string username, string tmpError);
    ErrorLog(string username, string tmpError, bool tmpBrute);
    virtual ~ErrorLog();

    void openInStream();
    void openOutStream();
    void pushError();

private:
/**************************************************
                  Meðlimabreytur
 **************************************************/
    string user;
    string error;
    string warning = "*WARNING*";
    bool brute = false;
    ifstream errorInput;
    ofstream errorOutput;
    MyTime time;
    string date;
    string timeNow;
};

#endif // ERRORLOG_H
