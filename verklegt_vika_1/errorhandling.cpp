#include "errorhandling.h"
#include <iostream>

using namespace std;


ErrorHandling::ErrorHandling()
{

}
ErrorHandling::~ErrorHandling ()
{

}

/**********************************************************
                   ERRORS AND ERROR MESSAGES
 **********************************************************/


void ErrorHandling::dataWriteError ()
{
    cout << "No database found!" << endl;
}

void ErrorHandling::dataSearchNotFound ()
{
    cout << "No items found" << endl;
}

void ErrorHandling::invalidName (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            cout << "The name you entered is already exists in the list" << endl;
            break;
        case 2:
            cout << "Name can not include numbers" << endl;
            break;
    }
}

void ErrorHandling::invalidSex ()
{
    cout << "Sex must be either Male or Female" << endl;
}

void ErrorHandling::invalidYear (int errorCode)
{
    switch (errorCode)
    {
        case 1:
            cout << "Year of death can not be before year of birth" << endl;
            break;

        case 2:
            cout << "The Computer Scientst can not be born in the future" << endl;
            break;

        case 3:
            // Ath ad thessi dude faer samt ad halda afram i forritinu!!
            cout << "Are you sure you want to add a Computer Scientist that was born before Christ? " << endl;
            break;
        case 4:
            cout << "Invalid characters in year." << endl;
            break;
    }
}
