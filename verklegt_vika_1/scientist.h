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
    
    string getName()
    {
        return _name;
    }

    string getSex()
    {
        return _sex;
    }

    int getYearOfBirth()
    {
        return _yearOfBirth;
    }

    int getYearOfDeath()
    {
        return _yearOfDeath;
    }


private:
    string _name;
    string _sex;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // SCIENTIST_H
