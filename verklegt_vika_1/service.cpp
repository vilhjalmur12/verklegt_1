#include "service.h"
#include "database.h"
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

bool Service::addName(string name)
{
    name = fixString(name);

    //Athugar hvort takn seu til stadar sem ekki eru stafir
    //Tharf ad laga svo ad bil seu leyfd
    bool containsDigits = !regex_match(name, regex("^[A-Za-z]+[ ]+([A-Za-z]+[ ])*+$"));

    for(unsigned int i = 0; i < _scientists.size(); i++)
    {
        if(_scientists[i].getName() == name)
            return false;
    }

    if (containsDigits)
        return false;

    return true;
}

bool Service::addSex(string sex)
{
    sex = fixString(sex);

    if(sex != "Male" && sex != "Female")
        return false;

    return true;
}

bool Service::addYears(int birthYear, int deathYear)
{
    //Pointer heldur utan um nuverandi ar -1900
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(deathYear < birthYear)
        return false;
    //pointer + 1900 == nuverandi ar
    if(birthYear > timePtr->tm_year + 1900 || deathYear > timePtr->tm_year + 1900)
        return false;

    return true;
}


//Temp cout setningar fyrir villur, finna leið til að láta skilaboð berast til console
void Service::addPerson(string name, string sex, int birthYear, int deathYear)
{
    // Fallið skilar false ef inntak inniheldur óþekktan staf eða er nú þegar til
    if(!addName(name))
    {
        cout << "Invalid Name!";
        return;
    }

    if(!addSex(sex))
    {
        cout << "Invalid Sex!";
        return;
    }

    if(!addYears(birthYear, deathYear))
    {
        cout << "Invalid Dates!";
        return;
    }

    Scientist tempScientist(name, sex, birthYear, deathYear);
    _scientists.push_back(tempScientist);
}

vector<Scientist> Service::getScientists(string choice)
{
    if (choice == "na")
        sortByNameAscending();
    /*
    if (choice == "nd")
        sortByNameDesending();
    if (choice == "gf")
        sortBySexF();
    if (choice == "gm")
        sortbySexM();
    if (choice == "ba")
        sortByBirthAscending();
    if (choice == "bd")
        sortByBirthDescending();
    if (choice == "da")
        sortByDeathAscending();
    if (choice == "dd")
        sortByDeathDescending();
    */

    return _scientists;
}

struct nameAscending {
  bool operator() (Scientist i, Scientist j) { return (i.getName()<j.getName());}
};

void Service::sortByNameAscending()
{
    nameAscending na;
    sort(_scientists.begin(), _scientists.end(), na);
}

struct birthAscending{
    bool operator() (Scientist i, Scientist j) { return (i.getYearOfBirth()<j.getYearOfBirth());}
};

void sortByBirthAscending()
{
    sort(_scientists.begin(), _scientists.end()+4, birthAscending);
}

void sortByBirthDescending();
void sortByDeathAscending();
void sortByDeathDescending();













// Erum her med allan listann i mismunandi butum. Nofnin, kynid, o.s.frv...
/*
void Service::sortByNameAscending()
{
    // Skoda betur hjemme
    for(int i = 0; i < names.size(); i++)
    {
        //if(tolower(names[i])<tolower(names[i+1]))
        //{

        //}
    }

}

void Service::sortByNameDesending()
{
    for(int i = 0; i < names.size() - 1; i++)
    {

    }
}

void Service::sortBySexF()
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
*/
