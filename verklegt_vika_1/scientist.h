#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, string sex, int YOB, int YOD, string FI);

    void pushScientist(string name, string sex, int DOB, int DOD, string FI);

    string getName() const
    {
        return _name;
    }

    string getSex() const
    {
        return _sex;
    }

    int getYearOfBirth() const
    {
        return _yearOfBirth;
    }

    int getYearOfDeath() const
    {
        return _yearOfDeath;
    }

    string getYearOfDeathForPrinting() const
    {
        if(_yearOfDeath==200000000)
            return "n/a";
        else
            return to_string(_yearOfDeath);
    }

    string getFurtherInfo() const
    {
        return _furtherInfo;
    }

    //Prentar út allar uppl um vísindamann í eina línu (aðskilið af tab-keypress)
    friend ostream& operator << (ostream& out, Scientist sc);
    friend bool operator == (Scientist lhs, Scientist rhs);

private:
    string _name;
    string _sex;
    string _furtherInfo;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // SCIENTIST_H
