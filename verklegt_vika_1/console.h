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
        void sorting_menu();
        string stringChoice();

    protected:
    private:
};

#endif // CONSOLE_H
