#ifndef CPUTYPE_H
#define CPUTYPE_H

#include <iostream>
#include <vector>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

class CpuType
{
public:
    CpuType();
    CpuType(int id, string type);
    virtual ~CpuType();

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
