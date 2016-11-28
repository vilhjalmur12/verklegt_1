#include "service.h"
#include <algorithm>

using namespace std;


Service::Service()
{

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

// Erum her med allan listann i mismunandi butum. Nofnin, kynid, o.s.frv...

void Service::sortByNameAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears)
{
    // Skoda betur hjemme
    for(int i = 0; i < names.size(); i++)
    {
        //if(tolower(names[i])<tolower(names[i+1]))
        //{

        //}
    }

}

//void Service::sortByNameDesending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);

void Service::sortBySexF(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears)
{
    for(int i = 0; i < names.size(); i++)
    {
        if(sexes[i] == "f" || sexes[i] == "F")
        {
            string tmp = sexes[i];
            sexes[i] = sexes[i + 1];
            sexes[i+1] = tmp;
        }
    }
}

//void Service::sortbySexM(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByBirthAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByBirthDescending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByDeathAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByDeathDescending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
