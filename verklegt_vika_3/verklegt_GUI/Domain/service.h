#ifndef SERVICE_H
#define SERVICE_H

#include "errorhandling.h"
#include "scientist.h"
#include "../DATA/database.h"
#include "errorlog.h"
#include "activitylog.h"

#include <algorithm>
#include <iostream>
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

    /**************************************************
        Ný föll - Á EFTIR AÐ KOMMENTA
    **************************************************/
        void setUser(QString username);
        Computer getComputer(int ID);

    /**********************************************************
                         Vector aðgerðir
    **********************************************************/
    bool doesScientistExcist(string firstName, string lastName, string sex, int birthYear,
                             int deathYear, string nationality, string furtherInfo);
    bool doesComputerExcist(string name, string CpuType, int yearBuilt, bool built);

    bool appendScientist (string firstName, string lastName, string sex, int birthYear,         //Bætir vísindamanni aftast í meðlimavector og skilar boolean
                          int deathYear, string nationality, string furtherInfo);               // gildi sem útskýrir hvernig gekk.
    bool appendComputer (string name, string CpuType, int yearBuilt, bool built);         //Bætir vísindamanni aftast í meðlimavector og skilar boolean
    void addRelations(int cID, int sID);
    void removeRelations(int cID, int sID);
    void addType(string type);
    void removeScientist(int index);                              //Fjarlægjr vísindamann sem index gefur til kynna
    void moveLastTo(int index);                                   //Færir aftasta vísindamann í stak sem index gefur til kynna
    vector<Scientist> getScientists(string choice = "na");                            //Skilar vector of vísindamönnum í núverandi röð
    vector<Scientist> getDeletedScientists();
    vector<Computer> getComputers(string choice = "na");
    vector<Computer> getDeletedComputers();
    vector<CpuType> getTypes(string choice = "t");
    int getNumberOfScientists();                                        //Segir til um hve margir vísindamenn eru í gagnagrunni
    int getNumberOfComputers();
  //  void sortScientistsBy(string choice = "na");                  //Raðar vísindamönnum í röð eftir vali sem er stafsrófsröð by default


    /**********************************************************
                         Villucheckar föll
    **********************************************************/
    bool validName(string& name);                                 //segir til um hvort nafn sé löglegt
    bool validCpuName(string &name);
    bool validSex(string& sex);                                   //segir til um hvort kyn sé löglegt
    bool validYears(int birthYear, int deathYear);                //segir til um hvort ár séu lögleg
    bool validDeathYear(string deathYear);                        //segir til um hvort dánarár sé löglegt
    bool validNationality(string& nationality);                   //segir til um hvort þjóðerni sé löglegt
    string getErrorString();                                      //skilar núverandi villuboði ef það er til staðar
    string getErrorString(bool brute);
    void logYearError(int code);

    bool validBuild(string &build);
    bool validBuildYear(int buildYear);




    /**********************************************************
                         Vistunarföll
    **********************************************************/
    void editScientist(int ID, Scientist scientist);
    void editComputer(int ID, Computer computer);

    /**********************************************************
                         Leitarföll
    **********************************************************/
    vector<int> getIndexesWith(string query);                    //skilar indexum þeirra vísindamanna sem uppfylla leitunarskilyrði
    void searchInDatabase(vector<Scientist> &scientists, vector<Computer> &computers, string query);

    /**********************************************************
                         Deleteföll
    **********************************************************/
    void deleteAllFromDatabase();
    void deleteAllScientistsFromDatabase();
    void deleteAllComputersFromDatabase();
    void deleteScientist(int ID);
    void deleteComputer(int ID);

    void restoreAllFromDatabase();
    void restoreAllComputerFromDatabase();
    void restoreAllScientistFromDatabase();

    void restoreScientist(int ID);
    void restoreComputer(int ID);

    /**********************************************************
                 Hjálparföll fyrir appendScientist
    **********************************************************/
    string removeSpaces(string before);                         //tekur inn streng og skilar honum án samliggjandi bila
    string fixString(string before);                            //Stækkar fyrstu stafi allra orða

    /**********************************************************
                     Villi að vesenast í nýju
    ***********************************************************/
    QSqlQuery showComputerData(QString username, QString searchString);
    void closeDatabase();
    QSqlQuery showScientistData(QString username, QString searchString);
    void deleteScientist(QString username, QString name, QString lastName, QString year);
    void deleteComputer(QString username, QString name, QString year);
    QSqlQuery getRecycledComputers(QString username);
    bool getUser(const QString& username, const QString& password);
    bool createUser (const QString& username, const QString& password, const QString& firstName, const QString& lastName);


private:
    /**********************************************************
                         Meðlimabreytur
    **********************************************************/
    vector<Scientist> _scientists;
    vector<Computer> _computers;
    ErrorHandling throwError;
    Database data;
    string user;
    QString qUser;



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
