#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "errorhandling.h"
#include "scientist.h"
#include "computer.h"
#include <qsqldatabase.h>
#include <QDebug>


using namespace std;

class database
{
public:
    database ();
    ~database ();
    void getData(QString username, vector<Scientist> &scien);
    void getData (string selection, string table);
    bool getUser (const QString& username, const QString& password);
    void createUser (const QString& username, const QString& password, const QString& firstName, const QString& lastName);
    vector<Scientist> pullScientists(string choice);
    vector<Computer> pullComputers(string choice);
    void insertScientist (Scientist scientist, QString tmpUser);
    void insertComputer (Computer computer, QString tmpUser);

    void openDataBaseConnection();

    void searchData(vector<Scientist> &scientists, vector<Computer> &computers, string sQuery);
    QString generalizeQuery(string query);

    void searchComputersForSubstring(vector<Computer> &computers, const string query);
    void searchComputersForInt(vector<Computer> &computers, const int iQuery);
    void addFoundComputers(QSqlQuery &query, vector<Computer> &computers);
    void addBuildersToComputers(vector<Computer> &computers);

    void searchScientistsForSubstring(vector<Scientist> &scientists, const string query);
    void searchScientistsForInt(vector<Scientist> &scientists, const int iQuery);
    void addFoundScientists(QSqlQuery &query, vector<Scientist> &scientists);
    void adddBuiltComputersToScientists(vector<Scientist> &scientists);

    void deleteAllFromDatabase();
    void deleteAllFromComputerDatabase();

private:
    QSqlDatabase myData;
    QString user;

    void selectData ();
    string encryptData (string n);
    string decryptData (string n);
    void initDatabase (const QString& username);
    void databaseClose(QSqlDatabase &data);
    void databaseOpen();
};

#endif // DATABASE_H
