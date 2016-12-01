#include "console.h"
#include "service.h"
#include "scientist.h"
#include "errorhandling.h"

#include <iostream>
#include <string>
#include <limits>
#include <regex>


Console::Console() { }

Console::~Console() { }

//commit

/********************************************************
                      Allir menu gluggar
*********************************************************/

void Console::welcome()
{
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Welcome to Database          |" << endl;
    cout << "|        Press enter to continue        |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::viewOrInsert()
{
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|           Choose procedure:           |" << endl;
    cout << "|            v - for viewing            |" << endl;
    cout << "|           i - for insertion           |" << endl;
    cout << "|            s - for search             |" << endl;
    cout << "|      e - for editing a scientist      |" << endl;
    cout << "|           q - for quitting            |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::printInsertMenu()
{
    cout << "-----------------------------------------" << endl;
    cout << "|       Please Insert Information       |" << endl;
    cout << "|        in the following format        |" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Name:   First (Middle) Last  |" << endl;
    cout << "|        Gender:   m/f                  |" << endl;
    cout << "| Year of Birth:   YYYY                 |" << endl;
    cout << "| Year of Death:   YYYY / n/a           |" << endl;
    cout << "-----------------------------------------" << endl;
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

void Console::changeDelete()
{
    cout << "-----------------------------------------" << endl;
    cout << "|   Would you like to pamper the list   |" << endl;
    cout << "|                                       |" << endl;
    cout << "|              c - change               |" << endl;
    cout << "|              d - delete               |" << endl;
    cout << "|              m - menu                 |" << endl;
    cout << "|              q - quit                 |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::printSearchMenu()
{
    cout << "-----------------------------------------" << endl;
    cout << "|      You can search by string         |" << endl;
    cout << "|      or substring. If you are         |" << endl;
    cout << "|      searching by date the            |" << endl;
    cout << "|      century or decade will           |" << endl;
    cout << "|      suffice                          |" << endl;
    cout << "-----------------------------------------" << endl;
}

/********************************************************
                      Föll
*********************************************************/


char Console::continueFunction()
{
    char cont;
    cout << "Would you like to view again?\t(y/n)" << endl << "-> ";
    cont = choice();

    return cont;
}

void Console::toContinue()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
    cout << "-> ";
    cin >> str;
    return str;
}

void Console::pushBackScientist()
{
    printInsertMenu();

    string name, sex, furtherInfo;
    int YOB, YOD = 200000000;

    do
    {
        cout << "Name: ";
        getline(cin, name);
    }while(!scientistService.validName(name));

    do
    {
        cout << "Gender: ";
        cin >> sex;
    }while(!scientistService.validSex(sex));

    cout << "Further Information: ";
    cin >> furtherInfo;

    bool cont = false;
    do
    {
        cont = false;
        string input;
        cout << "Year of birth: ";
        cin >> YOB;
        if(cin.fail())
        {
            throwError.invalidYear(4);
            cont = true;
            continue;
        }
        cout << "Year of death : ";
        cin >> input;

        bool deathContainsNonDigits = !regex_match(input, regex("^[0-9]+$"));

        if(input == "na");
        else if(deathContainsNonDigits)
        {
            throwError.invalidYear(4);
            cont = true;
            continue;
        }
        else
        {
            YOD = stoi(input);
        }

    }while(!scientistService.validYears(YOB, YOD) || cont);

    scientistService.appendScientist(name, sex, YOB, YOD, furtherInfo);
}

// Það sem gerist ef þú velur view, insert eða search
void Console::choiceMade()
{
    char choice_made = choice();
    bool isOn = true;
    

    while (isOn == true)
    {
        char cont = 'y';

        if (choice_made == 'v')
        {
            do
            {
                string str;
                sorting_menu();

                str = stringChoice();
                sorting(str);
                
                cont = continueFunction();
            } while (cont == 'y');
        }
        else if (choice_made == 'i')
        {
            pushBackScientist();
        }

        else if (choice_made == 's')
        {
            search();
        }

        else if(choice_made == 'e')
        {
            edit();
        }
        else if (choice_made == 'q')
        {
            quit();
        }
        else
        {
            cout << "Please enter a valid *** " << endl;
        }
    }
}

// Notandi sendur i sorting_menu
void Console::viewDisplay()
{
    string str;
    sorting_menu();
    //displayFræðina();
}

int Console::findIndexToEdit(string oldName)
{
    int index = 0;
    vector<int> indexesWithQuery = (scientistService.getIndexesWith(oldName));

    for(unsigned int i = 0; i < indexesWithQuery.size(); i++)
    {
        printTable(indexesWithQuery);
    }

    int input;

    cout << "Please enter the number of the entry you want to edit: ";
    cin >> input;

    index = indexesWithQuery[input];

    return index;
}

void Console::edit()
{
    string query;
    printSearchMenu();
    cout << "Query: ";
    cin >> query;
    int index = findIndexToEdit(query);
    cout << "--------Insert new Information:---------" << endl;
    pushBackScientist();
    scientistService.moveLastTo(index);
}

void Console::search()
{
    string query;
    printSearchMenu();
    cout << "Query: ";
    cin >> query;
    vector<int> indexesToPrint = scientistService.getIndexesWith(query);//á að leita
    printTable(indexesToPrint); //Prenta leitarniðurstöðu
    changeDelete();
    choice();
    char changeDeleteChoice = choice();

    if(changeDeleteChoice == 'q')
    {
        quit();

    }
    else if(changeDeleteChoice == 'd')
    {
        //TODO: delete fall
    }

    else if(changeDeleteChoice == 'c')
    {
        edit();
    }
    else if(changeDeleteChoice == 'm')
    {

    }


}

// Prenta út tölfu með upplýsingum
void Console::printTable (vector<int> indexesToPrint)
{
    vector<Scientist> allScientists = scientistService.getScientists();
    Scientist tmp;

    cout << "Nr.  Name\t\tGender\tDate of birth\tDate of death\tFurther Information" << endl;
    cout <<"----------------------------------------------------------------------" << endl;

    for (unsigned int i = 0; i < indexesToPrint.size(); i++)
    {
        tmp = allScientists[indexesToPrint[i]];

        cout << i << "  " << tmp.getName() << "\t\t" << tmp.getSex() << "\t" << tmp.getYearOfBirth() << "\t"
             << tmp.getYearOfDeath() << "\t" << tmp.getFurtherInfo() << endl;
    }
}

// Tjekk a hvort val a sorteringu se rett valid
void Console::sorting(string str)
{
    vector<Scientist> allScientists;
    bool isRunning = true;

    while (isRunning == true)
    {
        if (str == "na" || str == "nd" || str == "gf" || str == "gm" || str == "ba" || str == "bd" || str == "da" || str == "dd")
        {
            scientistService.SortedScientistsBy(str);
            printTable();
            isRunning = false;
        }
        else
        {
            cout << "Enter a valid command" << endl;
            str = stringChoice();
        }
    }
}

/**********************************************************
                Villi er að vinna hér
 **********************************************************/


void Console::run()
{
    
    bool programON = true;
    
    // Welcome
    void welcome ();
    
    // initial val
    do
    {
        viewOrInsert();
        
        choiceMade();
        
    } while (programON == true);
}


void Console::quit()
{
    cout << "Thank you for using Database, stay classy!" << endl << endl;
    
    scientistService.saveData();
}

void Console::printTable ()
{
    vector<Scientist> allScientists = scientistService.getScientists();
    Scientist tmp;
    
    cout << "Nr.  Name\t\tGender\tDate of birth\tDate of death\tFurther Information" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    
    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        tmp = allScientists[i];
        
        cout << i << "  " << tmp.getName() << "\t\t" << tmp.getSex() << "\t" << tmp.getYearOfBirth() << "\t"
             << tmp.getYearOfDeath() << "\t" << tmp.getFurtherInfo() << endl;
    }
}


/**********************************************************/
