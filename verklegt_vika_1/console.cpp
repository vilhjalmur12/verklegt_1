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

// Enter to continue
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
    cout << "|           s - for searching           |" << endl;
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

// Það sem gerist ef þú velur view, insert eða search
void Console::choiceMade()
{
    do
    {
<<<<<<< HEAD
        char choice_made = choice();
    
        if (choice_made == 'v')
        {
            string str;
            sorting_menu();

            str = stringChoice();
            sorting(str);
        }

        else if (choice_made == 'i')
        {
            cout << "insert" << endl;;

            cout << "Enter name: " << endl;
            //cin << name;
            cout << "Enter gender: " << endl;
            //cin >> gender;
            cout << "Enter year of birth: " << endl;
            //cin >> yob;
            cout << "Enter year of death (if it applies): " << endl;
            //cin >> yod;

            /*
             string name;
             char sex;
             int birthYear;
             int deathYear;
             cin >> name;
             cin >> sex;
             cin >> birthYear;
             cin >> deathYear;

             */
        }

        else if (choice_made == 's')
        {
            cout << "Search" << endl;
        }
        else if (choice_made == 'q')
        {
            quit();
        }
        else
        {
            cout << "Please enter a valid *** " << endl;
        }
    } while (arg != q || arg != s || arg != i || arg !=v);
=======
        string str;

        do
        {
            viewDisplay();

            str = stringChoice();
        }

        while (sorting(str) == false);


    }

    else if (choice_made == 'i')
    {
        cout << "insert" << endl;;

        cout << "Enter name: " << endl;
        //cin << name;
        cout << "Enter gender: " << endl;
        //cin >> gender;
        cout << "Enter year of birth: " << endl;
        //cin >> yob;
        cout << "Enter year of death (if it applies): " << endl;
        //cin >> yod;

        /*
         string name;
         char sex;
         int birthYear;
         int deathYear;
         cin >> name;
         cin >> sex;
         cin >> birthYear;
         cin >> deathYear;

         */
    }

    else if (choice_made == 's')
    {
        cout << "Search" << endl;
    }

    else
    {
        cout << "Please enter a valid *** " << endl;
    }
>>>>>>> d22906a08aec771ad843759db7eab9ee73769192
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

<<<<<<< HEAD

=======
void Console::viewDisplay()
{
    string str;
    sorting_menu();
    //displayFræðina();
}
>>>>>>> d22906a08aec771ad843759db7eab9ee73769192


bool Console::sorting(string str)
{
    if (str == "na")
    {
        cout << "na virkar" << endl;
        return true;
    }
    else if (str == "nd")
    {
        cout << "nd" << endl;
        return true;
    }
    else if (str == "gf")
    {
        cout << "gf virkar" << endl;
        return true;
    }
    else if (str == "gm")
    {
        cout << "gm" << endl;
        return true;
    }
    else if (str == "ba")
    {
        cout << "ba" << endl;
        return true;
    }
    else if (str == "bd")
    {
        cout << "bd" << endl;
        return true;
    }
    else if (str == "da")
    {
        cout << "da" << endl;
        return true;
    }
    else if (str == "dd")
    {
        cout << "dd" << endl;
        return true;
    }
    else
    {
        cout << "Enter a valid command" << endl;
        return false;
    }
}



/*void Console::run()
 {
 welcome();
=======
/**********************************************************
                Villi er að vinna hér
 **********************************************************/


void Console::run()

{
    welcome();


 char arg;


 while (arg != 'q')
 {
    break;
 }


 }


void Console::quit()
{
    cout << "Thank you for using Database, stay classy!" << endl << endl;
    
    exit(1);
}


/**********************************************************/




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
