#include "service.h"
#include <algorithm>
#include <ctime>

using namespace std;


Service::Service()
{

}

//Stillir fyrsta staf hvers ords storan og hina litla
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

    return before;
}

bool Service::addName(string name, vector<string> &names)
{
    name = fixString(name);

    //Athugar hvort takn seu til stadar sem ekki eru stafir
    //Tharf ad laga svo ad bil seu leyfd
    bool containsDigits = !regex_match(name, regex("^[A-Za-z]+$"));

    for(int i = 0; i < names.size(); i++)
    {
        if(names[i] == name)
            return false;
    }

    if (containsDigits)
        return false;
    else names.push_back(name);

    return true;
}

bool Service::addSex(string sex, vector<string> &sexes)
{
    sex = fixString(sex);

    if(sex != "Male" && sex != "Female")
        return false;

    else sexes.push_back(sex);

    return true;
}

bool Service::addYears(int birthYear, int deathYear, vector<int> &birthYears, vector<int> &deathYears)
{
    //Pointer heldur utan um nuverandi ar -1900
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(deathYear < birthYear)
        return false;
    //pointer + 1900 == nuverandi ar
    if(birthYear > timePtr->tm_year + 1900 || deathYear > > timePtr->tm_year + 1900)
        return false;
    else
    {
        birthYears.push_back(birthYear);
        deathYears.push_back(birthYear);
    }
    return true;
}


//Temp cout setningar fyrir villur, finna leið til að láta skilaboð berast til console
void Service::addPerson(string name, string sex, int birthYear, int deathYear, vector<string> &names, vector<string> &sexes, vector<int> &birthYears, vector<int> &deathYears)
{
    // Fallið skilar false ef inntak inniheldur tölu eða er nú þegar til
    if(!addName(name, names))
    {
        cout << "Invalid Name!";
        return;
    }
    // Skilar false ef eitthvað fer úrskeiðis
    if(!addSex(sex, sexes))
    {
        cout << "Invalid Sex!";
        return;
    }
    // Skilar false ef eitthvað fere úrskeiðis
    if(!addYears(birthYear, deathYear, birthYears, deathYears))
    {
        cout << "Invalid Dates!";
        return;
    }

}

void Service::sort(string choice, vector<string> &names, vector<string> &sexes, vector<int> &birthYears, vector<int> &deathYears)
{
    if (choice == "na")
        sortByNameAscending(names, sexes, birthYears, deathYears);
    if (choice == "nd")
        sortByNameDesending(names, sexes, birthYears, deathYears);
    if (choice == "gf")
        sortBySexF(names, sexes, birthYears, deathYears);
    if (choice == "gm")
        sortbySexM(names, sexes, birthYears, deathYears);
    if (choice == "ba")
        sortByBirthAscending(names, sexes, birthYears, deathYears);
    if (choice == "bd")
        sortByBirthDescending(names, sexes, birthYears, deathYears);
    if (choice == "da")
        sortByDeathAscending(names, sexes, birthYears, deathYears);
    if (choice == "dd")
        sortByDeathDescending(names, sexes, birthYears, deathYears);
}

void Service::switchPerson(index1, index2, vector<string> &names, vector<string> &sexes, vector<int> &birthYears, vector<int> &deathYears)


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

void Service::sortByNameDesending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears)
{
    for(int i = 0; i < names.size() - 1; i++)
    {

    }
}

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
