#include "Console.h"
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
    cout << "|           v - for viewing             |" << endl;
    cout << "|          i - for insertion            |" << endl;
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
        viewDisplay();

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
    stringChoice();
    cout << str << endl;

    //displayFræðina();
    //Setja hérna hvernig hægt er setja upp listann og kannski leita?
}

void Console::dataWriteError ()
{
    cout << "No database found!" << endl;
}

