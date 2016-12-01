#include "errorhandling.h"
#include <iostream>

using namespace std;


ErrorHandling::ErrorHandling() { }
ErrorHandling::~ErrorHandling (){ }

/**********************************************************
                   ERRORS AND ERROR MESSAGES
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
            cout << "ERROR: Name can not include numbers!" << endl;
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
            cout << "Are you sure you want to add a Computer Scientist that was born before Christ?" << endl;
            break;
        case 4:
            cout << "ERROR: Invalid characters in year!" << endl;
            break;
        case 5:
            cout << "ERROR: Death can not be registered for a future date!" << endl;
            break;
    }
}
