#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

class ErrorHandling
{
public:
    ErrorHandling();
    virtual ~ErrorHandling();
    void dataWriteError ();  // villi: error output fyrir database
    void quit();   // quit fall ef við vijum hætta í forriti
    void dataSearchNotFound ();
    void invalidYear (int errorCode);
    void invalidSex ();
    void invalidName (int errorCode);

private:

};

#endif // ERRORHANDLING_H
