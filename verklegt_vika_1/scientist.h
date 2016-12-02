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

/**************************************************
      Föll til að ná upplýsingum um fræðingana
**************************************************/
    string getName() const;
    string getSex() const;
    int getYearOfBirth() const;
    int getYearOfDeath() const;
    string getYearOfDeathForPrinting() const ;
    string getFurtherInfo() const;

/**************************************************
                 Operator föll
**************************************************/
    friend ostream& operator << (ostream& out, Scientist sc);       // Prentar út allar uppl um vísindamann í eina línu (aðskilið af tab-keypress)
    friend bool operator == (Scientist lhs, Scientist rhs);     // Ber saman upplýsingarnar til að sjá hvor þær séu eins

private:
/**************************************************
                 Meðlimabreytur
**************************************************/
    string _name;
    string _sex;
    string _furtherInfo;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // SCIENTIST_H
