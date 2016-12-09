#include "errorlog.h"

errorLog::errorLog(string username, string tmpError, bool tmpBrute)
{
    user = "[" + username + "]";
    error = tmpError;
    brute = tmpBrute;
    date = "[" + time.pullDate() + "]";
    timeNow = "[" + time.pullTime() + "]";

}

errorLog::errorLog()
{

}

errorLog::~errorLog() {}

void errorLog::openInStream()
{
    string logName = ".error_log";

    errorInput.open(logName);
    if (errorInput.fail())
    {
        fstream newDataInput (logName, std::ios::out);
        newDataInput.close();
        errorInput.open(logName);
    }
}

void errorLog::openOutStream()
{
    string logName = ".error_log";
    errorOutput.open(logName);
    if (errorOutput.fail())
    {
        fstream newDataInput (logName, std::ios::out);
        newDataInput.close();
        errorOutput.open(logName);
    }
}

void errorLog::pushError ()
{
    openOutStream();

    if (brute)
    {
       errorOutput << user << "\t" << date << "\t" << timeNow << "\t" << error << "\t" << warning
                   << "\t" << "Password brute force detected!" << endl;
    }
    else
    {
        errorOutput << user << "\t" << date << "\t" << timeNow << "\t" << error << endl;
    }
    errorOutput.close();
}


