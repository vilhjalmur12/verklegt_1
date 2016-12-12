#include "errorlog.h"

ErrorLog::ErrorLog()
{

}

/****************************************************************************
                        errorLog - smiður
    stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
            @parameter(string username) - nafn á notanda
          @parameter(string tmpError) - tegund tolvu
                    Seinni smiður er auk þess með:
          @parameter(bool tmpBrute) - skilar true eða false eftir því hvort er
            verið að reyna að bruteforce-a password. 3x byrjar það að telja
 ****************************************************************************/

ErrorLog::ErrorLog(string username, string tmpError)
{
    user = "[" + username + "]";
    error = tmpError;
    date = "[" + time.pullDate() + "]";
    timeNow = "[" + time.pullTime() + "]";
}

ErrorLog::ErrorLog(string username, string tmpError, bool tmpBrute)
{
    user = "[" + username + "]";
    error = tmpError;
    brute = tmpBrute;
    date = "[" + time.pullDate() + "]";
    timeNow = "[" + time.pullTime() + "]";
    brute = tmpBrute;
}

ErrorLog::~ErrorLog() {}

/****************************************************************************
                        openInStream
    opnar errorlog skrána
 ****************************************************************************/

void ErrorLog::openInStream()
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

void ErrorLog::openOutStream()
{
    string logName = ".error_log";
    errorOutput.open(logName, std::ios::app);
    if (errorOutput.fail())
    {
        fstream newDataInput (logName, std::ios::out);
        newDataInput.close();
        errorOutput.open(logName);
    }
}

void ErrorLog::pushError ()
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


