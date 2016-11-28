#include "service.h"

Service::Service()
{
 // Hlytur ad virka
}

string Service::removeSpaces(string before)
{
    if(before.at(0) == ' ')
        return true;
}

string Service::fixString(string before)
{

    char a = before.at(0);
    before.at(0) = toupper(a);

    for(unsigned int i = 1; i < before.length(); i++)
    {
        a = before.at(i);
        before.at(i) = tolower(a);

        if(before.at(i-1) == ' ')
        {
            a = before.at(i);
            before.at(i) = toupper(a);
        }
    }
}

bool Service::addName(string name, vector<string> &names)
{
    bool containsDigits = !regex_match(name, regex("^[A-Za-z]+$"));
    if (containsDigits)
        return false;
    else names.push_back(fixString(name));
}

bool Service::addSex(string sex, vector<string> &sexes)
{

}

void Service::addPerson(string name, string sex, int birthYear, int deathYear, vector<string> &names, vector<string> &sexes, vector<int> &birthYears, vector<int> &deathYears)
{
    if(!addName(name, names))
    {
        cout << "Invalid Name!";
        return;
    }

}
