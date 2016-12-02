#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "errorhandling.h"
#include "scientist.h"
#include <fstream>

using namespace std;

class database
{
public:
    database ();
    ~database ();
    int dataSearch (string tmp);
    int dataSearch (int tmp);
    void getData ();
    void writeData ();
    void pushData (vector<Scientist> write);
    vector<Scientist> pullData ();
    vector<int> dataSearch(string tmp,vector<Scientist> allScientist);
    void getUser ();

    // tvö prufuföll - við skulum sjá til þess að færa þessi út úr klasanum fyrir skil
    void testData (vector<Scientist> &allScientists);
    void dataPrint (vector<Scientist> const allScientists);
    void printSearch (int id);

private:
    vector<string> tempName;
    vector<string> tempSex;
    vector<int> tempDOB;
    vector<int> tempDOD;
    vector<string> tempfInfo;
    string username;
    string password;

    string encryptData (string n);
    string decryptData (string n);
    bool isEmpty (ifstream& input);

    ErrorHandling output;

};

#endif // DATABASE_H
