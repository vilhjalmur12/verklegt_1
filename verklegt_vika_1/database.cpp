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
 fall sem sækir allar niðurstöður úr gagnagrunni og skilar þeim í vectora svo
 við höfum þá til notkunar allann tíman sem við erum að vinna í forritinu.
 ****************************************************************************/

void database::getData (string user)
{
    string name, sex, furtherInfo, fullUser;
    int DOB, DOD;

    ifstream dataInput;
    fullUser = "." + user +"_profile.dat";

    dataInput.open(fullUser);
    if (dataInput.fail())
    {
        fstream newDataInput (fullUser, std::ios::out);
        newDataInput.close();
        dataInput.open(fullUser);
    }
    if (isEmpty(dataInput))
    {
        tempName.push_back("Ada Lovelace");
        tempSex.push_back("Female");
        tempDOB.push_back(1815);
        tempDOD.push_back(1852);
        tempfInfo.push_back("First programmer");
        tempName.push_back("Charles Babbage");
        tempSex.push_back("Male");
        tempDOB.push_back(1791);
        tempDOD.push_back(1871);
        tempfInfo.push_back("The father of computing");
        tempName.push_back("Blaise Pascal");
        tempSex.push_back("Male");
        tempDOB.push_back(1623);
        tempDOD.push_back(1662);
        tempfInfo.push_back("Pascal language named after him");
        tempName.push_back("Gottfried Wilhelm Leibniz");
        tempSex.push_back("Male");
        tempDOB.push_back(1646);
        tempDOD.push_back(1716);
        tempfInfo.push_back("Mechanical multiplier");
        tempName.push_back("Alan Turing");
        tempSex.push_back("Male");
        tempDOB.push_back(1912);
        tempDOD.push_back(1954);
        tempfInfo.push_back("Father of theoretical computer science");
        tempName.push_back("Tim Berners-Lee");
        tempSex.push_back("Male");
        tempDOB.push_back(1955);
        tempDOD.push_back(2016);
        tempfInfo.push_back("Inventor of the World Wide Web");
        tempName.push_back("George Boole");
        tempSex.push_back("Male");
        tempDOB.push_back(1815);
        tempDOD.push_back(1864);
        tempfInfo.push_back("Boolean algebra");
        tempName.push_back("Edsger Dijkstra");
        tempSex.push_back("Male");
        tempDOB.push_back(1930);
        tempDOD.push_back(2002);
        tempfInfo.push_back("Dijkstra's algorithm");
        tempName.push_back("Grace Hopper");
        tempSex.push_back("Female");
        tempDOB.push_back(1906);
        tempDOD.push_back(1992);
        tempfInfo.push_back("First compiler");
        tempName.push_back("Margaret Hamilton");
        tempSex.push_back("Female");
        tempDOB.push_back(1936);
        tempDOD.push_back(2016);
        tempfInfo.push_back("Apollo mission");

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
void database::writeData (string username)
{
    string name, sex, furtherInfo;
    int DOB, DOD;

    string fullUser = "." + username + "_profile.dat";

    ofstream dataOutput;
    dataOutput.open(fullUser);
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
    Auðveldur ceaser cypher sem dulkóðar og afkóðar data skrárnar
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
              Heldur utan um og hjálpar að kalla í notendur.
 ******************************************************************/

bool database::getUser (string username, string password)
{
    vector<string> allUsers;
    vector<string> allPasswords;

    ifstream userData;
    userData.open("users.dat");
    if (userData.fail())
    {
        fstream newUserData ("users.dat", std::ios::out);
        newUserData.close();
        userData.open("users.dat");
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
    userData.open("users.dat", std::ios::app);
    if (userData.fail())
    {
        fstream newUserData ("users.dat", std::ios::out);
        newUserData.close();
        userData.open("users.dat");
    }

    string encUser, encPass;

    encUser = encryptData(user);
    encPass = encryptData(password);

    userData << encUser << "\t" << encPass << endl;

    userData.close();

}

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
