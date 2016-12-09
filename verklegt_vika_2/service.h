#ifndef SERVICE_H
#define SERVICE_H

#include "errorhandling.h"
#include "scientist.h"
#include "database.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>
#include <qsqldatabase.h>
#include <QDebug>

using namespace std;

const int maxDeathYear = 200000000;

class Service
{
public:
    Service();
    Service(const QString user);
    virtual ~Service();

    /**********************************************************
                         Vector aðgerðir
    **********************************************************/
    bool doesScientistExcist(string firstName, string lastName, string sex, int birthYear,
                             int deathYear, string nationality, string furtherInfo);
    bool doesComputerExcist(string name, string cpuType, int yearBuilt, bool built);

    bool appendScientist (string firstName, string lastName, string sex, int birthYear,         //Bætir vísindamanni aftast í meðlimavector og skilar boolean
                          int deathYear, string nationality, string furtherInfo);               // gildi sem útskýrir hvernig gekk.
    bool appendComputer (string name, string cpuType, int yearBuilt, bool built);         //Bætir vísindamanni aftast í meðlimavector og skilar boolean
    void addRelations(int cID, int sID);
    void removeRelations(int cID, int sID);
    void addType(string type);
    void removeScientist(int index);                              //Fjarlægjr vísindamann sem index gefur til kynna
    void moveLastTo(int index);                                   //Færir aftasta vísindamann í stak sem index gefur til kynna
    vector<Scientist> getScientists(string choice = "na");                            //Skilar vector of vísindamönnum í núverandi röð
    vector<Computer> getComputers(string choice = "na");
    vector<cpuType> getTypes(string choice = "t");
    int getNumberOfScientists();                                        //Segir til um hve margir vísindamenn eru í gagnagrunni
    int getNumberOfComputers();
  //  void sortScientistsBy(string choice = "na");                  //Raðar vísindamönnum í röð eftir vali sem er stafsrófsröð by default


    /**********************************************************
                         Villucheckar föll
    **********************************************************/
    bool validName(string& name);                                 //segir til um hvort nafn sé löglegt
    bool validSex(string& sex);                                   //segir til um hvort kyn sé löglegt
    bool validYears(int birthYear, int deathYear);                //segir til um hvort ár séu lögleg
    bool validDeathYear(string deathYear);                        //segir til um hvort dánarár sé löglegt
    bool validNationality(string& nationality);                   //segir til um hvort þjóðerni sé löglegt
    string getErrorString();                                      //skilar núverandi villuboði ef það er til staðar
    void logYearError(int code);

    bool validBuild(string &build);
    bool validBuildYear(int buildYear);


    /**********************************************************
                         Vistunarfall
    **********************************************************/
    void editScientist(int ID, Scientist scientist);
    void editComputer(int ID, Computer computer);

    /**********************************************************
                         Leitarfall
    **********************************************************/
    vector<int> getIndexesWith(string query);                    //skilar indexum þeirra vísindamanna sem uppfylla leitunarskilyrði
    void searchInDatabase(vector<Scientist> &scientists, vector<Computer> &computers, string query);

    void deleteScientist(int ID);
    void deleteAllScientistFromDatabase();
    void deleteComputer(int ID);

private:
    /**********************************************************
                         Meðlimabreytur
    **********************************************************/
    vector<Scientist> _scientists;
    vector<Computer> _computers;
    ErrorHandling throwError;
    database data;
    string user;
    QString qUser;

    /**********************************************************
                 Hjálparföll fyrir appendScientist
    **********************************************************/
    string removeSpaces(string before);                         //tekur inn streng og skilar honum án samliggjandi bila
    string fixString(string before);                            //Stækkar fyrstu stafi allra orða

    /**********************************************************
                     Hjálparföll fyrir search
    **********************************************************/
    bool findInInt(int query, int year);                         //skilar true ef notandi slær inn rétt ár, árarug eða árhundruð
    bool findInString(string query, string string);              //skilar true ef hlutstrengur finnst einhversstaðar í gildum vísindamanns

    /**********************************************************
                  Sorting algrímar
         Þeir umraða _scientists vectornum
         eftir því sem við á í hverju falli
    **********************************************************/
    /*
    void sortByNameAscending();             //Stafrófsröð
    void sortByNameDesending();             //Öfug stafrófsröð
    void sortBySexF();                      //Konur fyrst
    void sortbySexM();                      //Karlar fyrst
    void sortByBirthAscending();            //Fæðingarár hækkandi
    void sortByBirthDescending();           //Fæðingarári lækkandi
    void sortByDeathAscending();            //Dánarári hækkandi
    void sortByDeathDescending();           //Dánarári lækkandi
    void sortByNationalityAscending();      //Stafrófsröð þjóðernis
    void sortByNationalityDescending();     //Öfugri stafrófsröð þjóðernis
    */
};

#endif // SERVICE_H
