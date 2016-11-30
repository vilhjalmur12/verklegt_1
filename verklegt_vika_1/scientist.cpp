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
    
    

 ostream& operator << (ostream& out, Scientist sc)
 {
    out << sc.getName() << "/t" << sc.getSex() << "/t" << sc.getYearOfBirth()
        << "/t" << sc.getYearOfDeath() << "/t" << sc.getfurtherInfo();
    return out;
 }
