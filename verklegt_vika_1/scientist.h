#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

class Scientist
{
public:
    Scientist();
    Scientist(string name, string sex, int YOB, int YOD);

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
    sring _sex;
    int _yearOfBirth;
    int _yearOfDeath;
};

#endif // SCIENTIST_H
