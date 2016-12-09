#ifndef CPUTYPE_H
#define CPUTYPE_H

#include <iostream>
#include <vector>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

class cpuType
{
public:
    cpuType();
    cpuType(string type);
    cpuType(int id, string type);
    virtual ~cpuType();

/***********************************************************
       Föll til að ná upplýsingum um tegundir tölvanna
***********************************************************/

    int getId ();
    string getType ();

private:
/***********************************************************
                        Meðlimabreytur
***********************************************************/
    int _ID;
    string _type;
};

#endif // CPUTYPE_H
