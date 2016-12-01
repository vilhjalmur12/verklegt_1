#include "database.h"
#include "console.h"
#include <iostream>
#include "scientist.h"
#include <vector>
#include <fstream>

using namespace std;

database::database () {}

database::~database () {}

/****************************************************************************
                getData

 fall sem sækir allar niðurstöður úr gagnagrunni og skilar þeim í vectora svo við höfum þá til notkunar allann
 tíman sem við erum að vinna í forritinu.
 ****************************************************************************/

void database::getData ()
{
    string name, sex, furtherInfo;
    int DOB, DOD;
    

    ifstream dataInput;

    dataInput.open("verklegt_1/verklegt_vika_1/data.db");
    if (dataInput.fail())
    {
        output.dataWriteError();
        exit(1);
    }
    if (isEmpty(dataInput))
    {
        tempName.push_back("name");
        tempSex.push_back("gender");
        tempDOB.push_back(0);
        tempDOD.push_back(0);
        tempfInfo.push_back("info");
    }
        for (unsigned int i = 0; i < tempName.size(); i++)
        {
            dataInput >> name >> sex >> DOB >> DOD >> furtherInfo;
        
               name = decryptData(name);
               sex = decryptData(sex);
              furtherInfo = decryptData(furtherInfo); // Sandra baetti vid thessari linu

            tempName.push_back(name);
            tempSex.push_back(sex);
            tempDOB.push_back(DOB);
            tempDOD.push_back(DOD);
            tempfInfo.push_back(furtherInfo); // Sandra baetti vid
        }
    
    dataInput.close();
}

bool database::isEmpty(ifstream& input)
{
    return input.peek() == std::ifstream::traits_type::eof();
}


/****************************************************************************
                writeData

 tekur inn upplýsingar frá gagnagrunni og hleður allar í vectoar til að reiðubúa notkun
 ****************************************************************************/
void database::writeData ()
{
    string name, sex, furtherInfo;
    int DOB, DOD;

    ofstream dataOutput;
    dataOutput.open("verklegt_1/verklegt_vika_1/data.db");
    if (dataOutput.fail())
    {
        output.dataWriteError();
        exit(1);
    }
    
    for (unsigned int i = 0; i < tempName.size(); i++)
    {
        name = tempName[i];
        name = encryptData(name);
        sex = tempSex[i];
        sex = encryptData(sex);
        DOB = tempDOB[i];
        DOD = tempDOD[i];
        furtherInfo = tempfInfo[i]; // Sandra baetti vid
        furtherInfo = encryptData(furtherInfo); // Sandra baetti vid

        dataOutput << name << "\t" << sex << "\t" << DOD << "\t" << DOB << "\t" << furtherInfo << endl;
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


    for (unsigned int i = 0; i < tempName.size(); i++)
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

    for (unsigned int i = 0; i < tempName.size(); i++)
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
void database::testData (vector<Scientist> &allScientists)
{
    char cont;
    string name, sex, furtherInfo;
    int DOB, DOD;
    Scientist tmp;

    do
    {
        cout << "Add name: ";
        cin >> name;
        cout << "Sex: ";
        cin >> sex;
        cout << "Date of birth: ";
        cin >> DOB;
        cout << "Date of death: ";
        cin >> DOD;
        cout << "Further information: "; // Lina by Sandra
        cin >> furtherInfo;

        tmp.pushScientist(name, sex, DOB, DOD, furtherInfo);
        allScientists.push_back(tmp);
        
        cout << "Continue?\t (y = yes, n = no)" << endl << "->";
        cin >> cont;
        
   //     tempName.push_back(name);
   //     tempSex.push_back(sex);
   //     tempDOB.push_back(DOB);
   //     tempDOD.push_back(DOD);
   //     tempfInfo.push_back(furtherInfo); // Lina by Sandra
        
        cout << endl;
        
    }while (cont != 'n');
}

void database::dataPrint (vector<Scientist> const allScientists)
{
    cout << "You selected\n";
    string name, sex, further;
    int DOD, DOB;
    Scientist tmp;
    
    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        tmp = allScientists[i];
        name = tmp.getName();
        sex = tmp.getSex();
        DOB = tmp.getYearOfBirth();
        DOD = tmp.getYearOfDeath();
        further = tmp.getFurtherInfo();
        
        cout << name << "\t" << sex << "\t" << DOB << "\t" << DOD << "\t" << further << endl;
    }
}

void database::printSearch (int id)
{
    cout << "fannst eftirfarandi: \n";
    cout << tempName[id] << "\t" << tempSex[id] << "\t" << tempDOB[id] << "\t" << tempDOD[id] << endl;

}
/*****************************************************************************/


void database::pushData (vector<Scientist> write)
{
    Scientist tmp;
    tempName.clear();
    tempSex.clear();
    tempDOD.clear();
    tempDOB.clear();
    tempfInfo.clear();
    
    for (unsigned int i = 0; i < write.size(); i++)
    {
        tmp = write[i];
        tempName.push_back(tmp.getName());
        tempSex.push_back(tmp.getSex());
        tempDOB.push_back(tmp.getYearOfBirth());
        tempDOD.push_back(tmp.getYearOfDeath());
        tempfInfo.push_back(tmp.getFurtherInfo());
    }
}

vector<Scientist> database::pullData ()
{
    vector<Scientist> A;
    Scientist tmp;
    string name, gender, furtherInfo;
    int DOB, DOD;
    
    for (unsigned int i = 0; i < tempName.size(); i++)
    {
        name = tempName[i];
        gender = tempSex[i];
        DOB = tempDOB[i];
        DOD = tempDOD[i];
        furtherInfo = tempfInfo[i]; // Lina by Sandra
        
        tmp.pushScientist(name, gender, DOB, DOD, furtherInfo);
        
        A.push_back(tmp);
        
    }
    return A;
}

/*************************************************************
                    Encryptions
 
 *************************************************************/

    // ceasar cypher

string database::encryptData (string n)
{
    for(unsigned int u=0; u < n.size(); u++){
        n[u]--;
    }
    return n;
}


string database::decryptData (string n)
{
    for(unsigned int u=0; u < n.size(); u++){
        n[u]++;
    }
    return n;
}



        // XOR encryptions
/*
void database::encryptData (string &n)
{
    char encryptionKey = 'x';
    for (unsigned int i = 0; i < n.size(); i++)
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
    for (unsigned int i = 0; i < n.size(); i++)
    n[i] ^= decryptionKey;
}

void database::decryptData (int &n)
{
    char decryptionKey = 'x';
        n ^= decryptionKey;
}
 */

/************************************************************/

