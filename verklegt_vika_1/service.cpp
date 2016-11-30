#include "console.h"
#include "database.h"
#include "service.h"

using namespace std;

Service::Service()
{
    database* pD = new database;
    _scientists = pD->pullData();
    delete pD;
}

Service::~Service(){ }

string Service::removeSpaces(string before)
{
    for(unsigned int i = 0; i < before.length()-1; i++)
    {
        if(before.at(i) == ' ' && before.at(i+1)==' ')
        {
            before.erase(i, 1);
            return(removeSpaces(before));
        }
    }

    return before;
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

bool Service::validName(string& name)
{
    name = fixString(name);
    Console* pC = new Console();


    for(unsigned int i = 0; i < _scientists.size(); i++)
    {
        if(_scientists[i].getName() == name)
            pC->invalidName(1);
            delete pC;
            return false;
    }

    bool containsDigits = !regex_match(name, regex("^[A-Za-z]+[ ]+([A-Za-z]||[ ])*+$"));

    if (containsDigits)
    {
        pC->invalidName(2);
        delete pC;
        return false;
    }

    delete pC;
    return true;
}

bool Service::validSex(string& sex)
{
    Console* pC = new Console();

    sex = fixString(sex);

    if(sex == "M")
    {
        sex = "Male";
        delete pC;
        return true;
    }

    if(sex == "F")
    {
        sex = "Female";
        delete pC;
        return true;
    }
    else
    {
        pC->invalidSex();
        delete pC;
        return false;
    }

}

bool Service::validYears(int birthYear, int deathYear)
{
    //Pointer heldur utan um nuverandi ar -1900
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    Console pC;

    if(deathYear < birthYear)
    {
        pC.invalidYear(1);
        return false;
    }
        //pointer + 1900 == nuverandi ar
    if(birthYear > timePtr->tm_year + 1900 || deathYear > timePtr->tm_year + 1900)
    {
        pC.invalidYear(2);
        return false;
    }
    if(birthYear < 0)
    {
        pC.invalidYear(3);
        return false;
    }

    return true;
}

void Service::appendScientist(string name, string sex, int birthYear, int deathYear)
{
    Scientist tempScientist(name, sex, birthYear, deathYear);
    _scientists.push_back(tempScientist);

    database* pD = new database;
    pD->pushData(_scientists);
    delete pD;
}

vector<Scientist> Service::getScientists (string choice)
{
    if (choice == "na")
        sortByNameAscending();
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

    return _scientists;
}


/***********************************************
 *                                                *
 *             Struct til að sortera              *
 *                                                *
************************************************/

struct nameAscending
{
  bool operator() (Scientist i, Scientist j) { return (i.getName()<j.getName());}
};

struct nameDescending
{
  bool operator() (Scientist i, Scientist j) { return (i.getName()>j.getName());}
};

struct sexFemale
{
  bool operator() (Scientist i, Scientist j) { return (i.getSex()<j.getSex());}
};

struct sexMale
{
  bool operator() (Scientist i, Scientist j) { return (i.getSex()>j.getSex());}
};

struct birthAscending
{
    bool operator() (Scientist i, Scientist j) { return (i.getYearOfBirth()<j.getYearOfBirth());}
};

struct birthDescending
{
    bool operator() (Scientist i, Scientist j) { return (i.getYearOfBirth()>j.getYearOfBirth());}
};

struct deathAscending
{
    bool operator() (Scientist i, Scientist j) { return (i.getYearOfDeath()<j.getYearOfDeath());}
};

struct deathDescending
{
    bool operator() (Scientist i, Scientist j) { return (i.getYearOfDeath()>j.getYearOfDeath());}
};

/**************************************************
 *                                                *
 *               Föll til að sortera              *
 *                                                *
*///***********************************************

void Service::sortByNameAscending()
{
    nameAscending na;
    sort(_scientists.begin(), _scientists.end(), na);
}

void Service::sortByNameDesending()
{
    nameDescending nd;
    sort(_scientists.begin(), _scientists.end(), nd);
}

void Service::sortBySexF()
{
    sexFemale sf;
    sort(_scientists.begin(), _scientists.end(), sf);
}

void Service::sortbySexM()
{
    sexMale sm;
    sort(_scientists.begin(), _scientists.end(), sm);
}

void Service::sortByBirthAscending()
{
    birthAscending ba;
    sort(_scientists.begin(), _scientists.end(), ba);
}

void Service::sortByBirthDescending()
{
    birthDescending bd;
    sort(_scientists.begin(), _scientists.end(), bd);
}

void Service::sortByDeathAscending()
{
    deathAscending da;
    sort(_scientists.begin(), _scientists.end(), da);
}

void Service::sortByDeathDescending()
{
    deathDescending de;
    sort(_scientists.begin(), _scientists.end(), de);
}
