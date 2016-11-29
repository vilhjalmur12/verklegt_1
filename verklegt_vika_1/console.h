#ifndef CONSOLE_H
#define CONSOLE_H

using namespace std;
#include <string>

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
<<<<<<< HEAD

        void toContinue(); //press enter to continue
    
        void dataWriteError ();  // villi: error output fyrir database
        void run();

=======
        void toContinue(); //press enter to continue
        void dataWriteError ();  // villi: error output fyrir database
>>>>>>> 482b0b6f00c039ad6d51b8d3c2bf9c79cfdf5d78

    protected:
    private:
};

#endif // CONSOLE_H
