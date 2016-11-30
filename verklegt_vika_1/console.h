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
    void welcome(); // print out welcome note
    void viewOrInsert(); // print out choice menu for viewing or inserting
    char choice(); // make choice to insert, view or more
    void choiceMade(); // choose view or insert
    void sorting_menu(); // print out the sorting menu
    string stringChoice(); // here you choose what kind of sorting you want to do
    void viewDisplay(); // prints out the list and sorting
    void toContinue(); // press enter to continue
    bool sorting(string str); // here we print out the list how they want it to be sorted like
    void run();
    char continueFunction(); // spyr hvort þú viljir endurtaka aðferð y/n
    void printTable(); // prentar út töflu með scientists
    void quit();


private:
    //Meðlimabreytur
    Service scientistService;

    //Hjálparföll við edit
    void edit();
    int findIndexToEdit(string oldName);
    void printInsertMenu();
    void pushBackScientist();

    //Hjálparföll við search
    void search();
    void printSearchMenu();

    void printTable(vector<int> indexesToPrint);


};

#endif // CONSOLE_H
