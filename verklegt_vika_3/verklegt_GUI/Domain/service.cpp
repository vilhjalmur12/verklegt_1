#include "service.h"

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
                        Villi að vesenast í nýju


*****************************************************************************/

QSqlQuery Service::showComputerData(QString username, QString searchString)
{

    QSqlQuery query = data.showComputerData(username, searchString);


    return query;
}

QSqlQuery Service::showScientistData(QString username, QString searchString)
{
    QSqlQuery query = data.showScientistData(username, searchString);

    return query;
}

void Service::closeDatabase()
{
    data.databaseClose();
}

void Service::deleteScientist(QString username, QString name, QString lastName, QString year)
{
    data.deleteScientist(username, name, lastName, year);
}

void Service::deleteComputer(QString username, QString name, QString year)
{
    data.deleteComputer(username, name, year);
}

QSqlQuery Service::getRecycledComputers(QString username)
{
    QSqlQuery query = data.getRecycledComputers(username);

    return query;
}

bool Service::getUser(const QString& username, const QString& password)
{
    bool tmp = data.getUser(username, password);

    return tmp;
}

bool Service::createUser (const QString& username, const QString& password, const QString& firstName, const QString& lastName)
{
    return data.createUser(username, password, firstName, lastName);
}
void Service::setUser(QString username)
{
    data.setUser(username);
}

Computer Service::getComputer(int ID)
{
    return data.getComputer(ID);

}

vector<Computer> Service::getComputersRelatedTo(int ID)
{
    return data.getComputersRelatedTo(ID);
}

vector<Scientist> Service::getScientistsRelatedTo(int ID)
{
    return data.getScientistsRelatedTo(ID);
}


/****************************************************************************
                               getErrorString
                     Sækir error message'ið sem er geymt í
                     throw error objectinu, ef enginn
                     error hefur verið skráður þá er
                     strengurinn tómur
 ****************************************************************************/
string Service::getErrorString()
{
   // errorLog _errorLog(user, throwError.catchError());
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
                               doesScientistExcist
                     Segir til um hvort vísindamaður sé til nú þegar
                     @return true ef vísindamaður er nú þegar til
                     @return false ef vísindamaður er ekki til
            *Til að vísindamaður sé til þurfa allar breytur að
            *vera þær sömu
 ****************************************************************************/
bool Service::doesScientistExcist(string firstName, string lastName, string sex, int birthYear, int deathYear, string nationality, string furtherInfo)
{
    vector<Scientist> scientists = getScientists();
    Scientist scientist(firstName, lastName, sex, birthYear, deathYear, nationality, furtherInfo);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        if(scientist == scientists[i])
        {
            throwError.invalidName(1);
            return true;
        }
    }
    return false;
}

/****************************************************************************
                               doesComputerExcist
                     Segir til um hvort tölva sé til nú þegar
                     @return true ef tölva er nú þegar til
                     @return false ef tölva er ekki til
            *Til að vísindamaður sé til þurfa allar breytur að
            *vera þær sömu
 ****************************************************************************/
bool Service::doesComputerExcist(string name, string cpuType, int yearBuilt, bool built)
{
    vector<Computer> computers = getComputers();
    Computer tempComputer(name, cpuType, yearBuilt, built);

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        if(tempComputer == computers[i])
        {
            throwError.invalidName(1);
            return true;
        }
    }
    return false;
}

/****************************************************************************
                           appendScientist
                  Bætir nýjum vísindamanni við gagnagrunn sé hún ekki til
                  nú þegar og skilar boolean segð sem segir til um
                  hvernig gekk
 ****************************************************************************/
bool Service::appendScientist(string firstName, string lastName, string sex, int birthYear, int deathYear, string nationality, string furtherInfo)
{
    Scientist tempScientist(firstName, lastName, sex, birthYear, deathYear, nationality, furtherInfo);

    if(doesScientistExcist(firstName, lastName, sex, birthYear, deathYear, nationality, furtherInfo))
        return false;

    activityLog _activityLog(data.pullUser());
    _activityLog.pushActivity("insert", tempScientist);

    data.insertScientist(tempScientist);

    return true;
}

/****************************************************************************
                           appendComputer
                  Bætir nýrri tölvu við gagnagrunn sé hún ekki til
                  nú þegar og skilar boolean segð sem segir til um
                  hvernig gekk
 ****************************************************************************/

bool Service::appendComputer (string name, string cpuType, int yearBuilt, bool built)
{
    Computer tempComputer(name, cpuType, built, yearBuilt);

    if(doesComputerExcist(name, cpuType, yearBuilt, built))
        return false;

    activityLog _activityLog(data.pullUser());
    _activityLog.pushActivity("insert", tempComputer);
    data.insertComputer(tempComputer, qUser);

    return true;
}

/****************************************************************************
                           delete föll
                  Flagga sem deletaða í gagnagrunni
 ****************************************************************************/
void Service::deleteScientist(int ID)
{
    data.deleteScientist(ID);
}

void Service::deleteComputer(int ID)
{
    data.deleteComputer(ID);
}

void Service::deleteAllFromDatabase()
{
    data.deleteAllFromDatabase();
}

void Service::deleteAllScientistsFromDatabase()
{
    data.deleteAllFromScientistDatabase();
}

void Service::deleteAllComputersFromDatabase()
{
    data.deleteAllFromComputerDatabase();
}

/****************************************************************************
                           Restore föll
                  Flagga sem ekki deletað í gagnagrunni
 ****************************************************************************/
void Service::restoreScientist(int ID)
{
    data.restoreScientist(ID);
}

void Service::restoreComputer(int ID)
{
    data.restoreComputer(ID);
}

void Service::restoreAllComputerFromDatabase()
{
    data.restoreAllFromComputerDatabase();
}

void Service::restoreAllScientistFromDatabase()
{
    data.restoreAllFromScientistDatabase();
}

void Service::restoreAllFromDatabase()
{
    data.restoreAllFromDatabase();
}

/****************************************************************************
                               editScientist
                     update'ar vísindamann í stað ID
                     @parameter ID: ID vísindamannsins sem skal uppfæra
                     @parameter Scientist: Nýr vísindamaður
 ****************************************************************************/
void Service::editScientist(int ID, Scientist scientist)
{
    data.editScientist(ID, scientist);
}

/****************************************************************************
                               editComputer
                     update'ar tölvu í stað ID
                     @parameter ID: ID tölvunnar sem skal uppfæra
                     @parameter Computer: Ný tölva
 ****************************************************************************/
void Service::editComputer(int ID, Computer computer)
{
    data.editComputer(ID, computer);
}

/****************************************************************************
                               addRelations
                     Tengir saman tölvu og vísindamann
                     @parameter cID: ID tölvu
                     @parameter sID: ID vísindamanns
 ****************************************************************************/
void Service::addRelations(int cID, int sID)
{
    data.addRelations(cID, sID);
    data.restoreRelations(cID, sID);
}

/****************************************************************************
                               removeRelations
                     Flaggat tengsl tölvu og vísindamanns sem delet'uð
                     @parameter cID: ID tölvu
                     @parameter sID: ID vísindamanns
 ****************************************************************************/
void Service::removeRelations(int cID, int sID)
{
    data.removeRelations(cID, sID);
}



/****************************************************************************
                               getScientists
           skilar vector vísindamanna í þeirri röð sem beðið er um
                     @parameter choice: na/nd/gf/gm/...  segir til um uppröðun
                     @return vector<Scientist>: Vector af Vísindamnann objectum
       n -> name | g -> gender | b -> birth | d-> death | c -> country
                        d -> Descending | m(ale) -> [gender] Descending
 ****************************************************************************/
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

/****************************************************************************
                               getDeletedScientists
   Skilar vector af vísindamönnum sem flaggaðir eru deletaðir í stafrófsröð
 ****************************************************************************/
vector<Scientist> Service::getDeletedScientists()
{
    return data.pullDeletedScientists();
}

/****************************************************************************
                               getComputers
           skilar vector af tölvum í þeirri röð sem beðið er um
                     @parameter choice: na/nd/ya/td/by/bn...  segir til um uppröðun
                     @return vector<Computers>: Vector af Tölvu objectum
               n -> name | y -> year | t-> type | b -> built?
                d -> Descending | y(es) -> [built?] Descending
 ****************************************************************************/
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
                               getDeletedComputers
     Skilar vector af tölvum sem flaggaðar eru deletaðar í stafrófsröð
 ****************************************************************************/
vector<Computer> Service::getDeletedComputers()
{
    return data.pullDeletedComputers();
}

/****************************************************************************
                               getTypes
                 Skilar vector af þekktum týpum talvna
 ****************************************************************************/
vector<CpuType> Service::getTypes(string choice)
{
    if(choice == "t")
        choice = "type";
    return data.pullTypes(choice);
}

/****************************************************************************
                               addType
                Bætir nýrri týpu af tölvu í gagnagrunninn
 ****************************************************************************/

void Service::addType(string type)
{
    type = fixString(type);

    CpuType _cpu(type);
    activityLog _activityLog(user);
    _activityLog.pushActivity("insert", _cpu);
    data.insertType(type);
}


/****************************************************************************
                               getNumberOfScientists()
                    skilar fjölda vísindamanna í gagnagrunni
 ****************************************************************************/
int Service::getNumberOfScientists()
{
    return data.getNumberOfScientistEntries();
}

/****************************************************************************
                               getNumberOfComputers()
                    skilar fjölda talvna í gagnagrunni
 ****************************************************************************/
int Service::getNumberOfComputers()
{
    return data.getNumberOfComputerEntries();
}

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

/****************************************************************************
                               validCpuName
                    Athugar hvort að nafn innihaldi skrítin tákn
                    og stækkar fyrsta staf allra orða
            @parameter(string& name) - nafnið, by reference til að breyta
            @return true - ef nafnið er gilt
            @return false - ef nafnið er ógilt
 ****************************************************************************/
bool Service::validCpuName(string &name)
{
    name = fixString(name);

    bool containsInvalidCharacter = !regex_match(name, regex("(^[A-Za-z0-9.-]+[ ]*([A-Za-z.0-9]||[ ])*$)"));

    if (containsInvalidCharacter)
    {
        throwError.invalidName(2);
        return false;
    }
    return true;
}

/****************************************************************************
                               validBuild
                    Ár innihaldi annað en tölur
            @parameter(string& build) - árið, by reference til að breyta
            @return true - ef árið er gilt
            @return false - ef árið er ógilt
 ****************************************************************************/
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

    if(birthYear > timePtr->tm_year + 1900)
    {
        throwError.invalidYear(2);
        return false;
    }

    if(deathYear == maxDeathYear)
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

/****************************************************************************
                               validYears
                     tekur inn bæði ártal og athugar villur

                     @parameter(int buildYear) - innslegið ár
                     @return true - ef ár eru gild
                     @return false - ef ár eru ógild
 ****************************************************************************/
bool Service::validBuildYear(int buildYear)
{
    //Pointer heldur utan um núverandi ár -1900
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(buildYear < -193000)
    {
        throwError.invalidYear(9);
        return false;
    }

    if(buildYear > timePtr->tm_year + 1900)
    {
        throwError.invalidYear(8);
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
    return (regex_match(input, regex("^-?[0-9]*$")));
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
                               searchInDatabase
                     leitar í öllum gagnagrunni að einhverju sem samsvarar leitarorði

                     @parameter(Scientists): Call by reference vektor sem fylltur er af leitarniðurstöðum
                     @parameter(Computers): Call by reference vektor sem fylltur er af leitarniðurstöðum
                     @parameter(String query) - innslegin leitarstrengur
 ****************************************************************************/
void Service::searchInDatabase(vector<Scientist> &scientists, vector<Computer> &computers, string query)
{
    data.searchData(scientists, computers, query);
}
