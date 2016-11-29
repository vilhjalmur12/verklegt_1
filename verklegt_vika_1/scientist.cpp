#include "scientist.h"
#include <iostream>

using namespace std;

Scientist::Scientist()
{

}

Scientist::Scientist(string name, string sex, int YOB, int YOD)
{
    _name = name;
    _sex = sex;
    _yearOfBirth = YOB;
    _yearOfDeath = YOD;
}

ostream& operator << (ostream& out, Scientist sc)
{
    out << sc.getName() << "/t" << sc.getSex() << "/t" << sc.getYearOfBirth() << "/t" << sc.getYearOfDeath();
    return out;
}
