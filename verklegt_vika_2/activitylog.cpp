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
    string tmpUser = user;
    tmpUser.erase(tmpUser.begin(), tmpUser.end());
    string logName = "." + tmpUser + "_activity";

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
    string tmpUser = user;
    tmpUser.erase(tmpUser.begin(), tmpUser.end());
    string logName = "." + tmpUser + "_activity";
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
    string actionOut = "[" + action +"]";

       activityOutput << user << "\t" << date << "\t" << timeNow << "\t" << actionOut << endl;
       activityOutput << "From: \t" <<  _scientistFrom.getFirstName() << "\t" << _scientistFrom.getLastName() << "\t" << _scientistFrom.getSex() << "\t" << _scientistFrom.getYearOfBirth() << "\t" << _scientistFrom.getYearOfDeath() << "\t" << _scientistFrom.getNationality() << "\t" << _scientistFrom.getFurtherInfo() << endl;
       activityOutput << "To: \t" <<  _scientistTo.getFirstName() << "\t" << _scientistTo.getLastName() << "\t" << _scientistTo.getSex() << "\t" << _scientistTo.getYearOfBirth() << "\t" << _scientistTo.getYearOfDeath() << "\t" << _scientistTo.getNationality() << "\t" << _scientistTo.getFurtherInfo() << endl;

    activityOutput.close();
}

void activityLog::pushActivity (string action, Scientist _scientistFrom)
{
    openOutStream();
    string actionOut = "[" + action +"]";

       activityOutput << user << "\t" << date << "\t" << timeNow << endl;
       activityOutput << actionOut << "\t" <<  _scientistFrom.getFirstName() << "\t" << _scientistFrom.getLastName() << "\t" << _scientistFrom.getSex() << "\t" << _scientistFrom.getYearOfBirth() << "\t" << _scientistFrom.getYearOfDeath() << "\t" << _scientistFrom.getNationality() << "\t" << _scientistFrom.getFurtherInfo() << endl;

    activityOutput.close();
}

void activityLog::pushActivity (string action, Computer _computerFrom, Computer _computerTo)
{
    openOutStream();
    string actionOut = "[" + action +"]";

       activityOutput << user << "\t" << date << "\t" << timeNow << "\t" << actionOut << endl;
       activityOutput << "From: \t" <<  _computerFrom.getName() << "\t" << _computerFrom.getCpuType() << "\t" << _computerFrom.getBuilt() << "\t" << _computerFrom.getYearBuilt() << endl;
       activityOutput << "To: \t" <<  _computerTo.getName() << "\t" << _computerTo.getCpuType() << "\t" << _computerTo.getBuilt() << "\t" << _computerTo.getYearBuilt() << endl;

    activityOutput.close();
}

void activityLog::pushActivity (string action, Computer _computerFrom)
{
    openOutStream();
    string actionOut = "[" + action +"]";

       activityOutput << user << "\t" << date << "\t" << timeNow << endl;
       activityOutput << actionOut << "\t" <<  _computerFrom.getName() << "\t" << _computerFrom.getCpuType() << "\t" << _computerFrom.getBuilt() << "\t" << _computerFrom.getYearBuilt() << endl;

    activityOutput.close();
}

void activityLog::pushActivity (string action, CpuType _cpuType)
{
    openOutStream();
    string actionOut = "[" + action +"]";

       activityOutput << user << "\t" << date << "\t" << timeNow << endl;
       activityOutput << actionOut << "\t" <<  _cpuType.getType() << endl;

    activityOutput.close();
}
