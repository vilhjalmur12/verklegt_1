#ifndef ERRORLOG_H
#define ERRORLOG_H

#include "database.h"
#include <fstream>


using namespace std;

class errorLog
{
public:
    errorLog();
    ~errorLog();
    void openInStream();
    void openOutStream();
    void pushError();
    void storeError (string username, string tmpError, bool tmpBrute);

private:
    string user;
    string error;
    string warning = "*WARNING*";
    bool brute;
    ifstream errorInput;
    ofstream errorOutput;
};

#endif // ERRORLOG_H
