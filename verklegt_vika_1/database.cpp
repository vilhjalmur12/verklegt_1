#include "database.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;



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
                        TEST FÖLL
 Þessi föll hjálpa okkur að prufa og prenta vectora
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
