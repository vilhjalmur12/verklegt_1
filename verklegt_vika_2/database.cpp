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
void database::getData(string selection, string table)
{
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("/Users/villi/Desktop/Verklegt Git/verklegt_1/verklegt_vika_2/" + user + ".sqlite");

   if (!myData.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
      qDebug() << "Database: connection ok";
   }

   // Byrjum að setja If setningar hér


   selectData();

   myData.close();

}

vector<Scientist> pullDataScientist (const QSqlDatabase& data)
{
    vector<string> tmp;
    vector<string> tmpS2;


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

   // initDatabase(username);

}

void database::initDatabase (const QString& username)
{
    QSqlQuery userQuery;
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
/*
    userQuery.prepare("CREATE  TABLE scientists "
                      "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                  "First_name VARCHAR NOT NULL , Last_name VARCHAR NOT NULL , "
                  "Gender VARCHAR, Year_of_birth INTEGER, Year_of_death INTEGER, "
                  "Nationality VARCHAR, Information VARCHAR)");
    */
   /*
    userQuery.prepare ("CREATE  TABLE \"main\".\"computers\" "
                   "(\"ID\" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                   "\"Name\" VARCHAR NOT NULL , \"Year_of_build\" INTEGER, "
                   "\"CPU_type_ID\" INTEGER, \"built_or_not\" BOOL)");
                   */
    /*
    userQuery.prepare("CREATE  TABLE \"main\".\"cpuType\" "
                  "(\"ID\" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                  "\"type\" VARCHAR NOT NULL )");
                  */

   userQuery.exec("CREATE TABLE sRc(computerID INTEGER, scientistID INTEGER, FOREIGN KEY (computerID) REFERENCES Computers(ID), FOREIGN KEY (scientistID) REFERENCES Scientists(ID) PRIMARY KEY (computerID, scientistID))");


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
