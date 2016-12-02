#include "database.h"
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

    dataInput.open("data.txt");
    if (dataInput.fail())
    {
        output.dataWriteError();
        exit(1);
    }
    if (isEmpty(dataInput))
    {
        tempName.push_back("Ada Lovelace");
        tempSex.push_back("Female");
        tempDOB.push_back(1933);
        tempDOD.push_back(2000);
        tempfInfo.push_back("First programmer");
    }
    else
    {
        int j = 0;
        string line;
        while (std::getline(dataInput, line)) {
            j++;
        }

        dataInput.clear();
        dataInput.seekg(0);


        for(int i = 0; i < j; i++)
        {
            dataInput >> name >> sex >> DOD >> DOB >> furtherInfo;

            name = decryptData(name);
            sex = decryptData(sex);
            furtherInfo = decryptData(furtherInfo); // Sandra baetti vid thessari linu

            tempName.push_back(name);
            tempSex.push_back(sex);
            tempDOB.push_back(DOB);
            tempDOD.push_back(DOD);
            tempfInfo.push_back(furtherInfo); // Sandra baetti vid
        }
    }
    
    dataInput.close();
}

bool database::isEmpty(ifstream& input)
{
    return input.peek() == std::ifstream::traits_type::eof();
}


/****************************************************************************
                writeData

 tekur inn upplýsingar frá gagnagrunni og hleður allar í vectora til að reiðubúa notkun
 ****************************************************************************/
void database::writeData ()
{
    string name, sex, furtherInfo;
    int DOB, DOD;

    ofstream dataOutput;
    dataOutput.open("data.txt");
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

/****************************************************************************
                        pushData - pullData
    Sér um að geta matað þau föll sem vilja sækja í gagnagrunninn.
 ****************************************************************************/
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

/******************************************************************
                    Encryptions
    Auðveldur ceaser cypher sem encryptar í decryptar data fileana
 ******************************************************************/

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

/******************************************************************
                        Notenda gagnagrunnur
    Heldur utan um og hjálpar að kalla í notendur
 ******************************************************************/

bool database::getUser (string username, string password)
{
    vector<string> allUsers;
    vector<string> allPasswords;

    ifstream userData;
    userData.open("users.txt");
    if (userData.fail())
    {
        fstream newUserData ("users.txt", std::ios::out);
        newUserData.close();
        userData.open("users.txt");
    }

    int j = 0;
    string line;
    while (std::getline(userData, line))
    {
        j++;
    }

    userData.clear();
    userData.seekg(0);

    string encUser, encPass;
    for (int i = 0; i < j; i++)
    {
        userData >> _username >> _password;
        encUser = decryptData(_username);
        encPass = decryptData(_password);
        allUsers.push_back(encUser);
        allPasswords.push_back(encPass);
    }

    if(userCorrect(username, password, allUsers, allPasswords))
    {
        return true;
    }

    return false;
}

void database::createUser (string user, string password)
{
    ofstream userData;
    userData.open("users.txt", std::ios::app);
    if (userData.fail())
    {
        fstream newUserData ("users.txt", std::ios::out);
        newUserData.close();
        userData.open("users.txt");
    }

    string encUser, encPass;

    encUser = encryptData(user);
    encPass = encryptData(password);

    userData << encUser << "\t" << encPass << endl;

    userData.close();

}

/****************************************************************************
                        TEST FÖLL
 Þessi föll hjálpa okkur að prufa og prenta vectora. Við eyðum eða færum þessi
 föll út úr klasanum fyrir skil.
 ****************************************************************************/

bool database::userCorrect (string username, string password, vector<string> allUsers, vector<string> allPasswords)
{
    string tmpUser, tmpPassword;
    for (unsigned int i = 0; i < allUsers.size(); i++)
    {
        tmpUser = allUsers[i];
        tmpPassword = allPasswords[i];

        if (tmpUser == username && tmpPassword == password)
        {
            return true;
        }
    }
    return false;
}

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
    string name, sex, furtherInfo;
    int DOD, DOB;
    Scientist tmp;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        tmp = allScientists[i];
        name = tmp.getName();
        sex = tmp.getSex();
        DOB = tmp.getYearOfBirth();
        DOD = tmp.getYearOfDeath();
        furtherInfo = tmp.getFurtherInfo();

        cout << name << "\t" << sex << "\t" << DOB << "\t" << DOD << "\t" << furtherInfo << endl;
    }
}

void database::printSearch (int id)
{
    cout << "fannst eftirfarandi: \n";
    cout << tempName[id] << "\t" << tempSex[id] << "\t" << tempDOB[id] << "\t" << tempDOD[id] << "\t" << tempfInfo[id] << endl;

}

/*****************************************************************************/
