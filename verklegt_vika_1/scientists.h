#ifndef SCIENTISTS_H
#define SCIENTISTS_H

#include <string>

using namespace std;

struct Scientists
{
    string name;
    string sex;
    int birthYear;
    int deathYear;
};

Scientists readScientists();
void displayScientists(Scientists& scientists);


#endif // SCIENTISTS_H
