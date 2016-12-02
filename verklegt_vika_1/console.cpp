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
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Welcome to Database          |" << endl;
    cout << "|        Press enter to continue        |" << endl;
    cout << "|       please ensure the console       |" << endl;
    cout << "|       window is at least 120x30       |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::viewOrInsert()
{
    cout << endl;
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

void Console::printPushBackMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       Please Insert Information       |" << endl;
    cout << "|        in the following format        |" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Name:   First (Middle) Last  |" << endl;
    cout << "|        Gender:   m/f/male/female      |" << endl;
    cout << "|  Contribution:   string               |" << endl;
    cout << "| Year of Birth:   YYYY                 |" << endl;
    cout << "| Year of Death:   (YYYY) / (n/a)       |" << endl;
    cout << "|   Nationality:   string               |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::sorting_menu()
{
    cout << endl;
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
    cout << "|   Nationality, ascending:  nta        |" << endl;
    cout << "|   Nationality, descending: ntd        |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::printChangeDelete()
{
    cout << endl;
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
    cout << endl;
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

void Console::printEditMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       What would you like to do?      |" << endl;
    cout << "|                                       |" << endl;
    cout << "|  l - see the full list of scientists  |" << endl;
    cout << "|      s - search for a scientist       |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::quitMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|     Thank you for using Database,     |" << endl;
    cout << "|             stay classy!              |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::loginMenu()
{
    cout << "-----------------------------------------" << endl;
    cout << "|             Choose option:            |" << endl;
    cout << "|                                       |" << endl;
    cout << "|           c - create new user         |" << endl;
    cout << "|               l - login               |" << endl;
    cout << "|               q - quit                |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

/********************************************************
                     Keyrsluföll
*********************************************************/
void Console::callUser ()
{
    database data;
    string password;
    string action;
    bool runProgram = false;

    welcome();
    toContinue();


    while (!runProgram)
    {
        loginMenu();
        cout << "-> ";
        cin >> action;

        if (action == "c")
        {
            string confirmPass = "password";

            cout << "Choose Username: ";
            cin >> user;


            while (password != confirmPass)
            {
                cout << "Choose Password: ";
                cin >> password;
                cout << "Confirm Password: ";
                cin >> confirmPass;

                if (password != confirmPass)
                {
                    cout << "You didn't confirm the right password" << endl;
                }
            }
            data.createUser(user, password);
            runProgram = true;

        }
        else if (action == "l")
        {
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> password;

            bool foundUser = data.getUser(user, password);

            if (foundUser == true)
            {
                runProgram = true;
            }
            else
            {
                cout << "Invalid user or password" << endl << endl;
            }
        }
        else if (action == "q")
        {
            exit(1);
        }
        else
        {
            cout << "Invaid action!" << endl << endl;
        }
    }
    Service newScientistService(user);
    scientistService = newScientistService;
    run();
}

void Console::run()
{
    bool programON = true;

    do
    {
        viewOrInsert();

        choiceMade();
        cin.ignore();

    } while (programON == true);
}

void Console::edit()
{
    string choice = "l";
    int index;
    printEditMenu();
    do
    {
        cout << "-> ";
        cin >> choice;
        if((choice != "l" && choice != "s") || cin.fail())
            cout << "Please insert valid choice" << endl;
    }while(choice != "l" && choice != "s");

    if(choice == "l")
    {
        printTable();
        do
        {
        cout << "Insert index to edit: ";
        cin.ignore();
        cin >> index;
        cin.clear();
        if(index <= 0 || index > scientistService.getLengthOfData() || cin.fail())
            cout << "Please insert valid index!" << endl;
        }while(index <= 0 || index > scientistService.getLengthOfData() || cin.fail());
        index -= 1;
    }
    else
    {
        string query;
        printSearchMenu();
        cout << "Query: ";
        cin >> query;
        index = findIndexToEdit(query);
    }
    if(index > -1)
    {
    cout << "--------Insert new Information:---------" << endl;
    pushBackScientist();
    scientistService.moveLastTo(index);
    }
}

void Console::search()
{
    string query;
    printSearchMenu();
    cout << "Query: ";
    cin >> query;
    cin.ignore();
    vector<int> indexesToPrint = scientistService.getIndexesWith(query);
    printTable(indexesToPrint);
    printChangeDelete();
    changeOrDelete(indexesToPrint);
}

void Console::viewDisplay()
{
    string str;
    sorting_menu();
}

string Console::continueFunction()
{
    string cont;

    cout << "Would you like to view again?\t(y/n)" << endl << "-> ";
    cont = choice();

    while(cont != "y" && cont != "n")
    {
        cout << "Please make a valid choice!" << endl << "-> ";
        cont = choice();
    }

    return cont;
}

void Console::quit()
{
    quitMenu();

    scientistService.saveData();

    exit(1);
}

/********************************************************
                    Opnunarföll
*********************************************************/

void Console::toContinue()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

/********************************************************
                   Valmyndarföll
*********************************************************/

string Console::choice()
{
    string choice_made;
    cin >> choice_made;

    return choice_made;
}

void Console::choiceMade()
{
    cout << "-> ";

    string choice_made = choice();
    string cont = "y";

    if (choice_made == "v")
    {
        do
        {
        string str;
        sorting_menu();

        str = stringChoice();
        sorting(str);

        cont = continueFunction();
        }while(cont == "y");
    }
    else if (choice_made == "i")
    {
        pushBackScientist();
    }

    else if (choice_made == "s")
    {
        search();
    }

    else if(choice_made == "e")
    {
        edit();
    }
    else if (choice_made == "q")
    {
        quit();
    }
    else
    {
        cout << "Please enter a valid command!" << endl;
    }

}

/********************************************************
                    Sorting föll
*********************************************************/

string Console::stringChoice()
{
    string str;
    cout << "-> ";
    cin >> str;
    return str;
}

/********************************************************
                    sorting
   Leifir notenda að velja hvernig hann skoðar listan
   @
*********************************************************/

void Console::sorting(string str)
{
    vector<Scientist> allScientists;
    bool isRunning = true;

    while (isRunning == true)
    {
        if (str == "na" || str == "nd" || str == "gf" || str == "gm" || str == "ba" || str == "bd" || str == "da" || str == "dd" || str == "nta" || str == "ntd")
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

/********************************************************
                  Hjálparföll við edit
*********************************************************/

int Console::findIndexToEdit(string oldName)
{
    int index = 0;
    vector<int> indexesWithQuery = (scientistService.getIndexesWith(oldName));

    printTable(indexesWithQuery);

    if(indexesWithQuery.size() > 0)
    {
        int input;
        do
        {
        cout << "Please enter the number of the entry you want to edit: ";
        cin >> input;
        }while(cin.fail());
        index = indexesWithQuery[input-1];

        return index;
    }
    else
        return -1;
}

void Console::pushBackScientist()
{
    printPushBackMenu();
    string name, sex, nationality, furtherInfo;
    int YOB, YOD;

    do
    {
        createScientist(name, sex, YOB, YOD, nationality, furtherInfo);
    }while(!scientistService.appendScientist(name, sex, YOB, YOD, nationality, furtherInfo));
}

void Console::createScientist(string &name, string &sex, int &YOB, int &YOD, string& nationality, string &furtherInfo)
{
    readName(name);

    readSex(sex);

    readFurtherInfo(furtherInfo);

    readYears(YOB, YOD);

    readNationality(nationality);
}

void Console::readName(string &name)
{
    do
    {
        cout << "Name: ";
        cin.ignore();
        do
        {
        getline(cin, name);
        }while(name.length()<1);

    }while(!scientistService.validName(name));
}

void Console::readSex(string &sex)
{
    do
    {
        cout << "Gender: ";
        cin >> sex;
    }while(!scientistService.validSex(sex));
}

void Console::readFurtherInfo(string &furtherInfo)
{
    cout << "Further Information: ";
    cin.ignore();
    getline(cin, furtherInfo);

    if(furtherInfo.length() > 0)
        furtherInfo.at(0) = toupper(furtherInfo.at(0));
}

void Console::readYears(int& YOB, int& YOD)
{
    bool cont = false;
    bool validYears = false;
    do
    {
        cont = false;
        validYears = true;

        readBirthYear(YOB, cont);

        if(cont)
            continue;

        readDeathYear(YOD, cont);

        if(cont || YOD == maxDeathYear)
            continue;

        validYears = scientistService.validYears(YOB, YOD);

    }while(!validYears || cont);
}

void Console::readBirthYear(int &YOB, bool &cont)
{
    cout << "Year of birth: ";
    cin >> YOB;

    if(cin.fail())
    {
        cin.sync();
<<<<<<< HEAD
        cin.clear();
        //cin.sync();
        throwError.invalidYear(4);
=======
        throwError.invalidYear(4); //---------------------------------------------------------------------------------------------------------
>>>>>>> 80cfbfdc6f7565177337a3f71412b761c4beb07c
        cont = true;
        return;
    }

    if(YOB < -2700)
    {
        cout << "Attention: your Computer Scientist will have to have been born before" << endl
             << "the invention of the abacus, the first known tool used for computation" << endl
             << "tip: enter an invalid Year of Death to re-input year of birth" << endl;
    }
    return;
}

void Console::readDeathYear(int &YOD, bool &cont)
{
    string input;

    cout << "Year of death: ";
    cin >> input;

    if(input == "n/a")
    {
        YOD = maxDeathYear;
        return;
    }
    if(!scientistService.validDeathYear(input))
    {
        throwError.invalidYear(4); //----------------------------------------------------------------------------------------------------------------
        cont = true;
        return;
    }
    else
    {
        YOD = stoi(input);
        return;
    }
}

void Console::readNationality(string &nationality)
{
    cout << "Nationality: ";
    cin.ignore();
    getline(cin, nationality);

    if(nationality.length() > 0)
        nationality.at(0) = toupper(nationality.at(0));
}


/********************************************************
                 Hjálparföll við search
*********************************************************/

void Console::changeOrDelete(vector<int> indexes)
{
    cout << "-> ";
    string changeDeleteChoice = choice();

    if(changeDeleteChoice == "q")
    {
        quit();
    }
    else if(changeDeleteChoice == "d")
    {
        int index;
        cout << "Insert the index you wish to delete: " << endl;
        do
        {
            cin.ignore();
            cin >> index;
            if(index <= 0 || index > scientistService.getLengthOfData() || cin.fail())
                cout << "Please insert valid index!" << endl;
        }while(index <= 0 || index > scientistService.getLengthOfData() || cin.fail());
        index -= 1;
        index = indexes[index];
        scientistService.removeScientist(index);
    }

    else if(changeDeleteChoice == "e")
    {
        int index;
        cout << "Insert the index you wish to edit: " << endl;
        do
        {
            cin.ignore();
            cin >> index;
            if(index <= 0 || index > scientistService.getLengthOfData() || cin.fail())
                cout << "Please insert valid index!" << endl;
        }while(index <= 0 || index > scientistService.getLengthOfData() || cin.fail());

        index -= 1;

        index = indexes[index];

        pushBackScientist();
        scientistService.moveLastTo(index);
    }
    else if(changeDeleteChoice == "m")
    {

    }
    else if(changeDeleteChoice == "s")
    {
        search();
    };
}

/********************************************************
                      Birta töflu
*********************************************************/

void Console::printTable ()
{
    vector<Scientist> allScientists = scientistService.getScientists();
    Scientist tmp;

    printf("%-5s%-35s%-15s%-16s%-16s%-14s%-20s\n", "Nr.", "Name", "Gender", "Year of Birth", "Year of Death", "Nationality", "Further Information");

    cout <<"--------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        tmp = allScientists[i];
        printf("%-5d%-35s%-15s%-16d%-16s%-14s%-20s\n",i+1, tmp.getName().c_str(), tmp.getSex().c_str(), tmp.getYearOfBirth(), tmp.getYearOfDeathForPrinting().c_str(),
               tmp.getNationality().c_str(), tmp.getFurtherInfo().c_str());
    }
}

void Console::printTable (vector<int> indexesToPrint)
{
    vector<Scientist> allScientists = scientistService.getScientists();
    Scientist tmp;

    if(indexesToPrint.size() == 0)
    {
        cout << endl;
        cout << "No related indexes found" << endl;
    }
    else
    {

        printf("%-5s%-35s%-15s%-16s%-16s%-14s%-20s\n", "Nr.", "Name", "Gender", "Year of Birth", "Year of Death", "Nationality", "Further Information");

        cout << endl;

        cout <<"------------------------------------------------------------------------------------------------------------------------------" << endl;

        for (unsigned int i = 0; i < indexesToPrint.size(); i++)
        {
            tmp = allScientists[indexesToPrint[i]];

            printf("%-5d%-35s%-15s%-16d%-16s%-14s%-20s\n",i+1, tmp.getName().c_str(), tmp.getSex().c_str(), tmp.getYearOfBirth(), tmp.getYearOfDeathForPrinting().c_str(),
                   tmp.getNationality().c_str(), tmp.getFurtherInfo().c_str());

        }
        cout << endl;
    }
}

