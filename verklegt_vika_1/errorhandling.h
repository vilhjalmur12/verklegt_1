#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

class ErrorHandling
{
public:
    ErrorHandling();
    virtual ~ErrorHandling();
    void dataWriteError ();
    void quit();
    void dataSearchNotFound ();
    void invalidYear (int errorCode);
    void invalidSex ();
    void invalidName (int errorCode);

private:

};

#endif // ERRORHANDLING_H
