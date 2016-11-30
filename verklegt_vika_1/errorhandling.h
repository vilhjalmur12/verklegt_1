#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

#include "console.h"

class ErrorHandling
{
public:
    ErrorHandling();
    virtual ~ErrorHandling();
    void dataWriteError ();  // villi: error output fyrir database
    void quit();   // quit fall ef við vijum hætta í forriti
    string str = stringChoice();
    void dataSearchNotFound ();
    void invalidYear (int errorCode);
    void invalidSex ();
    void invalidName (int errorCode);
private:

};

#endif // ERRORHANDLING_H
