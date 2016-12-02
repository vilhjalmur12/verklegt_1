#include "scientist.h"
#include <iostream>

using namespace std;

Scientist::Scientist() { }

Scientist::Scientist(string name, string sex, int YOB, int YOD, string furtherInfo)
{
    _name = name;
    _sex = sex;
    _yearOfBirth = YOB;
    _yearOfDeath = YOD;
    _furtherInfo = furtherInfo;
}

void Scientist::pushScientist(string name, string sex, int DOB, int DOD, string furtherInfo)
{
    _name = name;
    _sex = sex;
    _yearOfBirth = DOB;
    _yearOfDeath = DOD;
    _furtherInfo = furtherInfo;
}  

/**************************************************
                 Operator föll
**************************************************/

ostream& operator << (ostream& out, Scientist sc)
{
   out << sc.getName() << "/t" << sc.getSex() << "/t" << sc.getYearOfBirth()
       << "/t" << sc.getYearOfDeath() << "/t" << sc.getFurtherInfo();
   return out;
}

bool operator ==(Scientist lhs, Scientist rhs)
{
   return (lhs.getName() == rhs.getName() && lhs.getSex() == rhs.getSex() && lhs.getYearOfBirth() == lhs.getYearOfBirth()
           && lhs.getYearOfDeath() == rhs.getYearOfDeath()) && lhs.getFurtherInfo() == rhs.getFurtherInfo();
}

/**************************************************
      Föll til að ná upplýsingum um fræðingana
**************************************************/
string Scientist::getName() const
{
        return _name;
}

string Scientist::getSex() const
{
        return _sex;
}

int Scientist::getYearOfBirth() const
{
        return _yearOfBirth;
}

int Scientist::getYearOfDeath() const
{
        return _yearOfDeath;
}

string Scientist::getYearOfDeathForPrinting() const
{
        if(_yearOfDeath==200000000)
            return "n/a";
        else
            return to_string(_yearOfDeath);
}

string Scientist::getFurtherInfo() const
{
        return _furtherInfo;
}
