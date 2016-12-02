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
    //Notandi sendur i sorting_menu
    void viewDisplay();
    //Spyr hvort eigi að endurtaka aðgerð og geymir valið y/n
    char continueFunction();
    void quit();
    void callUser ();

/**************************************************
                    Opnunarföll
**************************************************/
    void welcome();
    //Notandi þarf að ýta á ENTER til að halda áfram
    void toContinue();

/**************************************************
                   Valmyndarföll
**************************************************/
    //Birta aðal valmynd
    void viewOrInsert();
    //Geyma valmöguleika
    char choice();
    //Kalla á framkvæmd eftir vali notanda
    void choiceMade();
    //Bjóða uppá að eiga við lista
    void printChangeDelete();
    void quitMenu();

/**************************************************
                   Sorting föll
**************************************************/
    //Birta valmynd yfir möguleika til að raða lista
    void sorting_menu();
    //Geyma val notanda yfir hvernig hann vildi raða listanum
    string stringChoice();
    //Birta raðaðann lista
    void sorting(string str);

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
    void createScientist(string& name, string& sex, int& YOB, int& YOD, string& furtherInfo);
    void readName(string& name);
    void readSex(string& sex);
    void readFurtherInfo(string& furtherInfo);
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
