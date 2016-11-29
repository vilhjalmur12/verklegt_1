#include <iostream>
#include "Console.h"
#include <string>
using namespace std;

int main()
{
    char choice_made;
    string str;

    Console console;
    console.welcome(); //spurning um ad yta a enter til ad fa naesta glugga?
    console.viewOrInsert(); //her kemur valmynd um hvort vid viljum skoda lista eda setja inn i hann
    choice_made = console.choice(); //her er gildid sem segir okkur hvad vid viljum gera med char
    console.choiceMade(choice_made);



    // TODO:
    //displayList();
    //addToList(); setjum vid tad her eda er tad komid inn sjalfkrafa? (1.3 endi)

    //cout << choice_made << endl;

    return 0;
}

