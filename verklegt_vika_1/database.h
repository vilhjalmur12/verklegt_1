#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include "console.h"
#include "scientist.h"
#include <fstream>

using namespace std;

class database
{
private:
    vector<string> tempName;
    vector<string> tempSex;
    vector<int> tempDOB;
    vector<int> tempDOD;
    
    void encryptData (string &n);
    void encryptData (int &n);
    void decryptData (string &n);
    void decryptData (int &n);
    
    Console output;

public:
    database ();
    ~database ();
    void getData ();
    void writeData ();
    int dataSearch (string tmp);
    int dataSearch (int tmp);
    void pushData (vector<string> name, vector<string> gender, vector<int> DOB, vector<int> DOD);
    void pullData (vector<string> &name, vector<string> &gender, vector<int> &DOB, vector<int> &DOD);
    vector<Scientist> pullData ();


    // tvö prufuföll - við skulum sjá til þess að færa þessi út úr klasanum fyrir skil
    void testData ();
    void dataPrint ();
    void printSearch (int id);

};

#endif // DATABASE_H
