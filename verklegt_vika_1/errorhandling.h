#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

#include <string>
#include <iostream>

using namespace std;

class ErrorHandling
{
public:
    ErrorHandling();
    virtual ~ErrorHandling();

/**********************************************************
                  Villuskilaboð
**********************************************************/
    void dataWriteError ();
    void dataSearchNotFound ();
    void invalidYear (int errorCode);
    void invalidSex ();
    void invalidName (int errorCode);

    string catchError();

private:
    string dataWritingError;
    string dataSearchError;
    string dataYearError;
    string dataSexError;
    string dataNameError;

};

#endif // ERRORHANDLING_H
