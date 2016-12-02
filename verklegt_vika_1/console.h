#ifndef CONSOLE_H
#define CONSOLE_H

#include "errorhandling.h"
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
    Service scientistService;
    ErrorHandling throwError;

/**************************************************
               Hjálparföll við edit
**************************************************/
    int findIndexToEdit(string oldName);
    void printInsertMenu();
    void pushBackScientist();

/**************************************************
              Hjálparföll við search
**************************************************/
    void printSearchMenu();
    void changeOrDelete();

/**************************************************
                 Birta töflu
**************************************************/
    void printTable();
    void printTable(vector<int> indexesToPrint);


};

#endif // CONSOLE_H
