#include "service.h"
#include <qsqldatabase.h>
#include <QSqlQuery>

// Ekki vinna med medlimabreytur heldur database-ið = getScientist stuff
using namespace std;
/****************************************************************************
                               Constructor
                        fyllir data objectinn og dælir gildum þaðan í
                        _scientists vectorinn
*****************************************************************************/
Service::Service() { }

Service::Service(const QString user)
{
    qUser = user;
    data.getData(user, _scientists);
}


Service::~Service() { }




/****************************************************************************
                               getErrorString
                     Sækir error message'ið sem er geymt í
                     throw error objectinu, ef enginn
                     error hefur verið skráður þá er
                     strengurinn tómur
 ****************************************************************************/
string Service::getErrorString()
{
    return throwError.catchError();
}

void Service::logYearError(int code)
{
    throwError.invalidYear(code);
}

/****************************************************************************
                               removeSpaces
                     Endurkvæmt fall sem fjarlægir öll
                     bil nema eitt ef þau eru samliggjandi
            @parameter(string before) - strengurinn með bilunum
            @return(string before) - strengurinn þegar búið er að fjarlægja bil
 ****************************************************************************/
string Service::removeSpaces(string before)
{
    for(unsigned int i = 0; i < before.length()-1; i++)
    {
        if(before.at(i) == ' ' && before.at(i+1)==' ')
        {
            before.erase(i,i+1);
            return(removeSpaces(before));
        }
    }
    return before;
}

/****************************************************************************
                               fixString
                     Fall sem tekur streng og passar
                     að fyrstu stafir allra orða séu
                     stórir
            @parameter(string before) - strengurinn fyrir
            @return(string before) - strengurinn þegar búið er að stækka stafi
 ****************************************************************************/
string Service::fixString(string before)
{
    before.at(0) = toupper(before.at(0));

    for(unsigned int i = 1; i < before.length(); i++)
    {
        before.at(i) = tolower(before.at(i));

        if(before.at(i-1) == ' ')
        {
            before.at(i) = toupper(before.at(i));
        }
    }

    before = removeSpaces(before);
    return before;
}

/****************************************************************************
                               appendScientist
                     Býr til vísindamann með fylgibreytum
                     (því sem hann tekur inn)
                     @return true ef vísindamaður er ekki nú þegar til
                     @return false ef vísindamaður er til
            *Til að vísindamaður sé til þurfa allar breytur að
            *vera þær sömu
 ****************************************************************************/
bool Service::appendScientist(string firstName, string lastName, string sex, int birthYear, int deathYear, string nationality, string furtherInfo)
{
    //_scientists = data.getScientists();


    Scientist tempScientist(firstName, lastName, sex, birthYear, deathYear, nationality, furtherInfo);
    for(unsigned int i = 0; i < _scientists.size(); i++)
    {
        if(tempScientist == _scientists[i])
        {
            throwError.invalidName(1);
            return false;
        }
    }

    _scientists.push_back(tempScientist);  // Líklega óþarfi

    data.insertScientist(tempScientist, qUser); //--> Ekki viss með nafnið a´fallinu en þetta verður sirka svona

    return true;
}

bool Service::appendComputer (string name, string cpuType, int yearBuilt, bool built)
{
    Computer tempComputer(name, cpuType, built, yearBuilt);
   /*
    for(unsigned int i = 0; i < _computers.size(); i++)
    {
        if(tempComputer == _computers[i])
        {
            throwError.invalidName(1);
            return false;
        }
    }
    */

    _computers.push_back(tempComputer);  // Líklega óþarfi

    data.insertComputer(tempComputer, qUser); //--> Ekki viss með nafnið a´fallinu en þetta verður sirka svona

    return true;
}

/****************************************************************************
                               removeScientist
                     Fjarlægir vísindamann skv index
            @parameter(const int index) - index þess sem eyða á
 ****************************************************************************/
void Service::removeScientist(int index) // Hvernig tek eg id inn her?
// Remove og EDIT!
// index er tekid inn i edit() fallinu i console
{
    //data.remove(int index)
    QSqlQuery query;

    // Matcha id-id vid thad sem er valid
    // query.prepare("UPDATE scientists set First Name = );
    /* query.bindValue(":ID", ID);
    success = query.exec();

    if(!success)
    {
        qDebug() << "Error: user was not found. ";
    }

    // _scientists.erase(_scientists.begin()+index);*/
}

/****************************************************************************
                               moveLastTo
                     Færir aftasta mann í sæti index
                     minnkar síðan vectorinn um einn
            @parameter(int index) - index sem færa á í
 ****************************************************************************/
void Service::moveLastTo(int index)
{
    //Skoða og finna leið til að hátta þessu fyrir SQL þ.a. hann update'i í hverju skrefi
    _scientists[index] = _scientists.back();
    _scientists.pop_back();
}

vector<Scientist> Service::getScientists(string choice/*="na"*/)
{
    string columnOfChoice;

    if(choice.at(0) == 'n')
        columnOfChoice = "last_name";
    if(choice.at(0) == 'g')
        columnOfChoice = "gender";
    if(choice.at(0) == 'b')
        columnOfChoice = "year_of_birth";
    if(choice.at(0) == 'd')
        columnOfChoice = "year_of_death";
    if(choice.at(0) == 'c')
        columnOfChoice = "nationality";

    if(choice.at(1) == 'd' || choice.at(1) == 'm')
        columnOfChoice += " DESC";

    return data.pullScientists(columnOfChoice);

    //return data.getScientists();
}


vector<Computer> Service::getComputers(string choice)
{
    string columnOfChoice;
    if(choice.at(0) == 'n')
        columnOfChoice = "name";
    if(choice.at(0) == 'y')
        columnOfChoice = "year_of_build";
    if(choice.at(0) == 't')
        columnOfChoice = "type";
    if(choice.at(0) == 'b')
        columnOfChoice = "built_or_not";

    if(choice.at(1) == 'd' || choice.at(1) == 'y')
        columnOfChoice += " DESC";

    return data.pullComputers(columnOfChoice);
}


/****************************************************************************
                               getLengthOfData()
                    skilar fjölda vísindamanna í gagnagrunni
 ****************************************************************************/
int Service::getLengthOfData()
{
    return _scientists.size();
    //Return data.numberOfScientistEntries();
}

/****************************************************************************
                        sortScientistsBy
               Raðar vector vísindamanna í röð eftir því
               sem notandi biður um
        @parameter(string choice) - er "na" by default en annað ef notandi biður um annað
            na=NameAscending, nd=NameDescending o.s.frv.
 ****************************************************************************/
/*
void Service::sortScientistsBy(string choice)
{
    if (choice == "na")
        sortByNameAscending(); // Líklega þyrftu öll föllin að taka inn þennan vector
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
*/

/****************************************************************************
                               validName
                    Athugar hvort að nafn innihaldi skrítin tákn
                    og stækkar fyrsta staf allra orða
            @parameter(string& name) - nafnið, by reference til að breyta
            @return true - ef nafnið er gilt
            @return false - ef nafnið er ógilt
 ****************************************************************************/
bool Service::validName(string &name)
{
    name = fixString(name);

    bool containsDigits = !regex_match(name, regex("(^[A-Za-z.-]+[ ]*([A-Za-z.-]||[ ])*$)"));

    if (containsDigits)
    {
        throwError.invalidName(2);
        return false;
    }
    return true;
}

bool Service::validBuild(string &build)
{

    bool containsDigits = !regex_match(build, regex("(^[A-Za-z.-]+[ ]*([A-Za-z.-]||[ ])*$)"));

    if (containsDigits)
    {
        throwError.invalidName(2);
        return false;
    }
    return true;
}

/****************************************************************************
                               validSex
                     tekur inn kyn og stækkar fyrsta stafinn
                     passar svo að nafn verði annað hvort
                     "Male" eða "Female"
                     @parameter(string& sex) - innslegid kyn
                     @return true - ef kyn er gilt
                     @return false - ef kyn er ógilt
 ****************************************************************************/
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

/****************************************************************************
                               validYears
                     tekur inn bæði ártöl og athugar villur

                     @parameter(int birthYear, int deathYear) - innslegin ár
                     @return true - ef ár eru gild
                     @return false - ef ár eru ógild
 ****************************************************************************/
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

bool Service::validBuildYear(int buildYear)
{
    //Pointer heldur utan um núverandi ár -1900
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(buildYear < -193000)
    {
        throwError.invalidYear(3);
        return false;
    }

    if(buildYear > timePtr->tm_year + 1900)
    {
        throwError.invalidYear(2);
        return false;
    }
    if(buildYear == maxDeathYear)
    {
        return true;
    }

    return true;
}

/****************************************************************************
                               validDeathYear
              athugar hvort innslegið ár innihaldi annað en tölustafi
                     @parameter(string input) - innslegid ár
                     @return true - ef ár er gilt
                     @return false - ef ár er ógilt
 ****************************************************************************/
bool Service::validDeathYear(string input)
{
    return regex_match(input, regex("^[0-9]+[0-9]*$"));
}

/****************************************************************************
                               validNationality

                     @parameter(string n) - innslegid kyn
                     @return true - ef kyn er gilt
                     @return false - ef kyn er ógilt
 ****************************************************************************/
bool Service::validNationality(string& nationality)
{
    nationality = fixString(nationality);

    bool containsDigits = !regex_match(nationality, regex("(^[A-Za-z]+[ ]*([A-Za-z]||[ ])*$)"));

    if (containsDigits)
    {
        throwError.invalidNation();
        return false;
    }
    return true;
}


/****************************************************************************
                               findInInt
                     ber saman fylgibreytur
                     @parameter(int query) - ár sem leitað er að
                     @parameter(int year) - ár sem leitað er eftir
                     @return true - ef query nefnir rétt ár/áratug/árhundrað
                     @return false - ef skilyrði að ofan eru óuppfyllt
 ****************************************************************************/
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

/****************************************************************************
                               findInString
                     ber saman fylgibreytur án þess að pæla
                     í stórum og litlum stöfum

                     @parameter(string query) - strengur sem leitað er að
                     @parameter(string String) - strengur sem leitað er í
                     @return true - ef query finnst sem heill-/hlutstrengur String
                     @return false - ef skilyrði að ofan eru óuppfyllt
 ****************************************************************************/
bool Service::findInString(string query, string String) //Jafnvel að endurskoða þetta fall ef við tökum inn Qstring í stað string
{
    transform(query.begin(), query.end(), query.begin(), ::tolower);
    transform(String.begin(), String.end(), String.begin(), ::tolower);

    if(query.length() > String.length())
        return false;
    else if(query.length() == String.length())
    {
        return !String.compare(0, query.length(), query);
    }

    for(unsigned int i = 0; i <= (String.length() - query.length()); i++)
    {
        if(!String.compare(i, query.length(), query))
            return true;
    }

    return false;
}

/****************************************************************************
                               getIndexesWith
                     Finnur indexa alla þeirra vísindamanna
                     sem uppfylla leitarskilyrði má vera tala eða strengur.
                     @parameter(string query) - Strengur/tala sem leitað er að
                     @return vector<int> - indexar allra þeirra vísindamanna sem uppfylltu skilyrði
 ****************************************************************************/
vector<int> Service::getIndexesWith(string query )
{
    /* vector<Scientist> _scientists = data.getScientists()
     * Betra að finna leið til að láta þetta vinna beint í SQL
     */

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
            if (findInString(query, _scientists[i].getFirstName()) || findInString(query, _scientists[i].getLastName()) || findInString(query, _scientists[i].getSex()) || findInString(query, _scientists[i].getFurtherInfo()))
            {
                foundScientists.push_back(i);
            }
        }
    }

    return foundScientists;
}

void Service::searchInDatabase(vector<Scientist> &scientists, vector<Computer> &computers, string query)
{
    data.searchData(scientists, computers, query);
}

/**********************************************************
                   Struct til að sortera
                 struct sem sort algorithm'inn
                 þarf á að halda til að kunna að
                 bera saman tvo vísindamenn.
                 Tilgangur hvers er talin augljós
                 útfrá nafni
**********************************************************/
/*
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

*/
/**********************************************************
              Sort föll
              Þau föll sem kallað er í til að
              raða meðlimavector í þá röð sem
              nafn hvers falls segir til um
**********************************************************/
/*
void Service::sortByNameAscending()  // Það þyrfti líklega að breyta öllum slíkum föllum á þennan máta
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
*/
