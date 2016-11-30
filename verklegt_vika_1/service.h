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

    //Fyrsta breyta er val um hvernig skuli raða
    vector<Scientist> getScientists(string choice);

    //TODO: Færa search fall frá datadrengjum í cpp
    void search(string query);

private:
    //Meðlimabreytur
    vector<Scientist> _scientists;

    //appendScientist Hjálparföll
    string fixString(string before);
    //TODO: Gera þessi föll public svo console geti notað þau!
    bool addName(string& name);
    bool addSex(string& sex);
    bool addYears(int birthYear, int deathYear);

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
