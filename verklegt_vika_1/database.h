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
    vector<string> tempfInfo;
    string _username;
    string _password;
    ErrorHandling output;

    /***************************************
                 Meðlimaföll
    ****************************************/
    string encryptData (string n);      //dulkóðun: tekur orð og dulkóðar það með ceaser script
    string decryptData (string n);      //afkóðun: tekur orð og afkóðar það í öfugri ceasar script
    bool isEmpty (ifstream& input);     //skoðar hvort ákveðin skrá sé tóm eða ekki
    bool userCorrect (string username, string password, vector<string> allUsers, vector<string> allPasswords);      //athugar hvort notendanafn og leyniorð passa
};

#endif // DATABASE_H
