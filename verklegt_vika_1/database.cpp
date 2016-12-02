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
    Sækir allar upplýsingar frá gagnagrunnskrá notanda og geymir þær. Ef notandi á ekki
    skrá þá býr það til nýja skrá og stillir 10 hluti á listann fyrir hann.
            @parameter(string user) - notendanafn notanda að forriti
 ****************************************************************************/

void database::getData (string user)
{
    string name, sex, nationality, furtherInfo, fullUser;
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
        tempNation.push_back("English");
        tempfInfo.push_back("First programmer");

        tempName.push_back("Alan Turing");
        tempSex.push_back("Male");
        tempDOB.push_back(1912);
        tempDOD.push_back(1954);
        tempNation.push_back("English");
        tempfInfo.push_back("Father of theoretical computer science");

        tempName.push_back("Blaise Pascal");
        tempSex.push_back("Male");
        tempDOB.push_back(1623);
        tempDOD.push_back(1662);
        tempNation.push_back("French");
        tempfInfo.push_back("Pascal language named after him");

        tempName.push_back("Charles Babbage");
        tempSex.push_back("Male");
        tempDOB.push_back(1791);
        tempDOD.push_back(1871);
        tempNation.push_back("English");
        tempfInfo.push_back("The father of computing");

        tempName.push_back("Edsger Dijkstra");
        tempSex.push_back("Male");
        tempDOB.push_back(1930);
        tempDOD.push_back(2002);
        tempNation.push_back("Dutch");
        tempfInfo.push_back("Dijkstra's algorithm");

        tempName.push_back("George Boole");
        tempSex.push_back("Male");
        tempDOB.push_back(1815);
        tempDOD.push_back(1864);
        tempNation.push_back("English");
        tempfInfo.push_back("Boolean algebra");

        tempName.push_back("Gottfried Wilhelm Leibniz");
        tempSex.push_back("Male");
        tempDOB.push_back(1646);
        tempDOD.push_back(1716);
        tempNation.push_back("German");
        tempfInfo.push_back("Mechanical multiplier");

        tempName.push_back("Grace Hopper");
        tempSex.push_back("Female");
        tempDOB.push_back(1906);
        tempDOD.push_back(1992);
        tempNation.push_back("American");
        tempfInfo.push_back("First compiler");

        tempName.push_back("Margaret Hamilton");
        tempSex.push_back("Female");
        tempDOB.push_back(1936);
        tempDOD.push_back(200000000);
        tempNation.push_back("American");
        tempfInfo.push_back("Apollo mission");

        tempName.push_back("Tim Berners-Lee");
        tempSex.push_back("Male");
        tempDOB.push_back(1955);
        tempDOD.push_back(200000000);
        tempNation.push_back("English");
        tempfInfo.push_back("Inventor of the World Wide Web");

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
            dataInput >> name >> sex >> DOD >> DOB >> nationality >> furtherInfo;

            name = decryptData(name);
            sex = decryptData(sex);
            nationality = decryptData(nationality);
            furtherInfo = decryptData(furtherInfo);

            tempName.push_back(name);
            tempSex.push_back(sex);
            tempDOB.push_back(DOB);
            tempDOD.push_back(DOD);
            tempNation.push_back(nationality);
            tempfInfo.push_back(furtherInfo);
        }
    }
    
    dataInput.close();
}

/****************************************************************************
                        isEmpty
    Lítur á skrá í gagnagrunni og segjir til um hvort hún sé tóm eða ekki
            @parameter(ifstream& input) - tekur inn skrár streymi notanda
            @return(true) - skilar satt ef hún sé tóm
            @return(false) - skilar ósatt ef hún sé EKKI tóm
 ****************************************************************************/

bool database::isEmpty(ifstream& input)
{
    return input.peek() == std::ifstream::traits_type::eof();
}


/****************************************************************************
                        writeData
    Skilar aftur öllum upplýsingum af forriti yfir á gagnagrunn skránna hjá notanda
            @parameter(string username) - notendanafn notanda að forriti
 ****************************************************************************/
void database::writeData (string username)
{
    string name, sex, nationality, furtherInfo;
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
        nationality = tempNation[i];
        nationality = encryptData(nationality);
        furtherInfo = tempfInfo[i];
        furtherInfo = encryptData(furtherInfo);

        dataOutput << name << "\t" << sex << "\t" << DOD << "\t" << DOB << "\t" << "\t" << nationality << "\t" << furtherInfo << endl;
    }

    dataOutput.close();
}

/****************************************************************************
                        dataSearch
    Leitarvél sem tekur inn streng sem leitað er í nafna vector og skilar
    út í hvaða staki hann var. Hægt að nota tölu sem identifier í hina vectora.
            @parameter(string tmp) - tekur inn streng og leitar í gagnagrunni
            @parameter(int tmp) - tekur inn tölu og leitar í gagnagrunni
            @return(int id) - skilar af sér tölu sem segjir til um í hvaða staki upplýsingarnar eru
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

/******************************************************************
                     pushData
    Fær til sín lista af vísindamönnum með upplýsingar fyrir hvern og einn
    og sendir þær aftur í gagnagrunninn fyrir notandann.
            @parameter(vector<Scientist> write) - vector (listi) af vísindamönnum
 ******************************************************************/
void database::pushData (vector<Scientist> write)
{
    Scientist tmp;
    tempName.clear();
    tempSex.clear();
    tempDOD.clear();
    tempDOB.clear();
    tempNation.clear();
    tempfInfo.clear();
    
    for (unsigned int i = 0; i < write.size(); i++)
    {
        tmp = write[i];
        tempName.push_back(tmp.getName());
        tempSex.push_back(tmp.getSex());
        tempDOB.push_back(tmp.getYearOfBirth());
        tempDOD.push_back(tmp.getYearOfDeath());
        tempNation.push_back(tmp.getNationality());
        tempfInfo.push_back(tmp.getFurtherInfo());
    }
}

/******************************************************************
                     pullData
    Sækir allar upplýsingar úr meðlimabreytum og skilar af sér öllum
    upplýsingum í einum vector (lista)
            @return(vector<Scientist> A) - vector (listi) af klasanum
            scientist með öllum upplýsingum um hvern scientist.
 ******************************************************************/

vector<Scientist> database::pullData ()
{
    vector<Scientist> A;
    Scientist tmp;
    string name, gender, nationality, furtherInfo;
    int DOB, DOD;
    
    for (unsigned int i = 0; i < tempName.size(); i++)
    {
        name = tempName[i];
        gender = tempSex[i];
        DOB = tempDOB[i];
        DOD = tempDOD[i];
        nationality = tempNation[i];
        furtherInfo = tempfInfo[i];

        
        tmp.pushScientist(name, gender, DOB, DOD, nationality, furtherInfo);
        
        A.push_back(tmp);
        
    }
    return A;
}

/******************************************************************
                     encryptData
    Auðveldur ceaser cypher sem dulkóðar streng
            @parameter(string n) - venjulegur strengur
            @return(string n) - dulkóðaður strengur
 ******************************************************************/

string database::encryptData (string n)
{
    for(unsigned int u=0; u < n.size(); u++){
        n[u]--;
    }
    return n;
}

/******************************************************************
                      decryptData
    Auðveldur ceaser cypher sem afkóðar streng
            @parameter(string n) - dulkóðaður strengur
            @return(string n) - afkóðaður strengur
 ******************************************************************/

string database::decryptData (string n)
{
    for(unsigned int u=0; u < n.size(); u++){
        n[u]++;
    }
    return n;
}

/******************************************************************
                            getUser
    Sækir gagnagrunnsskrá og les af henni upplýsingar um notendur,
    ef engin skrá er til um notendur þá býr hún til nýja. Ef notandi
    hafði slegjið inn vitlaust eða hann finnst ekki þá keyrir hann út false
            @parameter(string username) - notendanafn sem notandi sló inn í forritið
            @parameter(string password) - lykilorð sem notandi sló inní forritið
            @return(true) - verður satt ef notandi og lykilorð eru til
            @return(false) - verður ósatt ef ekki er til notandi og lykilorð
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

/******************************************************************
                      createUser
    Býr til nýjan notanda og skráir hann í gagnagrunn fyrir notendur.
            @parameter(string username) - notendanafn sem notandi sló inn í forritið
            @parameter(string password) - lykilorð sem notandi sló inní forritið
 ******************************************************************/

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

/******************************************************************
                      userCorrect
    Skoðar safn allra notanda, finnur notendanafn ef það sé til og
    ber það saman við lykilorð. Skilar satt ef þau stemma.
            @parameter(string username) - notendanafn sem notandi sló inn í forritið
            @parameter(string password) - lykilorð sem notandi sló inní forritið
            @parameter(vector<string allUsers) - allir notendur að forriti
            @parameter(vector<string allPasswords) - öll lykilorð að forriti
            @return(true) - skilar satt ef notendanafn í sama staki og lykilorð stemma
            @return(false) - skilar ósatt ef notendanafn í sama staki og lykilorð stemma EKKI

 ******************************************************************/

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

