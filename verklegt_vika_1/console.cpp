#include "Console.h"
#include <iostream>


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
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
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

void Console::choiceMade(char choice_made)
{
    if (choice_made == 'v')
    {
        cout << "view";

        //displayFræðina();
        //Setja hérna hvernig hægt er setja upp listann og kannski leita?
    }

    else if (choice_made == 'i')
    {
        cout << "insert";

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




/*char Console::choice(char x)
{
    cin >> x;

    cout << x;

}*/


