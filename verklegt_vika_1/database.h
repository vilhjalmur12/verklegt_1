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

    /***************************************
                 Leitarföll
    ****************************************/
    int dataSearch (string tmp);
    int dataSearch (int tmp);
    vector<int> dataSearch(string tmp,vector<Scientist> allScientist);

    /***************************************
                 Gagnagrunnsföll
    ****************************************/
    void getData (string user);             //sækir gagnagrunn í eigu notanda í vinnslu
    void writeData (string username);       //skrifar gagnagrunn á skrá frá notanda í vinnslu
    vector<Scientist> pullData ();      //skilar öllum upplýsingum frá meðlimabreytum database klasanns ef kallað sé í fallið
    void pushData (vector<Scientist> write);        //ýtir breyttum upplýsingum í gagnagrunni yfir í meðlimabreytur klasanns database
    bool getUser (string username, string password);        //sækir upplýsingar um alla skráða notendur og athugar hvort notandi og aðgangsorð sé tiltækt
    void createUser (string user, string password);     //býr til nýjan notanda með aðgangsorð í gagnagrunn og býr til gagnagrunn fyrir notandann

private:
    /***************************************
                 Meðlimabreytur
    ****************************************/
    vector<string> tempName;
    vector<string> tempSex;
    vector<int> tempDOB;
    vector<int> tempDOD;
    vector<string> tempNation;
    vector<string> tempfInfo;
    string _username;
    string _password;

    /***************************************
                 Meðlimaföll
    ****************************************/
    string encryptData (string n);      // tekur inn venjulegan streng og skilar strengnum kóðuðum
    string decryptData (string n);      // tekur inn kóðaðan streng og skilar honum afkóðuðum
    bool isEmpty (ifstream& input);     // athugar hvort skrá sé tóm
    bool userCorrect (string username, string password, vector<string> allUsers, vector<string> allPasswords);      // ber saman notanda og lykilorð

    ErrorHandling output;

};

#endif // DATABASE_H
