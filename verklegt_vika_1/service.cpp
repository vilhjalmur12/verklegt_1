#include "service.h"

using namespace std;

Service::Service()
{
    database dat;
    data = dat;

    ErrorHandling err;
    throwError = err;

    data.getData(user);
    _scientists = data.pullData();
   // cout << _scientists[0].getName();
}

Service::Service(string username)
{
    user = username;
    database dat;
    data = dat;

    ErrorHandling err;
    throwError = err;

    data.getData(user);
    _scientists = data.pullData();
   // cout << _scientists[0].getName();
}

Service::~Service()
{
    
}

void pushUser (string username)
{

}

/**********************************************************
                   Vinna með vísindamenn
**********************************************************/

void Service::saveData ()
{
    data.pushData(_scientists);
    data.writeData(user);
}

string Service::removeSpaces(string& before)
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

//Stillir fyrsta staf hvers orðs stóran og hina litla
string Service::fixString(string& before)
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

    before = removeSpaces(before);
    return before;
}

bool Service::appendScientist(string name, string sex, int birthYear, int deathYear, string nationality, string furtherInfo)
{
    Scientist tempScientist(name, sex, birthYear, deathYear, nationality, furtherInfo);
    for(unsigned int i = 0; i < _scientists.size(); i++)
    {
        if(tempScientist == _scientists[i])
        {
            throwError.invalidName(1);
            return false;
        }
    }
    _scientists.push_back(tempScientist);

    return true;
}

void Service::removeScientist(const int index)
{
    _scientists.erase(_scientists.begin()+index);
}

void Service::moveLastTo(int index)
{
    _scientists[index] = _scientists.back();
    _scientists.pop_back();
}

vector<Scientist> Service::getScientists()
{
    return _scientists;
}

int Service::getLengthOfData()
{
    return _scientists.size();
}

void Service::SortedScientistsBy(string choice)
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
    if (choice == "nta")
        sortByNationalityAscending();
    if (choice == "ntd")
        sortByNationalityDescending();
}

/**********************************************************
                   Villumeldingar
**********************************************************/

bool Service::validName(string &name)
{
    name = fixString(name);

    bool containsDigits = !regex_match(name, regex("^[A-Za-z]+[ ]*([A-Za-z]||[ ])*$"));

    if (containsDigits)
    {
        throwError.invalidName(2);
        return false;
    }
    return true;
}

bool Service::validSex(string& sex)
{
    sex = fixString(sex);

    if(sex == "M"||sex == "Male")
    {
        sex = "Male";
        return true;
    }

    if(sex == "F"||sex == "Female")
    {
        sex = "Female";
        return true;
    }

    else
    {
        throwError.invalidSex();
        return false;
    }
}

bool Service::validYears(int birthYear, int deathYear)
{
    //Pointer heldur utan um núverandi ár -1900
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(birthYear < -193000)
    {
        throwError.invalidYear(3);
        return false;
    }

    if(deathYear < birthYear)
    {
        throwError.invalidYear(1);
        return false;
    }
        //pointer + 1900 == núverandi ár
    if(birthYear > timePtr->tm_year + 1900)
    {
        throwError.invalidYear(2);
        return false;
    }
    if(birthYear == maxDeathYear)
    {
        return true;
    }
    if(deathYear > timePtr->tm_year + 1900)
    {
        throwError.invalidYear(5);
        return false;
    }

    return true;
}

bool Service::validNationality(string& nationality)
{
    nationality = fixString(nationality);

    bool containsDigits = !regex_match(nationality, regex("^[A-Za-z]+[ ]*([A-Za-z]||[ ])*$"));

    if (containsDigits)
    {
        throwError.invalidNationality(1);
        return false;
    }
    return true;
}

/**********************************************************
                 Hjálparföll fyrir search
**********************************************************/

//Leitar í gagnagrunn eftir öld
bool Service::findInInt(int query, int year)
{
    int century = (year / 100)*100;
    int decade = (year/10)*10;

    if(query == century || query == decade)
        return true;
    if(query == year)
        return true;
    return false;
}

bool Service::findInString(string query, string String)
{
    transform(query.begin(), query.end(), query.begin(), ::tolower);
    transform(String.begin(), String.end(), String.begin(), ::tolower);

    if(query.length() > String.length())
        return false;
    else if(query.length() == String.length())
    {
        return !String.compare(0, query.length(), query);
    }

    for(unsigned int i = 0; i < (String.length() - query.length()); i++)
    {
        if(!String.compare(i, query.length(), query))
            return true;
    }

    return false;
}

//Leitarvél sem skilar index-um í gagnagrunn
vector<int> Service::getIndexesWith(string query)
{
    vector<int> foundScientists;

    if (string::npos != query.find_first_of("0123456789"))
    {
        int year = stoi(query); // String í int

        for (unsigned int i = 0; i < _scientists.size(); i++)
        {
            if (findInInt(year, _scientists[i].getYearOfBirth()) || findInInt(year, _scientists[i].getYearOfDeath()))
            {
                foundScientists.push_back(i);
            }
        }    
    }
    else
    {
        for (unsigned int i = 0; i < _scientists.size(); i++)
        {
            if (findInString(query, _scientists[i].getName()) || findInString(query, _scientists[i].getSex()) || findInString(query, _scientists[i].getFurtherInfo()))
            {
                foundScientists.push_back(i);
            }
        }
    }

    return foundScientists;
}

/**********************************************************
                   Struct til að sortera
**********************************************************/

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

struct nationalityAscending
{
    bool operator() (Scientist i, Scientist j) { return (i.getNationality()<j.getNationality());}
};

struct nationalityDescending
{
    bool operator() (Scientist i, Scientist j) { return (i.getNationality()>j.getNationality());}
};
/**********************************************************
              Sorting algrímar - getScientist
**********************************************************/

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

void Service::sortByNationalityAscending()
{
    nationalityAscending nta;
    sort(_scientists.begin(), _scientists.end(), nta);
}

void Service::sortByNationalityDescending()
{
    nationalityDescending ntd;
    sort(_scientists.begin(), _scientists.end(), ntd);
}
