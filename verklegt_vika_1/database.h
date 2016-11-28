#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class database
{
private:
    vector<string> tempName;
    vector<string> tempSex;
    vector<int> tempDOB;
    vector<int> tempDOD;

public:
    void getData ();
    void writeData ();

    // tvö prufuföll
    void testData ();
    void dataPrint ();

};

#endif // DATABASE_H
