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

    //Keyrsluföll
    void run();
    void edit();
    void search();
    void viewDisplay(); //Notandi sendur i sorting_menu
    char continueFunction(); //Spyr hvort eigi að endurtaka aðgerð og geymir valið y/n
    void quit();

    //Opnunarföll
    void welcome(); //Bjóða notanda velkominn
    void toContinue(); //Notandi þarf að ýta á ENTER til að halda áfram

    //Valmyndarföll
    void viewOrInsert(); //Birta aðal valmynd
    char choice(); //Geyma valmöguleika
    void choiceMade(); //Kalla á framkvæmd eftir vali notanda
    void printChangeDelete(); //Bjóða uppá að eiga við lista


    //Sorting föll
    void sorting_menu(); //Birta valmynd yfir möguleika til að raða lista
    string stringChoice(); //Geyma val notanda yfir hvernig hann vildi raða listanum
    void sorting(string str); //Birta raðaðann lista

private:
    //Meðlimabreytur
    Service scientistService;
    ErrorHandling throwError;

    //Hjálparföll við edit
    int findIndexToEdit(string oldName);
    void printInsertMenu();
    void pushBackScientist();

    //Hjálparföll við search
    void printSearchMenu();
    void changeOrDelete();

    void printTable(); // prentar út töflu með öllum scientists í núverandi röð
    void printTable(vector<int> indexesToPrint);


};

#endif // CONSOLE_H
