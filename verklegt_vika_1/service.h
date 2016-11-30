#ifndef SERVICE_H
#define SERVICE_H

#include "database.h"
#include "scientist.h"
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

class Service
{
public:
    Service();
    virtual ~Service();

    void appendScientist(string name, string sex, int birthYear, int deathYear);

    bool rightName(string& name);
    bool rightSex(string& sex);
    bool rightYears(int birthYear, int deathYear);

    //Fyrsta breyta er val um hvernig skuli raða
    vector<Scientist> getScientists(string choice);

    //TODO: Færa search fall frá datadrengjum í cpp
    void search(string query);

private:
    //Meðlimabreytur
    vector<Scientist> _scientists;

    //appendScientist Hjálparföll
    string removeSpaces(string before);
    string fixString(string before);

    //getScientists - sorting algrímar
    void sortByNameAscending();
    void sortByNameDesending();
    void sortBySexF();
    void sortbySexM();
    void sortByBirthAscending();
    void sortByBirthDescending();
    void sortByDeathAscending();
    void sortByDeathDescending();

};

#endif // SERVICE_H
