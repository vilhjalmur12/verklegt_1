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
    errorMessage = "ERROR: No database found!\n";
}

void ErrorHandling::dataSearchNotFound ()
{
    errorMessage = "ERROR: No items found!\n";
}

void ErrorHandling::invalidName (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            errorMessage = "ERROR: The name you entered already exists in the list!\n";
            break;
        case 2:
            errorMessage = "ERROR: Name includes unsupported characters!\n";
            break;
    }
}

void ErrorHandling::invalidSex ()
{
    errorMessage = "ERROR: Gender has to be either male or female!\n";
}

void ErrorHandling::invalidYear (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            errorMessage = "ERROR: Year of death can not be before year of birth!\n";
            break;
        case 2:
            errorMessage = "ERROR: The Computer Scientist can not be born in the future!\n";
            break;
        case 3:
            errorMessage = "ERROR: Computer Scientist couldn't have been born before the ascent of Homo Sapiens!\n";
            break;
        case 4:
            errorMessage = "ERROR: Invalid characters in year of birth!\n";
            break;
        case 5:
            errorMessage = "ERROR: Death can not be registered for a future date!\n";
            break;
        case 6:
            errorMessage = "ERROR: Invalid characters in year of death!\n";
            break;
    }
}

void ErrorHandling::invalidNation()
{
    errorMessage = "ERROR: Invalid characters in nationality!\n";
}

string ErrorHandling::catchError()
{
    string tmpError = errorMessage;
    errorMessage = "";
    return tmpError;
}
