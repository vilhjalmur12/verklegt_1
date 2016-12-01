#ifndef CONSOLE_H
#define CONSOLE_H
#include "scientist.h"
#include "service.h"
#include "errorhandling.h"
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
    void viewDisplay(); // prints out the list and sorting
    char continueFunction(); // spyr hvort þú viljir endurtaka aðferð y/n
    void quit();

    //Opnunarföll
    void welcome(); // print out welcome note
    void toContinue(); // press enter to continue

    //Valmyndarföll
    void viewOrInsert(); // print out main menu
    char choice(); // make choice to insert, view or more
    void choiceMade(); // choose view or insert
    void changeDelete(); //change/delete menu

    //Sorting föll
    void sorting_menu(); // print out the sorting menu
    string stringChoice(); // here you choose what kind of sorting you want to do
    void sorting(string str); // here we print out the list how they want it to be sorted like



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

    void printTable(); // prentar út töflu með öllum scientists í núverandi röð
    void printTable(vector<int> indexesToPrint);


};

#endif // CONSOLE_H
