#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "errorhandling.h"
#include "scientist.h"
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
    vector<Scientist> pullDataScientist (const QSqlDatabase data);

private:
    QSqlDatabase myData;
    QString user;

    void selectData ();
    string encryptData (string n);
    string decryptData (string n);
    void initDatabase (const QString& username);
    void databaseClose(QSqlDatabase &data);

};

#endif // DATABASE_H
