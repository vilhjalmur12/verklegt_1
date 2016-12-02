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
}

void ErrorHandling::dataSearchNotFound ()
{
    cout << "ERROR: No items found!" << endl;
}

void ErrorHandling::invalidName (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            cout << "ERROR: The name you entered already exists in the list!" << endl;
            break;
        case 2:
            cout << "ERROR: Name includes unsupported characters!" << endl;
            break;
    }
}

void ErrorHandling::invalidSex ()
{
    cout << "ERROR: Gender has to be either male or female!" << endl;
}

void ErrorHandling::invalidYear (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            cout << "ERROR: Year of death can not be before year of birth!" << endl;
            break;
        case 2:
            cout << "ERROR: The Computer Scientist can not be born in the future!" << endl;
            break;
        case 3:
            cout << "ERROR: The Computer Scientist couldn't have been born before the ascent of Homo Sapiens!" << endl;
            break;
        case 4:
            cout << "ERROR: Invalid characters in year!" << endl;
            break;
        case 5:
            cout << "ERROR: Death can not be registered for a future date!" << endl;
            break;
    }
}

void ErrorHandling::invalidNationality(int errorCode)
{
    switch (errorCode)
    {
        case 1:
            cout << "ERROR: Name can not include numbers!" << endl;
            break;
    }
}
