#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
using namespace std;


class Console
{
public:
    Console();
    virtual ~Console();
    void welcome(); //print out welcome note
    void viewOrInsert(); //print out choice menu for viewing or inserting
    //char choice(char x);
    //void displayFræðinga();
private:
};

#endif // CONSOLE_HPP

