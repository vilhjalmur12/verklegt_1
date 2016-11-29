#include "database.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

database::database () {}

/****************************************************************************
                getData

 fall sem sækir allar niðurstöður úr gagnagrunni og skilar þeim í vectora svo við höfum þá til notkunnar allann
 tíman sem við erum að vinna í forritinu.
 ****************************************************************************/
void database::getData ()
{
    string name, sex;
    int DOB, DOD;

    ifstream dataInput;

    dataInput.open("data.db");
    if (dataInput.fail())
    {
        output.dataWriteError();
        exit(1);
    }

    for (int i = 0; i < 4; i++)
    {
        dataInput >> name >> sex >> DOB >> DOD;
        
        
        tempName.push_back(name);
        tempSex.push_back(sex);
        tempDOB.push_back(DOB);
        tempDOD.push_back(DOD);
    }

    dataInput.close();
}

/****************************************************************************
                writeData

 tekur inn upplýsingar frá gagnagrunni og hleður allar í vectoar til að reyðubúa notkun
 ****************************************************************************/
void database::writeData ()
{
    string name, sex;
    int DOB, DOD;

    ofstream dataOutput;
    dataOutput.open("data.db");
    if (dataOutput.fail())
    {
        output.dataWriteError();
        exit(1);
    }
    
    for (int i = 0; i < tempName.size(); i++)
    {
        name = tempName[i];
        sex = tempSex[i];
        DOB = tempDOB[i];
        DOD = tempDOD[i];

        dataOutput << name << "\t" << sex << "\t" << DOD << "\t" << DOB << endl;
    }

    dataOutput.close();
}

/****************************************************************************
                        dataSearch
    Leitarvél sem tekur inn streng sem leitað er í nafna vector og skilar
    út í hvaða staki hann var. Hægt að nota tölu sem identifier í hina vectora
 ****************************************************************************/
int database::dataSearch (string tmp)
{
    int id = 0;


    for (int i = 0; i < tempName.size(); i++)
    {
        if (tmp == tempName[i])
        {
            id = 0;
        }
    }
    return id;
}

int database::dataSearch (int tmp)
{
    int id = 100;

    for (int i = 0; i < tempName.size(); i++)
    {
        if (tmp == tempDOD[i] || tmp == tempDOB[i])
        {
            id = i;
        }
    }
    return id;
}

/*
int database::dataSearch()
{
    int id = -1;

    if (string::npos != temp.find_first_of("0123456789")) // Strengur af tölustöfum ?
    {
        int year = atoi(temp.c_str()); // String í int

        for (int i = 0; i < tempName.size(); i++)
        {
            if (year == tempDOD[i] || year == tempDOB[i])
            {
                id = i;
            }
        }
    }
    else
    {
        for (int i = 0; i < tempName.size(); i++)
        {
            if (temp == tempName[i])
            {
                id = i;
            }
        }
    }

    return id;
}
*/

/****************************************************************************
                        TEST FÖLL
 Þessi föll hjálpa okkur að prufa og prenta vectora. Við eyðum eða færum þessi
 föll út úr klasanum fyrir skil.
    testData
    dataPrint
 ****************************************************************************/
void database::testData ()
{
    char cont;
    string name, sex;
    int DOB, DOD;

    while (cont != 'n')
    {
        cout << "Add name: ";
        cin >> name;
        cout << "Sex: ";
        cin >> sex;
        cout << "Date of birth: ";
        cin >> DOB;
        cout << "Date of death: ";
        cin >> DOD;

        tempName.push_back(name);
        tempSex.push_back(sex);
        tempDOB.push_back(DOB);
        tempDOD.push_back(DOD);

        cout << "Continue?\t (y = yes, n = no)" << endl << "->";
        cin >> cont;
    }
}

void database::dataPrint ()
{
    cout << "You selected\n";
    for (int i = 0; i < tempName.size(); i++)
    {
        cout << tempName[i] << "\t" << tempSex[i] << "\t" << tempDOB[i] << "\t" << tempDOD[i] << endl;
    }
}

void database::printSearch (int id)
{
    cout << "fannst eftirfarandi: \n";
    cout << tempName[id] << "\t" << tempSex[id] << "\t" << tempDOB[id] << "\t" << tempDOD[id] << endl;

}


void database::pushData (vector<string> name, vector<string> gender, vector<int> DOB, vector<int> DOD)
{
    tempName.clear();
    tempSex.clear();
    tempDOD.clear();
    tempDOB.clear();

    tempName = name;
    tempSex = gender;
    tempDOB = DOB;
    tempDOD = DOD;
}

void database::pullData (vector<string> &name, vector<string> &gender, vector<int> &DOB, vector<int> &DOD)
{
    name = tempName;
    gender = tempSex;
    DOB = tempDOB;
    DOD = tempDOD;
}

/*************************************************************
                    Encryptions
 
 *************************************************************/

void database::encryptData (string &n)
{
    char encryptionKey = 'x';
    for (int i = 0; i < n.size(); i++)
    n[i] ^= encryptionKey;
}

void database::encryptData (int &n)
{
    char encryptionKey = 'x';
        n ^= encryptionKey;
}

void database::decryptData (string &n)
{
    char decryptionKey = 'x';
    for (int i = 0; i < n.size(); i++)
    n[i] ^= decryptionKey;
}

void database::decryptData (int &n)
{
    char decryptionKey = 'x';
        n ^= decryptionKey;
}



