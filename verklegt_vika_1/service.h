#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <vector>

using namespace std;

class Service
{
public:
    Service();

    void addName(string name, vector<string>& names);
    void addSex(string sex, vector<string>& sexes);
    void addBirthYear(int birthYear, vector<int>& birthYears);
    void addDeathYear(int deathYear, vector<int>& deathYears, int birthYear);

    void sort(string choice, vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);


private:
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
