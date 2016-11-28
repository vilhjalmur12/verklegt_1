#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <vector>

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
    /* ------------------Optional foll fyrir add person fallid--------------------------

    void addName(string name, vector<string>& names);
    void addSex(string sex, vector<string>& sexes);
    void addBirthYear(int birthYear, vector<int>& birthYears);
    void addDeathYear(int deathYear, vector<int>& deathYears, int birthYear);

    */


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
