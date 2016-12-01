#include <iostream>
#include "Console.h"
//#include "database.h"
#include "console.h"
#include <string>
//#include "database.h"
using namespace std;

int main()
{

    /*//database data;

    char choice_made;
    //char stringChoiceMade;

    //database data;
    //string str;

    Console console;
    console.welcome();

    console.toContinue();
    //naudsyn ad yta a enter til ad fa naestu valmynd
    console.viewOrInsert();
    //her kemur valmynd um hvort vid viljum skoda lista eda setja inn i hann
    choice_made = console.choice();
    //her er gildid sem segir okkur hvad vid viljum gera med char
    //console.choiceMade();



    cout << choice_made; ///Bara svo að hann hætti að væla um að choice_made sé ekki notað

    //console.sorting(str);

    // TODO:

    //displayList();
    //addToList(); setjum vid tad her eda er tad komid inn sjalfkrafa? (1.3 endi)

    //cout << choice_made << endl;

    /// Passa að skrifa vector út í database í lok keyrslu*/

    Console screen;
    screen.run();

    return 0;
}

