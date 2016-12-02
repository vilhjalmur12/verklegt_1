#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, string sex, int YOB, int YOD, string nationality, string FI);

    void pushScientist(string name, string sex, int DOB, int DOD, string nationality, string FI);

/**************************************************
      Föll til að ná upplýsingum um fræðingana
**************************************************/
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

    string getNationality()
    {
        return _nationality;
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

/**************************************************
                 Operator föll
**************************************************/
    // Prentar út allar uppl um vísindamann í eina línu (aðskilið af tab-keypress)
    friend ostream& operator << (ostream& out, Scientist sc);
    // Ber saman upplýsingarnar til að sjá hvor þær séu eins
    friend bool operator == (Scientist lhs, Scientist rhs);

private:
/**************************************************
                 Meðlimabreytur
**************************************************/
    string _name;
    string _sex;
    string _furtherInfo;
    string _nationality;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // SCIENTIST_H
