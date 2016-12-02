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
    void dataWriteError ();             // Skilar út villu skilaboðum á console glugga fyrir ófundinn gagnagrunn
    void dataSearchNotFound ();         // Skilar út villu skilaboðum á console glugga fyrir leitarvél
    void invalidYear (int errorCode);   // Skilar út villu skilaboðum á console glugga ef ekki er valið rétt ártal
    void invalidSex ();                 // Skilar út villu skilaboðum á console glugga ef ekki er gefið karlkyn eða kvenkyn í kyn vali
    void invalidName (int errorCode);   // Skilar út villu skilaboðum á console glugga ef nafn sé þegar til staðar á listanum
    string catchError();                // endurstillir á errorMessage meðlimabreytu

private:
    string errorMessage;
};

#endif // ERRORHANDLING_H
