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

private:
    QSqlDatabase myData;

    void selectData ();
    string encryptData (string n);
    string decryptData (string n);

};

#endif // DATABASE_H
