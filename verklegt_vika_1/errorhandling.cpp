#include "errorhandling.h"
#include <iostream>

using namespace std;

ErrorHandling::ErrorHandling() { }
ErrorHandling::~ErrorHandling (){ }

/**********************************************************
                   Villuskilaboð
 **********************************************************/

void ErrorHandling::dataWriteError ()
{
    cout << "ERROR: No database found!" << endl;
    errorMessage = "ERROR: No database found!/n";
}

void ErrorHandling::dataSearchNotFound ()
{
    cout << "ERROR: No items found!" << endl;
    errorMessage = "ERROR: No items found!/n";
}

void ErrorHandling::invalidName (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            cout << "ERROR: The name you entered already exists in the list!" << endl;
            errorMessage = "ERROR: The name you entered already exists in the list!/n";
            break;
        case 2:
            cout << "ERROR: Name includes unsupported characters!" << endl;
            errorMessage = "ERROR: Name includes unsupported characters!/n";
            break;
    }
}

void ErrorHandling::invalidSex ()
{
    cout << "ERROR: Gender has to be either male or female!" << endl;
    errorMessage = "ERROR: Gender has to be either male or female!/n";
}

void ErrorHandling::invalidYear (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            cout << "ERROR: Year of death can not be before year of birth!" << endl;
            errorMessage = "ERROR: Year of death can not be before year of birth!/n";
            break;
        case 2:
            cout << "ERROR: The Computer Scientist can not be born in the future!" << endl;   /// VANTAR VILLUCHECK
            errorMessage = "ERROR: The Computer Scientist can not be born in the future!/n";
            break;
        case 3:
            cout << "ERROR: The Computer Scientist couldn't have been born before the ascent of Homo Sapiens!" << endl;
            errorMessage = "ERROR: Computer Scientist couldn't have been born before the ascent of Homo Sapiens!/n";
            break;
        case 4:
            cout << "ERROR: Invalid characters in year!" << endl;
            errorMessage = "ERROR: Invalid characters in year!/n";
            break;
        case 5:
            cout << "ERROR: Death can not be registered for a future date!" << endl;
            errorMessage = "ERROR: Death can not be registered for a future date!/n";
            break;
    }
}

string ErrorHandling::catchError()
{
    string tmpError = errorMessage;
    errorMessage = "";
    return tmpError;
}
