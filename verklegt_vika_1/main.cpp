#include <iostream>
#include "Console.h"

using namespace std;

int main()
{
    char choice_made;

    Console console;
    console.welcome();
    console.viewOrInsert();
    console.choice();
    console.choiceMade(choice_made);
    //console.displayFræðinga();

    return 0;
}
