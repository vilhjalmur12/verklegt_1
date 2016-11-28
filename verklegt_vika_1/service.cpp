#include "service.h"
#include <algorithm>

using namespace std;


Service::Service()
{

}
// Erum her med allan listann i mismunandi butum. Nofnin, kynid, o.s.frv...

void Service::sortByNameAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears)
{
    // Skoda betur hjemme
    for(int i = 0; i < names.size(); i++)
    {
        //if(tolower(names[i])<tolower(names[i+1]))
        //{

        //}
    }

}

//void Service::sortByNameDesending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);

void Service::sortBySexF(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears)
{
    for(int i = 0; i < names.size(); i++)
    {
        if(sexes[i] == "f" || sexes[i] == "F")
        {
            string tmp = sexes[i];
            sexes[i] = sexes[i + 1];
            sexes[i+1] = tmp;
        }
    }
}

//void Service::sortbySexM(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByBirthAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByBirthDescending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByDeathAscending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
//void Service::sortByDeathDescending(vector<string>& names, vector<string>& sexes, vector<int>& birthYears, vector<int>& deathYears);
