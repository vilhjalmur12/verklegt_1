#ifndef CPUTYPE_H
#define CPUTYPE_H

#include <iostream>
#include <database.h>
#include "service.h"
#include <vector>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

class cpuType
{
public:
    cpuType();
    cpuType(int id, string type);
    int getId ();
    string getType ();

private:
    int _ID;
    string _type;
};

#endif // CPUTYPE_H
