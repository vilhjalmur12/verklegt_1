#include "console.h"
#include "service.h"
#include "scientist.h"

#include <iostream>
#include <string>
#include <limits>


Console::Console(){ }

Console::~Console() { }

void Console::welcome()
{
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Welcome to Database          |" << endl;
    cout << "|        Press enter to continue        |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

char Console::continueFunction()
{
    char cont;
    cout << "Would you like to view again?\t(y/n)" << endl << "-> ";
    cont = choice();

    return cont;
}



// Enter to continue
// Yta a Enter til ad halda afram

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
    cout << "|            s - for search             |" << endl;
    cout << "|           q - for quitting            |" << endl;
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

void Console::printInsertScreen()
{
    cout << "-----------------------------------------" << endl;
    cout << "|       Please Insert Information       |" << endl;
    cout << "|        in the following format        |" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Name:   First (Middle) Last  |" << endl;
    cout << "|        Gender:   m/f                  |" << endl;
    cout << "| Year of Birth:   YYYY                 |" << endl;
    cout << "| Year of Death:   YYYY / na            |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::insertScientist()
{
    printInsertScreen();

    string name, sex;
    int YOB, YOD = inf;

    do
    {
        cout << "Name: "
        cin.getline(name);
    }while(!scientistService.validName(name));

    do
    {
    cout << "Gender: ";
    cin >> sex;
    }while(!scientistService.validSex(sex));

    do
    {
        string input;
        cout << "Year of birth: ";
        cin >> YOB;
        cout << "Year of death : ";
        cin >> input;
        if(input == "na");
        else
        {
            YOD = stoi(input);
        }

    }while(!scientistService.validYears());

    scientistService.appendScientist(name, sex, YOB, YOD);
}

// Það sem gerist ef þú velur view, insert eða search
void Console::choiceMade(Scientist &scientist, vector<Scientist> &allScientists)
{
    char choice_made = choice();

    do
    {
        char cont;

        if (choice_made == 'v')
        {
            do
            {
                string str;
                sorting_menu();

                str = stringChoice();
                sorting(str);
                
                printTable(allScientists);

                cont = continueFunction();

            } while (cont == 'y');
        }
        else if (choice_made == 'i')
        {
            insertScientist();

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
    } while ( (choice_made != 'q') && (choice_made != 's') && (choice_made != 'i') && (choice_made != 'v') );


}

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

// Notandi sendur i sorting_menu
void Console::viewDisplay()
{
    string str;
    sorting_menu();
    //displayFræðina();
}

// Tjekk a hvort val a sorteringu se rett valid
bool Console::sorting(string str)
{
    Service tmp;
    vector<Scientist> scientists;

    if (str == "na" || str == "nd" || str == "gf" || str == "gm" || str == "ba" || str == "bd" || str == "da" || str == "dd")
    {
        scientists = tmp.getScientists(str);


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


/**********************************************************
                Villi er að vinna hér
 **********************************************************/


void Console::run()
{
    welcome();
}


void Console::quit()
{
    cout << "Thank you for using Database, stay classy!" << endl << endl;

    exit(1);
}

void Console::printTable (vector<Scientist> allScientists)
{
    Scientist tmp;
    
    cout << "Name\t\tGender\tDate of birth\tDate of death" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    
    for (int i = 0; i < 4; i++)
    {
        tmp = allScientists[i];
        
        cout << tmp.getName() << "\t\t" << tmp.getSex() << "\t" << tmp.getYearOfBirth() << "\t" << tmp.getYearOfDeath() << endl;
    }
}


/**********************************************************/
