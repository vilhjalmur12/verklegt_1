#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, string sex, int YOB, int YOD);

    void pushScientist(string name, string sex, int DOB, int DOD);
<<<<<<< HEAD


    
  //  string getName();


    
  //  string getName();

=======
>>>>>>> 4fc601ca142b69fbc59b3eca55fa4f433038a9ff

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

    //Prentar út allar uppl um vísindamann í eina línu (aðskilið af tab-keypress)
    friend ostream& operator << (ostream& out, Scientist sc);


private:
    string _name;
    string _sex;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // SCIENTIST_H
