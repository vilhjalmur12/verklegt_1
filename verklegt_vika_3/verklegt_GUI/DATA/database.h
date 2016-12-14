#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "../Domain/errorhandling.h"
#include "../Domain/scientist.h"
#include "../Domain/computer.h"
#include <qsqldatabase.h>
#include <QSqlRecord>
#include <QDebug>
#include "../Domain/cputype.h"
#include "../UI/errorwindow.h"

using namespace std;

class Database
{
public:
    Database ();
    virtual ~Database ();

    /**********************
     *      Nýtt
     * *********************/
    void databaseOpen(QString username);
    void databaseClose();
    QSqlQuery showScientistData (QString username, QString searchString);
    QSqlQuery showComputerData (QString username, QString searchString);
    void deleteScientist(QString username, QString name, QString lastName, QString year);
    void deleteComputer(QString username, QString name, QString year);
    bool computerAlreadyDeleted(QString username, int ID);
    QSqlQuery getRecycledComputers (QString username);
    QSqlQuery getRecycledScientists (QString username);

    void setUser(QString username);
    bool userExisting(QString username);
    bool noUserInserted (QString username);
    Computer getComputer(int ID);
    Scientist getScientist(int ID);

    Scientist makeScientist(QSqlQuery &query);
    Computer makeComputer(QSqlQuery &query);

    void adddBuiltComputersToScientist(Scientist &scientist);
    void addBuildersToComputer(Computer &computer);

    vector<Computer> getComputersRelatedTo(int ID);
    vector<Scientist> getScientistsRelatedTo(int ID);
    /****************************/


    void getData(QString username, vector<Scientist> &scien);
    void getData ();
    bool getUser (const QString& username, const QString& password);                            //Sækir notanda úr gagnagrunni
    bool createUser (const QString& username, const QString& password, const QString& firstName, const QString& lastName);  //Býr til notanda
    vector<Scientist> pullScientists(string choice);                                            //Sækir vísindamenn úr gagnagrunni
    vector<Scientist> pullDeletedScientists();                                                  //Sækir vísindamenn sem hafa verið eytt
    vector<Computer> pullComputers(string choice);                                              //Sækir tölvur úr gagnagrunni
    vector<Computer> pullDeletedComputers();                                                    //Sækir tölvur sem hafa verið deleted
    vector<CpuType> pullTypes(string order);                                                    //Sækir týpur af tölvum
    void insertScientist (Scientist scientist);                                                 //Bætir við nýjum vísindamanni
    void insertComputer (Computer computer, QString tmpUser);                                   //Bætir við nýrri tölvu
    int getTypeId(QString type);                                                                //Sækir ID fyrir tölvu týpu
    void insertType(string type);                                                               //Bætir við nýrri týpu
    string pullUser();                                                                          //Sækir tiltekin notanda úr gagnagrunni
    /**********************************************************
                         Edit föll
    **********************************************************/
    void editScientist(int ID, Scientist scientist);
    void editComputer(int ID, Computer computer);
    /**********************************************************
                         Leitar föll
    **********************************************************/
    void searchData(vector<Scientist> &scientists, vector<Computer> &computers, string sQuery); //Tekur við leitarstreng og ákveður hvernig leit skal framkvæma
    QString generalizeQuery(string query);                                                      //Tekur við leitar streng frá notenda og breytir í Qstring
    int getNumberOfScientistEntries();                                                          //Skilar fjölda af vísindamönnum
    int getNumberOfComputerEntries();                                                           //Skilar fjölda af tölvum

    void searchComputersForSubstring(vector<Computer> &computers, const string query);          //Leitar í tölvum eftir leitarstreng
    void searchComputersForInt(vector<Computer> &computers, const int iQuery);                  //Leitar í tölvum eftir tölu
    void addFoundComputers(QSqlQuery &query, vector<Computer> &computers);                      //Bætir fundum tölvum í vector
    void addBuildersToComputers(vector<Computer> &computers);                                   //Bætir vísindamönnum við tölvur

    void searchScientistsForSubstring(vector<Scientist> &scientists, const string query);       //Leitar í vísindamönnum eftir leitarstreng
    void searchScientistsForInt(vector<Scientist> &scientists, const int iQuery);               //Leitar í vísindamönnum eftir tölu
    void addFoundScientists(QSqlQuery &query, vector<Scientist> &scientists);                   //Bætir fundum vísindamönnum í vector
    void adddBuiltComputersToScientists(vector<Scientist> &scientists);                         //Bætir tölvum við vísindamenn

    /**********************************************************
                         Vensla föll
    **********************************************************/
    void addRelations(int cID, int sID);                                                        //Bætir við venslum milli vísindamanna og tölva
    void removeRelations(int cID, int sID);                                                     //Fjarlægir vensl milli vísindamanna og tölva
    /**********************************************************
                        Delete föll
    **********************************************************/
    void deleteAllFromDatabase();                                                               //Kallar á föll til að "eyða" úr gagnagrunni
    void deleteAllFromComputerDatabase();                                                       //Flaggar allar tölvur sem deleted
    void deleteAllFromScientistDatabase();                                                      //Flaggar alla vísindamenn sem deleted
    void deleteScientist(int ID);                                                               //Flaggar ákveðin vísindamann sem deleted
    void deleteComputer(int ID);                                                                //Flaggar ákveðna tölvu sem deleted
    /**********************************************************
                        Restore föll
    **********************************************************/
    void restoreAllFromDatabase();                                                              //Tekur allt sem hefur verið eytt og af flaggar það
    void restoreAllFromComputerDatabase();                                                      //Framkvæmir restoreAll aðgerðina fyrir tölvur
    void restoreAllFromScientistDatabase();                                                     //Framkvæmir restoreAll aðgerðina fyrir vísindamenn
    void restoreScientist(int ID);                                                              //Af flaggar ákveðin vísindamann
    void restoreComputer(int ID);                                                               //Af flaggar ákveðna tölvu


private:
    QSqlDatabase myData;
    QString user;
    errorwindow errorOut;

    void selectData ();
    string encryptData (string n);                                                              //Dulkóðar
    string decryptData (string n);                                                              //Afkóðar
    void initDatabase (const QString& username);                                                //Frumstillir gagnagrun fyrir vísindamann
    void databaseClose(QSqlDatabase &data);
    void databaseOpen();

};

#endif // DATABASE_H
