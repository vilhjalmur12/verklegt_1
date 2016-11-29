#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <vector>
#include <regex>
#include "database.h"
#include <iostream>

using namespace std;

class Service
{
public:
    Service();

    //Tekur inn nafn, aldur, fæðingar- og dánarár ásamt samsvarandi vectorum
    void addPerson(string name, string sex, int birthYear, int deathYear, vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);

    //Fyrsta breyta er val um hvernig skuli raða, listi skipanna fylgir falli. Tekur einnig inn vectoranna fjóra
    void sort(string choice, vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);

    //Tekur inn það sem leita skal að ásamt vectorunum 4 sem koma til með að geyma breyturnar
    void search(string query, vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);

private:
    string fixString(string before);
    bool addName(string name, vector<string>& names);
    bool addSex(string sex, vector<string>& sexes);
    bool addYears(int birthYear, int deathYear, vector<int>& birthYears, vector<int>& deathYears);

    void switchPerson(int index1, int index2, vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);

    void sortByNameAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
    void sortByNameDesending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
    void sortBySexF(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
    void sortbySexM(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
    void sortByBirthAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
    void sortByBirthDescending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
    void sortByDeathAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
    void sortByDeathDescending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);

};

#endif // SERVICE_H
