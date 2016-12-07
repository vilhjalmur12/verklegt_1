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

void database::databaseOpen()
{
    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("./" + user + ".sqlite");

    if (!myData.open())
    {
       qDebug() << "Error: connection with database fail";
    }
}

void database::databaseClose(QSqlDatabase &data)
{
    QString connection;
    connection = data.connectionName();
    data.close();
    data = QSqlDatabase();
    QSqlDatabase::removeDatabase(connection);
}

// ætti að fara inn í constructor: const QString& path ef við viljum útbúa spes path.
void database::getData(QString username, vector<Scientist> &scien)
{
   user = username;
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("./" + user + ".sqlite");

   if (!myData.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
       scien = pullDataScientist();

       databaseClose(myData);
   }
}

void database::getData(string selection, string table)
{
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("./" + user + ".sqlite");

   // myData.setDatabaseName("/Users/Sandra/Documents/GitHub/AlvoruVerklegt/verklegt_1/verklegt_vika_2/" + user + ".sqlite");

   if (!myData.open())
   {
      qDebug() << "Error: connection with database fail";
   }
   else
   {
       // Byrjum að setja If setningar hér
        vector<Scientist> scien = pullDataScientist();

        databaseClose(myData);
   }
}

vector<Scientist> database::pullDataScientist ()
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

            databaseClose(myData);
            getData("selection", "table");
            return true;
        }
        else
        {
            databaseClose(myData);
            return false;
        }
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
        QSqlQuery query;

        query.prepare("CREATE TABLE users(first_name VARCHAR NOT NULL, last_name VARCHAR NOT NULL, username VARCHAR NOT NULL, password VARCHAR NOT NULL)");
        query.exec();


        query.prepare("INSERT INTO users (first_name, last_name, username, password)" "VALUES (:firstName, :lastName, :username, :password)");
        query.bindValue(":firstName", firstName);
        query.bindValue(":lastName", lastName);
        query.bindValue(":username", username);
        query.bindValue(":password", password);
        query.exec();


        databaseClose(myData);

        initDatabase(username);
    }
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
        QSqlQuery userQuery;
        userQuery.exec("PRAGMA foreign_keys = ON");

        userQuery.exec("CREATE  TABLE scientists "
                       "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                        "First_name VARCHAR NOT NULL , Last_name VARCHAR NOT NULL , "
                        "Gender VARCHAR, Year_of_birth INTEGER, Year_of_death INTEGER, "
                        "Nationality VARCHAR, Information VARCHAR)");


        userQuery.exec ("CREATE  TABLE cpuType "
                      "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                      "type VARCHAR NOT NULL )");

        userQuery.exec ("CREATE TABLE computers "
                        "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL, "
                        "Name VARCHAR NOT NULL, "
                        "Year_of_build INTEGER, "
                        "CPU_type_ID INTEGER, "
                        "built_or_not BOOL, "
                        "FOREIGN KEY(CPU_type_ID) REFERENCES cpuType(ID))");

        userQuery.exec("CREATE TABLE scientist_computer_relations"
                       "(scientistID INTEGER, "
                       "computerID INTEGER, "
                       "FOREIGN KEY (computerID) REFERENCES Computers(ID), "
                       "FOREIGN KEY (scientistID) REFERENCES Scientists(ID) "
                       "PRIMARY KEY (computerID, scientistID)) ");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Ada', 'Lovelace', 'Female', 1815, 1852, 'English', 'First computer programmer')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('John', 'Eckert', 'Male', 1919, 1995, 'American', 'Electrical engineer')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Heinz', 'Zemanek', 'Male', 1920, 2014, 'Austrian', 'Computer Scientist')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Charles', 'Babbage', 'Male', 1791, 1871, 'English', 'Mechanical Engineer')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Mechanic')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Electronic')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Transistor Machine')");

        userQuery.exec("INSERT INTO computers "
                          "(Name, CPU_type_ID, built_or_not)"
                          "VALUES ('Analytical engine', 1, 0)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('ENIAC', 1946, 2, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('Mailufterl', 1958, 3, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('Difference Engine', 1991, 1, 1)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (1,1)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (2,2)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (3,3)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (4,1)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (4,4)");
        databaseClose(userData);
    }
}

void database::insertScientist (Scientist scientist, QString tmpUser)
{
       user = tmpUser;
       databaseOpen();

       QString tmpFirstName(scientist.getFirstName().c_str());
       QString tmpLastName(scientist.getLastName().c_str());
       QString tmpGender(scientist.getSex().c_str());
       int tmpYOB = scientist.getYearOfBirth();
       int tmpYOD = scientist.getYearOfDeath();
       QString tmpNation(scientist.getNationality().c_str());
       QString tmpInfo(scientist.getFurtherInfo().c_str());

       QSqlQuery query;
       query.prepare("INSERT INTO scientists"
                     "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                     "VALUES (:firstName, :lastName, :gender, :YOB, :YOD, :nation, :info)");
       query.bindValue(":firstName", tmpFirstName);
       query.bindValue(":lastName", tmpLastName);
       query.bindValue(":gender", tmpGender);
       query.bindValue(":YOB", tmpYOB);
       query.bindValue(":YOD", tmpYOD);
       query.bindValue(":nation", tmpNation);
       query.bindValue(":info", tmpInfo);
       query.exec();

       databaseClose(myData);
}

//------------------------------------------------------------------------------------------------Ný Search Fölll---------------------------------
void database::openDataBaseConnection()
{
    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("./" + user + ".sqlite"); // --------------------------------------------------------------- ATHUGA hvort línan virki

    if (!myData.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
}

QString database::generalizeQuery(string query)
{
    string tempSQuery = "%"+ query +"%";
    QString searchQuery (tempSQuery.c_str());
    return searchQuery;
}

void database::searchData(vector<Scientist> &scientists, vector<Computer> &computers, string sQuery)
{
    if (string::npos != sQuery.find_first_of("0123456789"))
    {
        int year = stoi(sQuery);
        searchComputersForInt(computers, year);
        searchScientistsForInt(scientists, year);
        searchComputersForSubstring(computers, sQuery);
        searchScientistsForSubstring(scientists, sQuery);
    }
    else
    {
        searchComputersForSubstring(computers, sQuery);
        searchScientistsForSubstring(scientists, sQuery);
    }

    addBuildersToComputers(computers);
    adddBuiltComputersToScientists(scientists);
}

void database::searchComputersForSubstring(vector<Computer> &computers, const string sQuery)
{
    QString searchQuery = generalizeQuery(sQuery);

    openDataBaseConnection();

    QSqlQuery query;
    query.prepare("SELECT c.ID, Name, year_of_build, type, built_or_not FROM computers c "
                  "INNER JOIN cpuType t "
                  "ON t.ID = c.CPU_type_ID "
                  "WHERE c.name like :string "
                  "OR t.type like :string "
                  );
    query.bindValue(":string", searchQuery);
    query.exec();

    addFoundComputers(query, computers);

    myData.close();
}

void database::searchComputersForInt(vector<Computer> &computers, const int iQuery)
{
    openDataBaseConnection();

    QSqlQuery query;
    query.prepare("Select c.ID, name, year_of_build, type, built_or_not FROM computers c "
                  "INNER JOIN cpuType t "
                  "ON t.ID = c.CPU_type_ID "
                  "WHERE year_of_build = :int "
                  "OR (year_of_build/100)*100 = :int "
                  "OR (year_of_build/10)*10 = :int "
                );
    query.bindValue(":int",iQuery);
    query.exec();

    addFoundComputers(query, computers);

    myData.close();
}

void database::addFoundComputers(QSqlQuery& query, vector<Computer> &computers)
{
    while(query.next())
    {
        QString tempQ;

        int ID;
        string Name;
        int YOB;
        string cpuType;
        bool built;

        ID = query.value(0).toInt();

        tempQ = query.value(1).toString();
        Name = tempQ.toUtf8().constData();

        YOB = query.value(2).toInt();

        tempQ = query.value(3).toString();
        cpuType = tempQ.toUtf8().constData();

        built = query.value(4).toBool();

        Computer temp(ID, Name, cpuType, built, YOB);
        computers.push_back(temp);
    }
}

void database::addBuildersToComputers(vector<Computer> &computers)
{
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        int compID = computers[i].getID();

        openDataBaseConnection();

        QSqlQuery query;
        query.prepare("SELECT last_name FROM scientists s "
                      "LEFT OUTER JOIN scientist_computer_relations r "
                      "ON r.computerID = :ID "
                      "WHERE ID = r.scientistID ");
        query.bindValue(":ID", compID);
        query.exec();

        while(query.next())
        {
            QString tempQ = query.value(0).toString();
            string lastName = tempQ.toUtf8().constData();
            computers[i].addBuilder(lastName);
        }

        myData.close();
    }
}

void database::searchScientistsForSubstring(vector<Scientist> &scientists, const string sQuery)
{
    QString searchQuery = generalizeQuery(sQuery);

    openDataBaseConnection();

    QSqlQuery query;
    query.prepare("SELECT * FROM scientists s "
                  "WHERE s.first_name like :string "
                  "OR s.last_name like :string "
                  "OR s.gender like :string "
                  "OR s.nationality like :string "
                  "OR s.information like :string "
                  );
    query.bindValue(":string", searchQuery);
    query.exec();

    addFoundScientists(query, scientists);

    myData.close();
}

void database::searchScientistsForInt(vector<Scientist> &scientists, const int iQuery)
{
    openDataBaseConnection();

    QSqlQuery query;
    query.prepare("Select * FROM scientists s "
                  "WHERE year_of_birth = :int "
                  "OR (year_of_birth/100)*100 = :int "
                  "OR (year_of_birth/10)*10 = :int "
                  "OR  year_of_death = :int "
                  "OR (year_of_death/100)*100 = :int "
                  "OR (year_of_death/10)*10 = :int "
                );
    query.bindValue(":int",iQuery);
    query.exec();

    addFoundScientists(query, scientists);

    myData.close();
}

void database::addFoundScientists(QSqlQuery& query, vector<Scientist> &scientists)
{
    while(query.next())
    {
        QString tempQ;
        int ID;
        string firstName;
        string lastName;
        string gender;
        int YOB;
        int YOD;
        string nationality;
        string information;

        ID = query.value(0).toInt();

        tempQ = query.value(1).toString();
        firstName = tempQ.toUtf8().constData();

        tempQ = query.value(2).toString();
        lastName = tempQ.toUtf8().constData();

        tempQ = query.value(3).toString();
        gender = tempQ.toUtf8().constData();

        YOB = query.value(4).toInt();

        YOD = query.value(5).toInt();

        tempQ = query.value(6).toString();
        nationality = tempQ.toUtf8().constData();

        tempQ = query.value(7).toString();
        information = tempQ.toUtf8().constData();

        Scientist temp(ID,firstName, lastName, gender, YOB, YOD, nationality, information);
        scientists.push_back(temp);
    }
}

void database::adddBuiltComputersToScientists(vector<Scientist> &scientists)
{
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        int sciID = scientists[i].getID();

        openDataBaseConnection();

        QSqlQuery query;
        query.prepare("SELECT name FROM computers c "
                      "LEFT OUTER JOIN scientist_computer_relations r "
                      "ON r.ScientistID = :ID "
                      "WHERE ID = r.computerID ");
        query.bindValue(":ID", sciID);
        query.exec();

        while(query.next())
        {
            QString tempQ = query.value(0).toString();
            string computer = tempQ.toUtf8().constData();
            scientists[i].addComputerBuilt(computer);
        }

        myData.close();
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------------

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
