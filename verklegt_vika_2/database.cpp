#include "database.h"
#include <iostream>
#include "scientist.h"
#include <vector>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord.h>


using namespace std;

database::database () {}
database::~database () {}

// ætti að fara inn í constructor: const QString& path ef við viljum útbúa spes path.
void database::getData(QString username, vector<Scientist> &scien)
{
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("./" + username + ".sqlite");

   if (!myData.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }

   // Byrjum að setja If setningar hér
    scien = pullDataScientist(myData);



   myData.close();

}

void database::getData(string selection, string table)
{
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("./" + user + ".sqlite");

   if (!myData.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }

   // Byrjum að setja If setningar hér
    vector<Scientist> scien = pullDataScientist(myData);



   myData.close();
   QSqlDatabase::removeDatabase("QSQLITE");

}

vector<Scientist> database::pullDataScientist (const QSqlDatabase data)
{
    vector<Scientist> scientists;

    QSqlQuery query;
    query.exec("SELECT * FROM scientists");
    while(query.next())
    {
        QString tempQ;
        int tempID;
        string tempFirstName;
        string tempLastName;
        string tempGender;
        int tempYOB;
        int tempYOD;
        string tempNationality;
        string tempInfo;

        tempID = query.value(0).toInt();

        tempQ = query.value(1).toString();
        tempFirstName = tempQ.toUtf8().constData();

        tempQ = query.value(2).toString();
        tempLastName = tempQ.toUtf8().constData();

        tempQ = query.value(3).toString();
        tempGender = tempQ.toUtf8().constData();

        tempYOB = query.value(4).toInt();
        tempYOD = query.value(5).toInt();

        tempQ = query.value(6).toString();
        tempNationality = tempQ.toUtf8().constData();

        tempQ = query.value(7).toString();
        tempInfo = tempQ.toUtf8().constData();

        cout << tempID << endl << tempFirstName << endl << tempLastName << endl << tempGender << endl << tempYOB << endl << tempYOD << endl << tempNationality << endl << tempInfo << endl;

        Scientist tmp(tempID, tempFirstName, tempLastName, tempGender, tempYOB, tempYOD, tempNationality, tempInfo);

        scientists.push_back(tmp);
    }

    return scientists;
}

bool database::getUser(const QString& username, const QString& password)
{
    user = username;
    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("./users.sqlite");

    if (!myData.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :user");
    query.bindValue(":user", username);
    query.exec();

    QString qPass;
    if (query.next())
    {
        qPass = query.value(0).toString();
    }

    if (password == qPass)
    {
        myData.close();
        getData("selection", "table");
        return true;
    }
    else
    {
        myData.close();
        return false;
    }
}

void database::createUser(const QString& username, const QString& password, const QString& firstName, const QString& lastName)
{
    user = username;
    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("./users.sqlite");

    if (!myData.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    QSqlQuery query;

    query.prepare("CREATE TABLE users(first_name VARCHAR NOT NULL, last_name VARCHAR NOT NULL, username VARCHAR NOT NULL, password VARCHAR NOT NULL)");
    query.exec();


    query.prepare("INSERT INTO users (first_name, last_name, username, password)" "VALUES (:firstName, :lastName, :username, :password)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();


    myData.close();

    initDatabase(username);

}

void database::initDatabase (const QString& username)
{

    QSqlDatabase userData = QSqlDatabase::addDatabase("QSQLITE");
    userData.setDatabaseName("./" + username + ".sqlite");
    if (!userData.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    QSqlQuery userQuery;
    userQuery.exec("CREATE  TABLE scientists "
                   "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                    "First_name VARCHAR NOT NULL , Last_name VARCHAR NOT NULL , "
                    "Gender VARCHAR, Year_of_birth INTEGER, Year_of_death INTEGER, "
                    "Nationality VARCHAR, Information VARCHAR)");

    userQuery.exec ("CREATE  TABLE computers "
                   "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                   "Name VARCHAR NOT NULL , Year_of_build INTEGER, "
                   "CPU_type_ID INTEGER, built_or_not BOOL)");


    userQuery.exec ("CREATE  TABLE cpuType "
                  "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                  "type VARCHAR NOT NULL )");

    userQuery.exec("INSERT INTO scientists "
                      "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                      "VALUES ('Ada', 'Lovelace', 'Female', 1815, 1852, 'English', 'First computer programmer')");

    userQuery.exec("INSERT INTO scientists "
                      "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                      "VALUES ('John', 'Eckert', 'Male', 1919, 1995, 'American', 'Electrical engineer')");

    userQuery.exec("INSERT INTO scientists "
                      "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                      "VALUES ('Heinz', 'Zemanek', 'Male', 1920, 2014, 'Austrian', 'Computer Scientist')");

    userQuery.exec("INSERT INTO computers"
                      "(Name, Year_of_build, CPU_type_ID, built_or_not)"
                      "VALUES ('Analytical engine', 'n/a', 1, 'n')");

    userQuery.exec("INSERT INTO computers"
                      "(Name, Year_of_build, CPU_type_ID, built_or_not)"
                      "VALUES ('ENIAC', 1946, 2, 'y')");

    userQuery.exec("INSERT INTO computers"
                      "(Name, Year_of_build, CPU_type_ID, built_or_not)"
                      "VALUES ('Mailüfterl', 1958, 3, 'y')");

    userQuery.exec("INSERT INTO cpuType"
                      "(Type)"
                      "VALUES ('Mechanic')");

    userQuery.exec("INSERT INTO cpuType"
                      "(Type)"
                      "VALUES ('Electronic')");

    userQuery.exec("INSERT INTO cpuType"
                      "(Type)"
                      "VALUES ('Transistor Machine')");

    userData.close();

}

void database::selectData ()
{

    QSqlQuery query("SELECT * FROM cpuType");
    int idName = query.record().indexOf("type");
    while (query.next())
    {
       QString name = query.value(idName).toString();
       qDebug() << name;
    }
}




/******************************************************************
                     encryptData
    Auðveldur ceaser cypher sem dulkóðar streng
            @parameter(string n) - venjulegur strengur
            @return(string n) - dulkóðaður strengur
 ******************************************************************/

string database::encryptData (string n)
{
    for(unsigned int u=0; u < n.size(); u++){
        n[u]--;
    }
    return n;
}

/******************************************************************
                      decryptData
    Auðveldur ceaser cypher sem afkóðar streng
            @parameter(string n) - dulkóðaður strengur
            @return(string n) - afkóðaður strengur
 ******************************************************************/

string database::decryptData (string n)
{
    for(unsigned int u=0; u < n.size(); u++){
        n[u]++;
    }
    return n;
}
