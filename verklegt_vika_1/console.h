#ifndef CONSOLE_H
#define CONSOLE_H

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
        void sorting();
    protected:
    private:
};

#endif // CONSOLE_H
