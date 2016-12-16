#include "database.h"

using namespace std;

Database::Database () {}
Database::~Database () {}

/*****************************************
 *
 *  Þetta er allt nýtt
 *
 * ***************************************/

QSqlQuery Database::showScientistData (QString username, QString searchString)
{
    string sSearch = searchString.toUtf8().constData();
    databaseOpen(username);

    string command = "SELECT First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information "
                     "FROM scientists "
                     "WHERE (First_name = '%" + sSearch + "%' "
                     "OR Last_name LIKE '%" + sSearch + "%' "
                     "OR Gender LIKE '%" + sSearch + "%' "
                     "OR Year_of_birth LIKE '%" + sSearch + "%' "
                     "OR Year_of_death LIKE '%" + sSearch + "%' "
                     "OR Nationality LIKE '%" + sSearch + "%' "
                     "OR Information LIKE '%" + sSearch + "%') "
                     "AND (Deleted = '0')";

    QString Qcommand(command.c_str());

    QSqlQuery query;
    query.exec(Qcommand);

    return query;
}

QSqlQuery Database::showComputerData (QString username, QString searchString)
{
    string sSearch = searchString.toUtf8().constData();
    databaseOpen(username);

    string command1 = "SELECT name, year_of_build, type, built_or_not "
                     "FROM Computers c "
                     "INNER JOIN cpuType t "
                     "ON t.ID = c.CPU_type_ID "
                     "where deleted = 0 "
                     "AND ("
                     "name LIKE \"%" + sSearch + "%\" "
                     "OR "
                     "year_of_build LIKE \"%" + sSearch + "%\" "
                     "OR "
                     "type LIKE \"%" + sSearch + "%\" "
                     "OR "
                     "built_or_not LIKE \"%" + sSearch + "%\")";


    QString Qcommand(command1.c_str());

    QSqlQuery query;
    query.exec(Qcommand);

    return query;
}

bool Database::computerAlreadyDeleted(QString username, int ID)
{

    string sID = to_string(ID);
    QString tmp;

    string command1 = "SELECT ID, deleted "
                     "FROM Computers "
                     "Where ID = " + sID + " ";

    QString Qcommand(command1.c_str());
    QSqlQuery query;
    query.exec(Qcommand);

    while(query.next())
    {
        tmp = query.value(1).toString();
    }

    int intTmp = tmp.toInt();
     if (intTmp == 1)
     {

         return true;
     }

     return false;
}
void Database::setUser(QString username)
{
    user = username;
}

Computer Database::getComputer(int ID)
{
    databaseOpen();

    QSqlQuery query;

    query.prepare( "SELECT c.ID, name, year_of_build, type, built_or_not FROM Computers c "
                     "INNER JOIN cpuType t "
                     "ON t.ID = c.CPU_type_ID "
                     "WHERE c.ID = :ID ");
    query.bindValue(":ID", ID);
    query.exec();

    query.next();

    Computer temp = makeComputer(query);
    addBuildersToComputer(temp);

    databaseClose();


    return temp;
}

QSqlQuery Database::getRecycledComputers (QString username)
{
    databaseOpen(username);

    string command1 = "SELECT name, year_of_build, type, built_or_not "
                     "FROM Computers c "
                     "INNER JOIN cpuType t "
                     "ON t.ID = c.CPU_type_ID "
                     "where deleted = 1 ";

    QString Qcommand(command1.c_str());

    QSqlQuery query;
    query.exec(Qcommand);

    return query;
}

QSqlQuery Database::getRecycledScientists (QString username)
{
    databaseOpen(username);

    string command1 = "SELECT First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information "
                     "FROM scientists "
                     "where Deleted = 1 ";

    QString Qcommand(command1.c_str());

    QSqlQuery query;
    query.exec(Qcommand);

    return query;
}

Scientist Database::getScientist(int ID)
{
    databaseOpen();

    QSqlQuery query;

    query.prepare("SELECT * FROM scientists "
                  "WHERE ID = :ID ");
    query.bindValue(":ID", ID);
    query.exec();

    query.next();

    Scientist temp = makeScientist(query);

    adddBuiltComputersToScientist(temp);

    databaseClose();

    return temp;
}

Scientist Database::makeScientist(QSqlQuery &query)
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

    return temp;
}

Computer Database::makeComputer(QSqlQuery &query)
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

    return temp;
}

void Database::adddBuiltComputersToScientist(Scientist &scientist)
{
    int sciID = scientist.getID();

    QSqlQuery query;
    query.prepare("SELECT name FROM computers c "
                  "LEFT OUTER JOIN scientist_computer_relations r "
                  "ON r.ScientistID = :ID "
                  "WHERE ID = r.computerID "
                  "AND c.deleted = 0 "
                  "AND r.deleted = 0 "
                  "ORDER BY name ");
    query.bindValue(":ID", sciID);
    query.exec();

    while(query.next())
    {
        QString tempQ = query.value(0).toString();
        string computer = tempQ.toUtf8().constData();
        scientist.addComputerBuilt(computer);
    }
}

void Database::addBuildersToComputer(Computer &computer)
{
    int compID = computer.getID();

    QSqlQuery query;
    query.prepare("SELECT last_name FROM scientists s "
                  "LEFT OUTER JOIN scientist_computer_relations r "
                  "ON r.computerID = :ID "
                  "WHERE ID = r.scientistID "
                  "AND r.deleted = 0 "
                  "AND s.deleted = 0 "
                  "ORDER BY last_name ");
    query.bindValue(":ID", compID);
    query.exec();

    while(query.next())
    {
        QString tempQ = query.value(0).toString();
        string lastName = tempQ.toUtf8().constData();
        computer.addBuilder(lastName);
    }
}

vector<Computer> Database::getComputersRelatedTo(int ID)
{
    vector<Computer> computers;

    databaseOpen();

    QSqlQuery query;

    query.prepare("SELECT c.ID, name, year_of_build, type, built_or_not FROM computers c "
                  "INNER JOIN cpuType t "
                  "ON t.ID = c.cpu_type_ID "
                  "LEFT OUTER JOIN scientist_computer_relations r "
                  "ON r.scientistID = :ID "
                  "WHERE c.ID = r.computerID "
                  "AND c.deleted = 0 "
                  "AND r.deleted = 0 "
                  "ORDER BY name ");
    query.bindValue(":ID", ID);
    query.exec();

    addFoundComputers(query, computers);

    databaseClose();

    return computers;
}

vector<Scientist> Database::getScientistsRelatedTo(int ID)
{
    databaseOpen();

    vector<Scientist> scientists;

    QSqlQuery query;
    query.prepare("SELECT * FROM scientists s "
                  "LEFT OUTER JOIN scientist_computer_relations r "
                  "ON r.computerID = :ID "
                  "WHERE ID = r.scientistID "
                  "AND r.deleted = 0 "
                  "AND s.deleted = 0 "
                  "ORDER BY last_name ");
    query.bindValue(":ID", ID);
    query.exec();

    addFoundScientists(query, scientists);

    databaseClose();

    return scientists;
}

void Database::restoreRelations(int cID, int sID)
{
    databaseOpen();


    QSqlQuery query;
    query.prepare("UPDATE scientist_computer_relations "
                  "SET deleted = 0 "
                  "WHERE(scientistID = :sID AND computerID = :cID)");
    query.bindValue(":sID", sID);
    query.bindValue(":cID", cID);
    query.exec();


    databaseClose(myData);
}

void Database::databaseOpen(QString username)
{
    user = username;

    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("./" + username + ".sqlite");

    if (!myData.open())
    {
       //qDebug() << "Error: connection with database fail";
    }
}

void Database::databaseClose()
{
    QString connection;
    connection = myData.connectionName();
    myData.close();
    myData = QSqlDatabase();
    QSqlDatabase::removeDatabase(connection);
}

void Database::deleteScientist(QString username, QString name, QString lastName, QString year)
{
    databaseOpen(username);


    string sName = name.toUtf8().constData();
    string sLastName = lastName.toUtf8().constData();
    string sYear = year.toUtf8().constData();
    QSqlQuery query;
    string command = "UPDATE scientists "
                     "SET Deleted = '1' "
                     "WHERE First_name = \'" + sName + "\' "
                     "AND Last_name = \'" + sLastName + "\' "
                     "AND Year_of_birth = \'" + sYear + "\'";

    QString qCommand(command.c_str());
    query.exec(qCommand);

    databaseClose();
}

void Database::deleteComputer(QString username, QString name, QString year)
{
    databaseOpen(username);
    QSqlQuery query;

    string sName = name.toUtf8().constData();
    string sYear = year.toUtf8().constData();
    string command = "UPDATE computers "
                     "SET Deleted = '1' "
                     "WHERE Name = \'" + sName + "\' "
                     "AND Year_of_build = " + sYear + "";

    QString qCommand(command.c_str());
    query.exec(qCommand);

    databaseClose();
}

/**********************************************/


void Database::databaseOpen()
{
    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("./" + user + ".sqlite");

    if (!myData.open())
    {
       //qDebug() << "Error: connection with database fail";
    }
}

void Database::databaseClose(QSqlDatabase &data)
{
    QString connection;
    connection = data.connectionName();
    data.close();
    data = QSqlDatabase();
    QSqlDatabase::removeDatabase(connection);
}

void Database::getData(QString username, vector<Scientist> &scien)
{

   user = username;
   vector<Scientist> newScien =  scien;
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("./" + user + ".sqlite");

   if (!myData.open())
   {
      //qDebug() << "Error: connection with database fail";
   }
   else
   {
       databaseClose(myData);
   }
}


void Database::getData()
{
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("./" + user + ".sqlite");

   if (!myData.open())
   {
      //qDebug() << "Error: connection with database fail";
   }
   else
   {
        databaseClose(myData);
   }
}

/******************************************************************
                      pullComputers
     Sækir allar tölvur úr gagnagrunni
     @return(vector<Scientist> scientists) - vector af vísindamönnum
 ******************************************************************/

vector<Scientist> Database::pullScientists(string choice)
{
    databaseOpen();

    vector<Scientist> scientists;

    string command = "SELECT * FROM Scientists where deleted = 0 ORDER BY " + choice + ", last_name";

    QString Qcommand(command.c_str());

    QSqlQuery query;
    query.exec(Qcommand);

    addFoundScientists(query, scientists);
    adddBuiltComputersToScientists(scientists);

    databaseClose(myData);

    return scientists;
}

/******************************************************************
                      pullDeletedScientists
     Sækir þá vísindamenn sem búið er að flagga sem deleted úr gagnagrunni
     @return(vector<Scientist> scientists) - vector af vísindamönnum
        sem búið er að eyða
 ******************************************************************/

vector<Scientist> Database::pullDeletedScientists()
{
    databaseOpen();

    vector<Scientist> scientists;

    QSqlQuery query;

    query.exec("SELECT * FROM scientists "
               "WHERE deleted = 1 "
               "ORDER BY last_name ");

    addFoundScientists(query, scientists);

    databaseClose(myData);

    return scientists;
}

/******************************************************************
                      pullComputers
     Sækir allar tölvur úr gagnagrunni
     @return(vector<Computer> computers) - vector af tölvum
 ******************************************************************/

vector<Computer> Database::pullComputers(string choice)
{
    databaseOpen();

    vector<Computer> computers;

    string command = "SELECT c.ID, name, year_of_build, type, built_or_not FROM Computers c "
                     "INNER JOIN cpuType t "
                     "ON t.ID = c.CPU_type_ID "
                     "where deleted = 0 "
                     "ORDER BY " + choice +", name";

    //QString Qchoice(choice.c_str());
    QString Qcommand(command.c_str());

    QSqlQuery query;
    query.exec(Qcommand);

    addFoundComputers(query, computers);
    addBuildersToComputers(computers);

    databaseClose(myData);

    return computers;
}

/******************************************************************
                      pullDeletedComputers
     Sækir þær tölvur sem búið er að flagga sem deleted úr gagnagrunni
     @return(vector<Computer> computers) - vector af tölvum sem búið
        er að eyða
 ******************************************************************/

vector<Computer> Database::pullDeletedComputers()
{
    databaseOpen();

    vector<Computer> computers;

    QSqlQuery query;
    query.exec("SELECT c.ID, name, year_of_build, type, built_or_not FROM Computers c "
               "INNER JOIN cpuType t "
               "ON t.ID = c.CPU_type_ID "
               "where deleted = 1 "
               "ORDER BY name");

    addFoundComputers(query, computers);

    databaseClose(myData);

    return computers;
}

/******************************************************************
                      getUser
     Sækir notenda og lykilorð úr gagnagrunni
     @parameter(const QString& username) - bendir á notendanaf
     @parameter(const QString& password) - bendir á lykilorð
 ******************************************************************/

bool Database::getUser(const QString& username, const QString& password)
{


    user = username;
    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("users.sqlite");

    if (!myData.open())
    {
       errorOut.dataErrorFound();
    }
    else
    {
        //qDebug() << username;

        QSqlQuery query;
        query.prepare("SELECT password FROM users WHERE username = :user");
        query.bindValue(":user", username);
        query.exec();



        QString qPass;
        QString QEncPass;
        if (query.next())
        {
            qPass = query.value(0).toString();
            string tmpPass = qPass.toUtf8().constData();
            string encPass = decryptData(tmpPass);
            QString QTmpPass(encPass.c_str());
            QEncPass = QTmpPass;

            //cout << tmpPass << endl;
            cout << encPass << endl;
        }

        if (password == QEncPass)
        {

            databaseClose(myData);
            getData();
            return true;
        }      
    }
    databaseClose(myData);
    return false;
}

/******************************************************************
                      createUser
     Býr til nýjan user í sér user gagnagrunn
     @parameter(const QString& username) - bendir á notendanaf
     @parameter(const QString& password) - bendir á lykilorð
     @parameter(const QString& firstName) - bendir á fyrra nafn
     @parameter(const QString& lastName) - notenda bendir á eftirnafn
 ******************************************************************/

bool Database::createUser(const QString& username, const QString& password, const QString& firstName, const QString& lastName)
{
    user = username;
    myData = QSqlDatabase::addDatabase("QSQLITE");
    myData.setDatabaseName("./users.sqlite");

    string tmpPass = password.toUtf8().constData();
    string encPass = encryptData(tmpPass);
    QString QEncPass(encPass.c_str());

    if (!myData.open())
    {
       //qDebug() << "Error: connection with database fail";
    }
    else
    {   
        if(noUserInserted(username)||userExisting(username))
        {
            return false;
        }

        QSqlQuery query;

        query.prepare("CREATE TABLE users(first_name VARCHAR NOT NULL, last_name VARCHAR NOT NULL, username VARCHAR NOT NULL, password VARCHAR NOT NULL)");
        query.exec();

        query.prepare("INSERT INTO users (first_name, last_name, username, password)" "VALUES (:firstName, :lastName, :username, :password)");
        query.bindValue(":firstName", firstName);
        query.bindValue(":lastName", lastName);
        query.bindValue(":username", username);
        query.bindValue(":password", QEncPass);
        query.exec();

        databaseClose(myData);

        initDatabase(username);
    }
    return true;
}

bool Database::userExisting(QString username)
{

    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE username = :user");
    query.bindValue(":user", username);
    query.exec();

    if(query.next())
    {
        return true;
    }

    return false;
}

bool Database::noUserInserted (QString username)
{
    QString tmp = "";

    if (username == tmp)
    {
        return true;
    }
    return false;
}

/******************************************************************
                      initDatabase
     Frumstillir gagnagrunn fyrir sérhvern notanda sem búin er til
     @parameter(const QString& username) - notenda nafn
 ******************************************************************/

void Database::initDatabase (const QString& username)
{
    QSqlDatabase userData = QSqlDatabase::addDatabase("QSQLITE");
    userData.setDatabaseName("./" + username + ".sqlite");


    if (!userData.open())
    {
       //qDebug() << "Error: connection with database fail";
    }
    else
    {
        QSqlQuery userQuery;
        userQuery.exec("PRAGMA foreign_keys = ON");

        userQuery.exec("CREATE  TABLE scientists "
                       "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                        "First_name VARCHAR NOT NULL , Last_name VARCHAR NOT NULL , "
                        "Gender VARCHAR, Year_of_birth INTEGER, Year_of_death INTEGER, "
                        "Nationality VARCHAR, Information VARCHAR, 'Deleted' BOOL DEFAULT (0))");

        userQuery.exec ("CREATE  TABLE cpuType "
                      "(ID INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL , "
                      "type VARCHAR NOT NULL )");

        userQuery.exec ("CREATE TABLE computers "
                        "('ID' INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL, "
                        "'Name' VARCHAR NOT NULL, "
                        "'Year_of_build' INTEGER, "
                        "'CPU_type_ID' INTEGER, "
                        "'built_or_not' BOOL, "
                        "'deleted' BOOL DEFAULT (0), "
                        "FOREIGN KEY(CPU_type_ID) REFERENCES cpuType(ID))");

        userQuery.exec("CREATE TABLE scientist_computer_relations"
                       "(scientistID INTEGER, "
                       "computerID INTEGER, "
                       "'deleted' BOOL DEFAULT (0), "
                       "FOREIGN KEY (computerID) REFERENCES Computers(ID), "
                       "FOREIGN KEY (scientistID) REFERENCES Scientists(ID) "
                       "PRIMARY KEY (computerID, scientistID)) ");

        /**************************************
                setja inn vísindamann
        **************************************/

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

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Tommy', 'Flowers', 'Male', 1905, 1998, 'English', 'First programmable electronic computer')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Freddie', 'Williams', 'Male', 1911, 1977, 'English', 'Engineer')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Tom', 'Kilburn', 'Male', 1921, 2001, 'English', 'Mathematician and computer scientist')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Gordon', 'Bell', 'Male', 1934, 200000000, 'American', 'Electrical engineer')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Charles', 'Flint', 'Male', 1850, 1934, 'American', 'Financial capalist')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Clive', 'Sinclair', 'Male', 1940, 200000000, 'English', 'Entrepreneur and inventor')");

        userQuery.exec("INSERT INTO scientists "
                          "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information)"
                          "VALUES ('Steve', 'Jobs', 'Male', 1955, 2011, 'American', 'Co-founder Apple and more.')");


        /**************************************
                      setja inn type
        **************************************/

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Mechanic')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Electronic')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Transistor Machine')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Mainframe computer')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Mini computer')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Personal computer')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Home computer')");

        userQuery.exec("INSERT INTO cpuType "
                          "(Type)"
                          "VALUES ('Calculator')");

        /**************************************
                    setja inn tölvu
        **************************************/

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not)"
                          "VALUES ('Analytical engine', 200000000, 1, 0)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('ENIAC', 1946, 2, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('Mailufterl', 1958, 3, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('Difference Engine', 1991, 1, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('The Abacus', -2000, 8, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('Colossus', 1944, 2, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('The Manchester Baby', 1948, 2, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('IBM System 360', 1964, 4, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('DEC PDP-8', 1965, 5, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('IBM PC', 1981, 6, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('Sinclair ZX81', 1981, 7, 1)");

        userQuery.exec("INSERT INTO computers "
                          "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                          "VALUES ('Apple Macintosh', 1981, 6, 1)");

        /**************************************
                      setja inn vensl
        **************************************/

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

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (5,6)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (6,7)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (7,7)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (8,9)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (9,8)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (9,10)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (10,11)");

        userQuery.exec("INSERT INTO scientist_computer_relations "
                       "(ScientistID, ComputerID) "
                       "VALUES (11,12)");

        databaseClose(userData);
    }
}

/******************************************************************
                      pullTypes
     Sækir allar týpur af tölvum úr gagnagrunni
     @parameter(string order) - ákvörðun frá notanda
     @return(vector<CpuType>cpu) - vector af týpum
 ******************************************************************/

vector<CpuType> Database::pullTypes(string order)
{
    string execute = "SELECT * From cpuType "
                     "ORDER BY " + order;

    databaseOpen();

    vector<CpuType> cpu;
    CpuType tmpCpu;
    QString QCpu;
    QString Qorder(execute.c_str());
    string tmpCpuString;
    int tmpID;
    QSqlQuery query;

    query.exec(Qorder);

    while (query.next())
    {
        tmpID = query.value(0).toInt();
        QCpu = query.value(1).toString();
        tmpCpuString = QCpu.toUtf8().constData();
        CpuType tmpCpu(tmpID, tmpCpuString);

        cpu.push_back(tmpCpu);
    }

    databaseClose(myData);

    return cpu;
}

/******************************************************************
                      insertScientist
     Býr til nýtt eintak af vísindamanni í gagnagrunn
     @parameter(Scientist scientist) - Eintak af computer
 ******************************************************************/

void Database::insertScientist (Scientist scientist)
{
       databaseOpen();

       QString tmpFirstName(scientist.getFirstName().c_str());
       QString tmpLastName(scientist.getLastName().c_str());
       QString tmpGender(scientist.getSex().c_str());
       int tmpYOB = scientist.getYearOfBirth();
       int tmpYOD = scientist.getYearOfDeath();
       QString tmpNation(scientist.getNationality().c_str());
       QString tmpInfo(scientist.getFurtherInfo().c_str());

       QSqlQuery query;
       query.prepare("INSERT INTO scientists "
                     "(First_name, Last_name, Gender, Year_of_birth, Year_of_death, Nationality, Information) "
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

/******************************************************************
                      insertComputer
     Býr til nýtt eintak af tölvu í gagnagrunn
     @parameter(Computer computer) - Eintak af computer
 ******************************************************************/
void Database::insertComputer (Computer computer, QString tmpUser)
{
       user = tmpUser;
       databaseOpen();

       QString tmpName(computer.getName().c_str());
       QString tmpCpuType(computer.getCpuType().c_str());
       int tmpType = getTypeId(tmpCpuType);
       int tmpYB = computer.getYearBuilt();
       bool tmpBuilt = computer.getBuilt();

       QSqlQuery query;
       query.prepare("INSERT INTO computers "
                     "(Name, Year_of_build, CPU_type_ID, built_or_not) "
                     "VALUES (:name, :YOB, :type, :BON)");
       query.bindValue(":name", tmpName);
       query.bindValue(":YOB", tmpYB);
       query.bindValue(":type", tmpType);
       query.bindValue(":BON", tmpBuilt);
       query.exec();

       databaseClose(myData);
}

/******************************************************************
                      getTypeId
     Sækir ID fyrir ákveðna týpu af tölvu
     @parameter(QString type) - Nafn á týpu
     @return(int query2.value(0).toInt();) - ID á týpu
 ******************************************************************/

int Database::getTypeId(QString type)
{
    QSqlQuery query2;

    query2.prepare("SELECT ID FROM cpuType "
                   "WHERE type = :type ");
    query2.bindValue(":type",type);
    query2.exec();

    query2.next();

    return query2.value(0).toInt();

}

/******************************************************************
                      insertType
     Notandi getur bætt við nýrri týpu af tölvu.
     @parameter(string type) - Nafn á týpu
 ******************************************************************/

void Database::insertType(string type)
{
    databaseOpen();

    QString Qtype(type.c_str());

    QSqlQuery query;
    query.prepare("INSERT INTO cpuType (type) "
                  "VALUES (:type) ");
    query.bindValue(":type", Qtype);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                      editComputer
     Tekur inn ID fyrir valin vísindamann og leyfir notenda að edit-a
     upplýsingar um hann
     Edit fall fyrir vísindamann.
     @parameter(int ID) - ID fyrir tölvu
     @parameter(Computer computer) - Eintak af computer
 ******************************************************************/

void Database::editComputer(int ID, Computer computer)
{
    databaseOpen();

    int type = getTypeId(QString::fromStdString(computer.getCpuType()));
    int built;
    if(computer.getBuilt())
        built = 1;
    else
        built = 0;

    QSqlQuery query;
    query.prepare("UPDATE computers "
                  "SET name = :name, cpu_type_ID = :type, "
                  "year_of_build = :build, built_or_not = :built "
                  "WHERE ID = :ID");
    query.bindValue(":name", QString::fromStdString(computer.getName()));
    query.bindValue(":type", type);
    query.bindValue(":build", computer.getYearBuilt());
    query.bindValue(":built", built);
    query.bindValue(":ID", ID);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                      editScientist
     Tekur inn ID fyrir valin vísindamann og leyfir notenda að edit-a
     upplýsingar um hann
     Edit fall fyrir vísindamann.
     @parameter(int ID) - ID fyrir vísindamann
     @parameter(Scientist scientist) - Eintak af scientist
 ******************************************************************/

void Database::editScientist(int ID, Scientist scientist)
{
    databaseOpen();

    QSqlQuery query;
    query.prepare("UPDATE scientists "
                  "SET first_name = :first, last_name = :last, gender = :gender, "
                  "year_of_birth = :birth, year_of_death = :death, nationality = :nationality, "
                  "information = :info "
                  "WHERE ID = :ID");
    query.bindValue(":first", QString::fromStdString(scientist.getFirstName()));
    query.bindValue(":last", QString::fromStdString(scientist.getLastName()));
    query.bindValue(":gender", QString::fromStdString(scientist.getSex()));
    query.bindValue(":birth", scientist.getYearOfBirth());
    query.bindValue(":death", scientist.getYearOfDeath());  ///SKOÐA BETUR EF VISINDAMADUR ER LIFANDI
    query.bindValue(":nationality", QString::fromStdString(scientist.getNationality()));
    query.bindValue(":info", QString::fromStdString(scientist.getFurtherInfo()));
    query.bindValue(":ID", ID);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                      getNumberOfComputerEntries
     Finnur fjölda af tölvum.
      @return(int ID) - fjöldi tölva
 ******************************************************************/

int Database::getNumberOfComputerEntries()
{
    databaseOpen();

    QSqlQuery query;
    query.exec("SELECT MAX(ID) FROM computers");

    query.next();
    int ID = query.value(0).toInt();

    databaseClose(myData);

    return ID;
}

/******************************************************************
                      getNumberOfScientistEntries
     Finnur fjölda af vísindamönnum.
     @return(int ID) - fjöldi vísindamanna
 ******************************************************************/

int Database::getNumberOfScientistEntries()
{
  databaseOpen();

  QSqlQuery query;
  query.exec("SELECT MAX(ID) FROM scientists");

  query.next();
  int ID = query.value(0).toInt();

  databaseClose(myData);

  return ID;
}

/******************************************************************
                      generalizeQuery
     Tekur við leitar streng frá notenda og breytir í Qstring.
     @parameter(string query) - Leitar strengur frá notanda
     @return(QString searchQuery) - Qstrengur af leitarstreng
 ******************************************************************/

QString Database::generalizeQuery(string query)
{
    string tempSQuery = "%"+ query +"%";
    QString searchQuery (tempSQuery.c_str());
    return searchQuery;
}

/******************************************************************
                      searchData
     Tekur við leitar streng frá notenda, ákveður hvað á að gera við hann.
     @parameter(vector<Scientist> &scientists) - Vector af bendum á tölvur
     @parameter(vector<Computer> &computers) - Vector af bendum á tölvur
     @parameter(QSqlQuery& query) - QSqlQuery af leitarstreng
 ******************************************************************/

void Database::searchData(vector<Scientist> &scientists, vector<Computer> &computers, string sQuery)
{
    databaseOpen();

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

    databaseClose(myData);
}

/******************************************************************
                      searchComputersForSubstring
     Leitar í tölvum eftir leitarstreng
     @parameter(vector<Computer> &computers) - Vector af bendum á tölvur
     @parameter(QSqlQuery& query) - QSqlQuery af leitarstreng
 ******************************************************************/

void Database::searchComputersForSubstring(vector<Computer> &computers, const string sQuery)
{
    QString searchQuery = generalizeQuery(sQuery);

    QSqlQuery query;
    query.prepare("SELECT c.ID, Name, year_of_build, type, built_or_not FROM computers c "
                  "INNER JOIN cpuType t "
                  "ON t.ID = c.CPU_type_ID "
                  "WHERE (c.name like :string "
                  "OR t.type like :string) "
                  "AND deleted = 0 "
                  "ORDER BY name "
                  );
    query.bindValue(":string", searchQuery);
    query.exec();

    addFoundComputers(query, computers);
}

/******************************************************************
                      searchComputersForInt
     Leitar í tölvum af integer
     @parameter(vector<Computer> &computers) - Vector af bendum á tölvur
     @parameter(QSqlQuery& query) - QSqlQuery af interger
 ******************************************************************/

void Database::searchComputersForInt(vector<Computer> &computers, const int iQuery)
{
    QSqlQuery query;
    query.prepare("Select c.ID, name, year_of_build, type, built_or_not FROM computers c "
                  "INNER JOIN cpuType t "
                  "ON t.ID = c.CPU_type_ID "
                  "WHERE (year_of_build = :int "
                  "OR (year_of_build/100)*100 = :int "
                  "OR (year_of_build/10)*10 = :int) "
                  "AND deleted = 0 "
                  "ORDER BY name"
                );
    query.bindValue(":int",iQuery);
    query.exec();

    addFoundComputers(query, computers);
}

/******************************************************************
                      addFoundComputers
     Bætir tölvu sem fannst við leit í vektor
     @parameter(QSqlQuery& query) - Bendir á QSqlQuery af leitarstreng
     @parameter(vector<Scientist> &scientists) - Vector af bendum á vísindamenn
 ******************************************************************/

void Database::addFoundComputers(QSqlQuery& query, vector<Computer> &computers)
{
    while(query.next())
    {
        Computer temp = makeComputer(query);
        computers.push_back(temp);
    }
}

/******************************************************************
                      addBuildersToComputers
     Bætir vísindamanni við tölvu
     @parameter(vector<Scientist> &scientists) - Vector af bendum á vísindamenn
 ******************************************************************/

void Database::addBuildersToComputers(vector<Computer> &computers)
{
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        addBuildersToComputer(computers[i]);
    }
}

/******************************************************************
                      searchScientistsForSubstring
     Leitar að vísindamönnum eftir leitar streng
     @parameter(vector<Scientist> &scientists) - Vector af bendum á vísindamenn
     @parameter(const string sQuery) - Leitarstrengur frá notenda
 ******************************************************************/

void Database::searchScientistsForSubstring(vector<Scientist> &scientists, const string sQuery)
{
    QString searchQuery = generalizeQuery(sQuery);

    QSqlQuery query;
    query.prepare("SELECT * FROM scientists s "
                  "WHERE (s.first_name like :string "
                  "OR s.last_name like :string "
                  "OR s.gender like :string "
                  "OR s.nationality like :string "
                  "OR s.information like :string) "
                  "AND deleted = 0 "
                  "ORDER BY last_name "
                  );
    query.bindValue(":string", searchQuery);
    query.exec();

    addFoundScientists(query, scientists);
}

/******************************************************************
                      searchScientistsForInt
     Leitar í vísindamönnum eftir ártali(öld eða áratug)
     @parameter(vector<Scientist> &scientists) - Vector af bendum á vísindamenn
     @parameter(const int iQuery) - ártals leit frá notanda
 ******************************************************************/

void Database::searchScientistsForInt(vector<Scientist> &scientists, const int iQuery)
{
    QSqlQuery query;
    query.prepare("Select * FROM scientists s "
                  "WHERE (year_of_birth = :int "
                  "OR (year_of_birth/100)*100 = :int "
                  "OR (year_of_birth/10)*10 = :int "
                  "OR  year_of_death = :int "
                  "OR (year_of_death/100)*100 = :int "
                  "OR (year_of_death/10)*10 = :int) "
                  "AND deleted = 0 "
                );
    query.bindValue(":int",iQuery);
    query.exec();

    addFoundScientists(query, scientists);
}

/******************************************************************
                      addFoundScientists
     Bætir vísindamanni sem fannst við leit í vektor
     @parameter(QSqlQuery& query) - Bendir á QSqlQuery af leitarstreng
     @parameter(vector<Scientist> &scientists) - Vector af bendum á vísindamenn
 ******************************************************************/

void Database::addFoundScientists(QSqlQuery& query, vector<Scientist> &scientists)
{
    while(query.next())
    {
        Scientist temp = makeScientist(query);
        scientists.push_back(temp);
    }
}

/******************************************************************
                      adddBuiltComputersToScientists
     Býður notenda upp á að búa til vensl milli nýrra tölva og vísindamanna
     @parameter(vector<Scientist> &scientists) - Vector af bendum á vísindamenn
 ******************************************************************/

void Database::adddBuiltComputersToScientists(vector<Scientist> &scientists)
{
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        adddBuiltComputersToScientist(scientists[i]);
    }
}


// ----------------------------------------------------------------------------------------------------------------------------------------------------------

/******************************************************************
                      addRelations
     Býr til vensl á milli vísindamans og tölvu
     @parameter(int cID) - ID fyrir tölvu
     @parameter(int sID) - ID fyrir vísindamann
 ******************************************************************/

void Database::addRelations(int cID, int sID)
{
   databaseOpen();


   QSqlQuery query;
   query.prepare("INSERT INTO scientist_computer_relations(scientistID, computerID) "
                 "VALUES (:sID, :cID)");
   query.bindValue(":sID", sID);
   query.bindValue(":cID", cID);
   query.exec();


   databaseClose(myData);
}

/******************************************************************
                      removeRelations
     Fjarlægir vensl á milli vísindamans og tölvu
     @parameter(int cID) - ID fyrir tölvu
     @parameter(int sID) - ID fyrir vísindamann
 ******************************************************************/
void Database::removeRelations(int cID, int sID)
{
    databaseOpen();


    QSqlQuery query;
    query.prepare("UPDATE scientist_computer_relations "
                  "SET deleted = 1 "
                  "WHERE(scientistID = :sID AND computerID = :cID)");
    query.bindValue(":sID", sID);
    query.bindValue(":cID", cID);
    query.exec();


    databaseClose(myData);
}

/******************************************************************
                      selectData

 ******************************************************************/

void Database::selectData()
{

    QSqlQuery query("SELECT * FROM cpuType");
    int idName = query.record().indexOf("type");
    while (query.next())
    {
       QString name = query.value(idName).toString();
       //qDebug() << name;
    }
}


/******************************************************************
                     encryptData
    Auðveldur ceaser cypher sem dulkóðar streng
            @parameter(string n) - venjulegur strengur
            @return(string n) - dulkóðaður strengur
 ******************************************************************/

string Database::encryptData (string n)
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

string Database::decryptData (string n)
{
    for(unsigned int u=0; u < n.size(); u++){
        n[u]++;
    }
    return n;
}

/******************************************************************
                      deleteAllFromDatabase
    Fall sem eyðir öllu út úr Database
 ******************************************************************/

void Database::deleteAllFromDatabase()
{
    deleteAllFromComputerDatabase();
    deleteAllFromScientistDatabase();
}

/******************************************************************
                      deleteAllFromComputerDatabase
    Fall sem eyðir öllu út úr computer database
 ******************************************************************/

void Database::deleteAllFromComputerDatabase()
{
    int doDeleted = 1;

    databaseOpen();

    QSqlQuery query;
    query.prepare("UPDATE computers SET deleted = :deleted " );
    query.bindValue(":deleted", doDeleted);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                      deleteAllFromScientistDatabase
    Fall sem eyðir öllu út úr scientist Database
 ******************************************************************/

void Database::deleteAllFromScientistDatabase()
{
    int doDeleted = 1;

    databaseOpen();

    QSqlQuery query;
    query.prepare("UPDATE scientists SET Deleted = :deleted " );
    query.bindValue(":deleted", doDeleted);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                          deleteScientist
         Hægt er að velja hvaða vísindamanni verður eytt
             @parameter(int ID) - ID fyrir vísindamann sem á að eyða
 ******************************************************************/

void Database::deleteScientist(int ID)
{
    databaseOpen();

    QSqlQuery query;
    query.prepare("UPDATE scientists "
                  "SET deleted = 1 "
                  "WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                     restoreAllFromDatabase
             Kallar í föll til að setja setja allt sem hefur verið
             eytt aftur í töflur
 ******************************************************************/

void Database::restoreAllFromDatabase()
{
    restoreAllFromComputerDatabase();
    restoreAllFromScientistDatabase();
}

/******************************************************************
                   restoreAllFromComputerDatabase
    Tekur allar tölvur sem búið er að flagga sem "deleted" og
    og setur þær aftur í gagnagrunn
 ******************************************************************/

void Database::restoreAllFromComputerDatabase()
{
    databaseOpen();

    QSqlQuery query;
    query.exec("UPDATE computers SET DELETED = 0");

    databaseClose(myData);
}

/******************************************************************
                   restoreAllFromScientistDatabase
    Tekur alla vísindamenn sem búið er að flagga sem "deleted" og
    og setur þá aftur í gagnagrunn
 ******************************************************************/

void Database::restoreAllFromScientistDatabase()
{
    databaseOpen();

    QSqlQuery query;
    query.exec("UPDATE scientists SET DELETED = 0");

    databaseClose(myData);
}

/******************************************************************
                          deleteComputer
    Tekur við ID-i fyrir tölvu sem á að flagga sem "deleted" og
    og þar með fjarlægja úr gagnagrunn
             @parameter(int ID) - ID fyrir tölvu sem á að af fjarlægja
 ******************************************************************/

void Database::deleteComputer(int ID)
{
    databaseOpen();

    QSqlQuery query;
    query.prepare("UPDATE computers "
                  "SET deleted = 1 "
                  "WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                          restoreScientist
    Tekur við ID-i fyrir vísindamann sem búið er að flagga sem "deleted" og
    og á að setja aftur í gagnagrunn
             @parameter(int ID) - ID fyrir vísindamann sem á að af flagga
 ******************************************************************/

void Database::restoreScientist(int ID)
{
    databaseOpen();

    QSqlQuery query;
    query.prepare("UPDATE scientists "
                  "SET DELETED = (0) "
                  "WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();

    databaseClose(myData);
}

/******************************************************************
                          restoreComputer
    Tekur við ID-i fyrir tölvu sem búið er að flagga sem "deleted" og
    og á að setja aftur í gagnagrunn
             @parameter(int ID) - ID fyrir tölvu sem á að af flagga
 ******************************************************************/

void Database::restoreComputer(int ID)
{
    databaseOpen();

    QSqlQuery query;
    query.prepare("UPDATE computers "
                  "SET deleted = (0) "
                  "WHERE ID = :ID");
    query.bindValue(":ID", ID);
    query.exec();

    databaseClose(myData);
}

string Database::pullUser()
{
    return user.toUtf8().constData();
}
