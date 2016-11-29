#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

using namespace std;

class Console
{
<<<<<<< HEAD
=======

>>>>>>> 8eb49a226c863944fa7e43ad728431a20c4a5291
public:
    Console();
    virtual ~Console();
    void welcome(); //print out welcome note
    void viewOrInsert(); //print out choice menu for viewing or inserting
    char choice(); //make choice
    void choiceMade(char choice_made); //choose view or insert
    void sorting_menu(); //print out the sorting menu
    string stringChoice(); //here you choose what kind of sorting you want to do
    void viewDisplay(); //prints out the list and sorting
    void toContinue(); //press enter to continue
    void sorting(string str); //here we print out the list how they want it to be sorted like

    //string str = stringChoice();

    void dataWriteError ();  // villi: error output fyrir database
    void dataSearchNotFound ();


private:

<<<<<<< HEAD
=======

>>>>>>> 8eb49a226c863944fa7e43ad728431a20c4a5291
};

#endif // CONSOLE_H
