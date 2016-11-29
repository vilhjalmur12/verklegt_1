#include "console.h"

#include <iostream>
#include <string>
#include <limits>


Console::Console()
{
    //ctor
}

Console::~Console()
{
    //dtor
}

void Console::welcome()
{
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Welcome to Database          |" << endl;
    cout << "|        Press enter to continue        |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::toContinue()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void Console::viewOrInsert()
{
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|           Choose procedure:           |" << endl;
    cout << "|            v - for viewing            |" << endl;
    cout << "|           i - for insertion           |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

char Console::choice()
{
    char choice_made;
    cin >> choice_made;

    return choice_made;
}

string Console::stringChoice()
{
    string str;
    cin >> str;
    return str;
}

void Console::choiceMade(char choice_made)
{
    if (choice_made == 'v')
    {
        string str;
        viewDisplay();
        str = stringChoice();
        sorting(str);
    }

    else if (choice_made == 'i')
    {
        cout << "insert" << endl;;

        /*
         string name;
         char sex;
         int birthYear;
         int deathYear;
         cin >> name;
         cin >> sex;
         cin >> birthYear;
         cin >> deathYear;

         banna að sleppa nafni, kyni og fæðingarári en má sleppa dánarári (ekki allir dánir)?
         ekki leyfa fæðingarári að vera á eftir dánarári

         */
    }

    else
    {
        cout << "Please enter a valid *** " << endl;
    }
}


/*void Console::displayFræðinga()
 {
 vektor með fræðingur = sækjaFræðinga(); - frá service

 tékka hvernig hægt er að prenta út upplýsingar í töflu


 for (size_t i = 0; i < fallFræðinga.size(); i++)
 {
 cout << fallFræðinga[i].sækjaNafn() << endl;
 prenta líka út allt hitt?
 }



 }*/


void Console::sorting_menu()
{
    cout << "-----------------------------------------" << endl;
    cout << "| In what order would you like to view? |" << endl;
    cout << "|                                       |" << endl;
    cout << "|     Name, ascending: na               |" << endl;
    cout << "|     Name, descending: nd              |" << endl;
    cout << "|     Gender, female: gf                |" << endl;
    cout << "|     Gender, male: gm                  |" << endl;
    cout << "|     Birth year, ascending: ba         |" << endl;
    cout << "|     Birth year, descending: bd        |" << endl;
    cout << "|     Death year, ascending: da         |" << endl;
    cout << "|     Death year, descending: dd        |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::viewDisplay()
{
    string str;
    sorting_menu();

    //stringChoice();

    //return str;

    //displayFræðina();
}

/*void Console::dataWriteError ()
{
    cout << "No database found!" << endl;
}*/

void Console::sorting(string str)
{
    if (str == "na")
    {
        cout << "na virkar" << endl;
        //na fallið
    }
    else if (str == "nd")
    {
        cout << "nd" << endl;
        //nd fallið
    }
    else if (str == "gf")
    {
        cout << "gf virkar" << endl;
        //nd fallið
    }
    else if (str == "gm")
    {
        cout << "gm" << endl;
        //nd fallið
    }
    else if (str == "ba")
    {
        cout << "ba" << endl;
        //nd fallið
    }
    else if (str == "bd")
    {
        cout << "bd" << endl;
        //nd fallið
    }
    else if (str == "da")
    {
        cout << "da" << endl;
        //nd fallið
    }
    else if (str == "dd")
    {
        cout << "dd" << endl;
        //nd fallið
    }
    else
    {
        cout << "Enter valid command" << endl;
    }
}

/*void Console::run()
{
    welcome();

    char arg;

    while (arg != 'q')
    {
        break;
    }


}
*/

/**********************************************************
                    ERRORS
 **********************************************************/

void Console::dataWriteError ()
{
    cout << "No database found!" << endl;
}

void Console::dataSearchNotFound ()
{
    cout << "No items found" << endl;
}
/**********************************************************/

