#include "console.h"
#include "service.h"
#include "scientist.h"
#include "errorhandling.h"

#include <iostream>
#include <string>
#include <limits>
#include <regex>


Console::Console()
{
    Service serviceTemp;
    ErrorHandling errorTemp;

    throwError = errorTemp;
    scientistService = serviceTemp;
}

Console::~Console() { }


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
    cout << "|        Gender:   m/f/male/female      |" << endl;
    cout << "|  Contribution:   string               |" << endl;
    cout << "| Year of Birth:   YYYY                 |" << endl;
    cout << "| Year of Death:   (YYYY) / (n/a)       |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::sorting_menu()
{
    cout << "-----------------------------------------" << endl;
    cout << "| In what order would you like to view? |" << endl;
    cout << "|                                       |" << endl;
    cout << "|           Name, ascending: na         |" << endl;
    cout << "|          Name, descending: nd         |" << endl;
    cout << "|            Gender, female: gf         |" << endl;
    cout << "|              Gender, male: gm         |" << endl;
    cout << "|     Birth year, ascending: ba         |" << endl;
    cout << "|    Birth year, descending: bd         |" << endl;
    cout << "|     Death year, ascending: da         |" << endl;
    cout << "|    Death year, descending: dd         |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::printChangeDelete()
{
    cout << "-----------------------------------------" << endl;
    cout << "|       What would you like to do       |" << endl;
    cout << "|                                       |" << endl;
    cout << "|           s - search again            |" << endl;
    cout << "|         e - edit a Scientist          |" << endl;
    cout << "|        d - delete a Scientist         |" << endl;
    cout << "|           m - go to menu              |" << endl;
    cout << "|          q - quit program             |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::printSearchMenu()
{
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|      You can search by string         |" << endl;
    cout << "|      or substring. If you are         |" << endl;
    cout << "|      searching by date the            |" << endl;
    cout << "|      century or decade will           |" << endl;
    cout << "|      suffice                          |" << endl;
    cout << "|                                       |" << endl;
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

    while(cont != 'y' && cont != 'n')
    {
        cout << "Please make a valid choice!" << endl << "->";
        cont = choice();
    }



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
    int YOB, YOD;
    do
    {
        do
        {
            cout << "Name: ";
            cin.clear();
            cin.sync();
            do
            {
            getline(cin, name);
            }while(name.length()<1);

        }while(!scientistService.validName(name));

        do
        {
            cout << "Gender: ";
            cin >> sex;
        }while(!scientistService.validSex(sex));

        cin.clear();
        cin.sync();

        cout << "Further Information: ";

        cin.clear();
        cin.sync();
        getline(cin, furtherInfo);

        if(furtherInfo.length() > 0)
            furtherInfo.at(0) = toupper(furtherInfo.at(0));

        bool cont = false;
        bool validYears = false;
        do
        {
            cont = false;
            validYears = true;
            YOD = 200000000;
            string input;

            cout << "Year of birth: ";
            cin >> YOB;

            if(cin.fail())
            {
                cin.clear();
                cin.sync();
                throwError.invalidYear(4);
                cont = true;
                continue;
            }
            if(YOB < -2700)
            {
                cout << "Attention: your Computer Scientist will have to have been born before" << endl
                     << "the invention of the abacus, the first known tool used for computation" << endl
                     << "tip: enter an invalid Year of Death to re-input year of birth" << endl;
            }

            cout << "Year of death: ";
            cin >> input;

            bool deathContainsNonDigits = !regex_match(input, regex("^[0-9]+[0-9]*$"));

            if(input == "n/a")
            {
                continue;
            }
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

            if(cont == false)
                validYears = scientistService.validYears(YOB, YOD);

        }while(!validYears || cont);
    } while(!scientistService.appendScientist(name, sex, YOB, YOD, furtherInfo));
}

void Console::choiceMade()
{
    char choice_made = choice();
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
        }while(cont == 'y');
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
        cout << "Please enter a valid command!" << endl;
    }

}

void Console::viewDisplay()
{
    string str;
    sorting_menu();
}

int Console::findIndexToEdit(string oldName)
{
    int index = 0;
    vector<int> indexesWithQuery = (scientistService.getIndexesWith(oldName));

    printTable(indexesWithQuery);

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

void Console::changeOrDelete()
{
    char changeDeleteChoice = choice();

    if(changeDeleteChoice == 'q')
    {
        quit();
    }
    else if(changeDeleteChoice == 'd')
    {
        string query;
        cout << "Query for deletion: " << endl;
        cin >> query;
        int index = findIndexToEdit(query);
        scientistService.removeScientist(index);
    }

    else if(changeDeleteChoice == 'e')
    {
        edit();
    }
    else if(changeDeleteChoice == 'm')
    {

    }
    else if(changeDeleteChoice == 's')
    {
        search();
    };
}

void Console::search()
{
    string query;
    printSearchMenu();
    cout << "Query: ";
    cin >> query;
    vector<int> indexesToPrint = scientistService.getIndexesWith(query);
    printTable(indexesToPrint);
    printChangeDelete();
    changeOrDelete();
}

void Console::printTable (vector<int> indexesToPrint)
{
    vector<Scientist> allScientists = scientistService.getScientists();
    Scientist tmp;

    if(indexesToPrint.size() == 0)
    {
        cout << "No related indexes found" << endl;
    }
    else
    {
        printf("%-4s%-30s%-9s%-18s%-18s%-30s\n", "Nr.", "Name", "Gender", "Year of Birth", "Year of Death", "Further Information");
        cout <<"-------------------------------------------------------------------------------------------------------" << endl;

        for (unsigned int i = 0; i < indexesToPrint.size(); i++)
        {
            tmp = allScientists[indexesToPrint[i]];

            printf("%-4d%-30s%-9s%-18d%-18s%-30s\n",i+1, tmp.getName().c_str(), tmp.getSex().c_str(), tmp.getYearOfBirth(), tmp.getYearOfDeathForPrinting().c_str(), tmp.getFurtherInfo().c_str());

        }
    }
}

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

void Console::run()
{
    bool programON = true;
    
    welcome();
    toContinue();

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
    
    exit(1);
}

void Console::printTable ()
{
    vector<Scientist> allScientists = scientistService.getScientists();
    Scientist tmp;
    
    printf("%-4s%-30s%-9s%-18s%-18s%-30s\n", "Nr.", "Name", "Gender", "Year of Birth", "Year of Death", "Fruther Information");
    cout <<"-------------------------------------------------------------------------------------------------------" << endl;
    
    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        tmp = allScientists[i];
        printf("%-4d%-30s%-9s%-18d%-18s%-30s\n",i+1, tmp.getName().c_str(), tmp.getSex().c_str(), tmp.getYearOfBirth(), tmp.getYearOfDeathForPrinting().c_str(), tmp.getFurtherInfo().c_str());
    }
}
