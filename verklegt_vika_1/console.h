#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>

using namespace std;

class Console
{
<<<<<<< HEAD
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

    //string str = stringChoice();

    //void dataWriteError ();  // villi: error output fyrir database


protected:
private:
=======
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
    
        void dataWriteError ();  // villi: error output fyrir database
        void dataSearchNotFound ();
        void run();


    


    protected:
    private:
>>>>>>> 5e0ed330bddd229a3c616b4d3d6f8c208f8a4a68
};

#endif // CONSOLE_H
