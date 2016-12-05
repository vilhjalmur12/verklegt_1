#include "database.h"
#include <iostream>
#include "scientist.h"
#include <vector>
#include <QDebug>
#include <QSqlQuery.h>
#include <QSqlRecord.h>


using namespace std;

database::database () {}
database::~database () {}

// ætti að fara inn í constructor: const QString& path ef við viljum útbúa spes path.
database::database()
{
   myData = QSqlDatabase::addDatabase("QSQLITE");
   myData.setDatabaseName("/Users/villi/Desktop/Verklegt\ Git/Qt_test/sql_test/computers.sqlite");

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
