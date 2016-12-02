#ifndef SERVICE_H
#define SERVICE_H

#include "errorhandling.h"
#include "scientist.h"
#include "database.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>

using namespace std;

class Service
{
public:
    Service();
    virtual ~Service();

    bool appendScientist(string name, string sex, int birthYear, int deathYear, string furtherInfo);
    void removeScientist(int index);

    void moveLastTo(int index);

    bool validName(string& name);
    bool validSex(string& sex);
    bool validYears(int birthYear, int deathYear);
    void saveData ();

    //Fyrsta breyta er val um hvernig skuli raða
    vector<Scientist> getScientists();
    void SortedScientistsBy(string choice = "na");

    //TODO: Færa search fall frá datadrengjum í cpp
    vector<int> getIndexesWith(string query);

private:
    //Meðlimabreytur
    vector<Scientist> _scientists;
    ErrorHandling throwError;
    database data;

    //appendScientist Hjálparföll
    string removeSpaces(string& before);
    string fixString(string& before);

    //search Hjálparföll
    bool findInInt(int query, int year);
    bool findInString(string query, string string);

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
