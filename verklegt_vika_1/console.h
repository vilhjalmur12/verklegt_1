#ifndef CONSOLE_H
#define CONSOLE_H

#include "scientist.h"
#include "service.h"

#include <vector>
#include <string>

using namespace std;

class Console
{
public:
    Console();
    virtual ~Console();
/**************************************************
                    Keyrsluföll
**************************************************/
    void run();
    void edit();
    void search();
    void viewDisplay();     //Notandi sendur i sorting_menu
    string continueFunction();      //Spyr hvort eigi að endurtaka aðgerð og geymir valið y/n
    void quit();
    void callUser ();

/**************************************************
                    Opnunarföll
**************************************************/
    void welcome();
    void toContinue();      //Notandi þarf að ýta á ENTER til að halda áfram

/**************************************************
                   Valmyndarföll
**************************************************/
    void viewOrInsert();        //Birta aðal valmynd
    void loginMenu();       //Login menu
    string choice();        //Geyma valmöguleika
    void choiceMade();      //Kalla á framkvæmd eftir vali notanda
    void printChangeDelete();       //Bjóða uppá að eiga við lista
    void quitMenu();

/**************************************************
                   Sorting föll
**************************************************/
    void sorting_menu();        //Birta valmynd yfir möguleika til að raða lista
    string stringChoice();      //Geyma val notanda yfir hvernig hann vildi raða listanum
    void sorting(string str);       //Birta raðaðann lista

private:
/**************************************************
                   Meðlimabreytur
**************************************************/
    ErrorHandling throwError;
    string user;
    Service scientistService;
/**************************************************
               Hjálparföll við edit
**************************************************/
    int findIndexToEdit(string oldName);
    void printPushBackMenu();
    void printEditMenu();

    void pushBackScientist();
    void createScientist(string& name, string& sex, int& YOB, int& YOD, string& nationality, string& furtherInfo);
    void readName(string& name);
    void readSex(string& sex);
    void readFurtherInfo(string& furtherInfo);
    void readNationality(string& nationality);
    void readYears(int& YOB, int& YOD);
    void readBirthYear(int& YOB, bool& cont);
    void readDeathYear(int& YOD, bool& cont);

/**************************************************
              Hjálparföll við search
**************************************************/
    void printSearchMenu();
    void changeOrDelete(vector<int> indexes);

/**************************************************
                 Birta töflu
**************************************************/
    void printTable();
    void printTable(vector<int> indexesToPrint);
};

#endif // CONSOLE_H
