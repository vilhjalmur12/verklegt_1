#include "activitylog.h"

activityLog::activityLog()
{

}

activityLog::activityLog(string username)
{
    user = "[" + username + "]";
    date = "[" + time.pullDate() + "]";
    timeNow = "[" + time.pullTime() + "]";
}

activityLog::~activityLog()
{

}

void activityLog::openInStream()
{
    string logName = "." + user + "_activity";

    activityInput.open(logName);
    if (activityInput.fail())
    {
        fstream newDataInput (logName, std::ios::out);
        newDataInput.close();
        activityInput.open(logName);
    }
}

void activityLog::openOutStream()
{
    string logName = "." + user + "_activity";
    activityOutput.open(logName, std::ios::app);
    if (activityOutput.fail())
    {
        fstream newDataInput (logName, std::ios::out);
        newDataInput.close();
        activityOutput.open(logName);
    }
}

void activityLog::pushActivity (string action, Scientist _scientistFrom, Scientist _scientistTo)
{
    openOutStream();

       activityOutput << user << "\t" << date << "\t" << timeNow << "\t" << action << "\t" << "From: " + _scientistFrom.getFirstName()
                   + " To: " + _scientistTo.getFirstName() <<  "\t" << "\t" << "From: " + _scientistFrom.getLastName()
                   + " To: " + _scientistTo.getLastName() << endl;

    activityOutput.close();
}


