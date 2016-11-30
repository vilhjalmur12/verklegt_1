#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

using namespace std;

class Console
{
public:
    Console();
    virtual ~Console();

    void welcome(); //print out welcome note
    void viewOrInsert(); //print out choice menu for viewing or inserting
    char choice(); //make choice
    void choiceMade(char choice_made);
    void sorting_menu(); //print out the sorting menu
    string stringChoice(); //here you choose what kind of sorting you want to do
    void viewDisplay(); //prints out the list and sorting
    void toContinue(); //press enter to continue
    void sorting(string str);

    //void dataWriteError ();  // villi: error output fyrir database
    //string str = stringChoice();

    void dataWriteError ();  // villi: error output fyrir database
    void dataSearchNotFound ();

protected:
private:




};

#endif // CONSOLE_H
