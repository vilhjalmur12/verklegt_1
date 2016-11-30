#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <vector>
#include <regex>
#include "database.h"
#include "scientist.h"
#include <iostream>

using namespace std;

class Service
{
public:
    // TODO: Útfæra database fall sem skilar vísindamönnum í vector
    Service();
    virtual ~Service();

    // TODO: Útfæra database fall til að bæta einstaklingi við database
    void appendScientist(string name, string sex, int birthYear, int deathYear);

    //Fyrsta breyta er val um hvernig skuli raða
    vector<Scientist> getScientists(string choice);

    void search(string query);

private:
    vector<Scientist> _scientists;

    string fixString(string before);
    bool addName(string& name);
    bool addSex(string& sex);
    bool addYears(int birthYear, int deathYear);

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
