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


/******************************************************************
                      Allir menu gluggar
*******************************************************************/

void Console::welcome()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|                                       |" << endl;
    cout << "|          Welcome to Database          |" << endl;
    cout << "|        Press enter to continue        |" << endl;
    cout << "|       Please ensure the console       |" << endl;
    cout << "|       window is at least 120x30       |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::viewOrInsert()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|           Choose procedure:           |" << endl;
    cout << "|                                       |" << endl;
    cout << "|            v - for viewing            |" << endl;
    cout << "|           i - for insertion           |" << endl;
    cout << "|            s - for search             |" << endl;
    cout << "|            e - for editing            |" << endl;
    cout << "|           d - for deleting            |" << endl;
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
    cout << "|    Nationality, ascending: nta        |" << endl;
    cout << "|   Nationality, descending: ntd        |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::printChangeDelete()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       What would you like to do?      |" << endl;
    cout << "|                                       |" << endl;
    cout << "|               e - edit                |" << endl;
    cout << "|              d - delete               |" << endl;
    cout << "|            m - go to menu             |" << endl;
    cout << "|           s - search again            |" << endl;
    cout << "|           q - quit program            |" << endl;
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

void Console::printCpuPushBackMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       Please insert information       |" << endl;
    cout << "|        in the following format        |" << endl;
    cout << "|                                       |" << endl;
    cout << "|             Name:   string            |" << endl;
    cout << "|       Build year:   YYYY              |" << endl;
    cout << "|    Computer type:   string            |" << endl;
    cout << "|    Was it built?:   y/n               |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::editMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       What would you like to do?      |" << endl;
    cout << "|                                       |" << endl;
    cout << "|          s - edit a scientist         |" << endl;
    cout << "|          c - edit a computer          |" << endl;
    cout << "|           q - quit program            |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::deleteMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       What would you like to do?      |" << endl;
    cout << "|                                       |" << endl;
    cout << "|         s - delete a scientist        |" << endl;
    cout << "|         c - delete a computer         |" << endl;
    cout << "|           q - quit program            |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::viewMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       What would you like to do?      |" << endl;
    cout << "|                                       |" << endl;
    cout << "|          s - view a scientist         |" << endl;
    cout << "|          c - view a computer          |" << endl;
    cout << "|           q - quit program            |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::cpuSortingMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| In what order would you like to view? |" << endl;
    cout << "|                                       |" << endl;
    cout << "|           Name, ascending: na         |" << endl;
    cout << "|          Name, descending: nd         |" << endl;
    cout << "|     Build year, ascending: ba         |" << endl;
    cout << "|    Build year, descending: bd         |" << endl;
    cout << "|  Computer type, ascending: ta         |" << endl;
    cout << "| Computer type, descending: td         |" << endl;
    cout << "|                Built, yes: by         |" << endl;
    cout << "|                 Built, no: bn         |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

void Console::insertMenu()
{
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|       What would you like to do?      |" << endl;
    cout << "|                                       |" << endl;
    cout << "|         s - insert a scientist        |" << endl;
    cout << "|         c - insert a computer         |" << endl;
    cout << "|           q - quit program            |" << endl;
    cout << "|                                       |" << endl;
    cout << "-----------------------------------------" << endl;
}

/****************************************************************************
                        callUser
    Notandi hefur val á að skrá sig inn í forritið eða skrá nýjan notanda
 ****************************************************************************/

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
        string tmpUser;
        loginMenu();
        cout << "-> ";
        cin >> action;

        if (action == "c")
        {
            string confirmPass = "password";


            cout << "Choose Username: ";
            cin >> tmpUser;
            QString tmpQUser(tmpUser.c_str());
            user = tmpQUser;

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
            QString qPassword(password.c_str());

            string firstName, lastName;
            cout << "Enter your first name: ";
            cin >> firstName;
            cout << "Enter your last name: ";
            cin >> lastName;

            QString qFirstName(firstName.c_str());
            QString qLastName(lastName.c_str());

            data.createUser(user, qPassword, qFirstName, qLastName);
            runProgram = true;

        }
        else if (action == "l")
        {
            cout << "Username: ";
            cin >> tmpUser;
            cout << "Password: ";
            cin >> password;

            QString tmpQUser(tmpUser.c_str());
            user = tmpQUser;
            QString qPassword(password.c_str());

            bool foundUser = data.getUser(user, qPassword);

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

/******************************************************************************
                         run
    Keyrir forritið fyrir þann notanda sem skráði sig inn í callUser fallinu.
 ******************************************************************************/

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

/******************************************************************************
                         edit
    Birtir edit valmynd og tekur við upplýsingum um hvort notandi vill velja
    vísindamann úr lista eða leita í gagnagrunni að vísindamanni.
 ******************************************************************************/

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
        printScientists(scientistService.getScientists());
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

/******************************************************************************
                         search
    Birtir leitar valmynd og tekur við leitar streng. Birtir síðan töflu af
    vísindamönnum ásamt index-um og valmynd um þar sem notandi ákveður hvort
    eigi að edit-a, eyða, leita aftur, fara aftur á aðvalmynd eða hætta keyrslu.
 ******************************************************************************/

void Console::search()
{
  vector<Scientist> scientists;
  vector<Computer> computers;
  string query;

  printSearchMenu();
  cout << "Query: ";
  cin >> query;

  scientistService.searchInDatabase(scientists, computers, query);
  printScientists(scientists);
  printComputers(computers);
  ///-------------------------------------------------------------------SKOÐA CHANGE/DELETE/LEITA AFTUR/MENU
}
/*
void Console::search() -- GAMLA FALLIÐ
{
    string query;
    cout << "Query: ";
    cin >> query;
    cin.ignore();
    vector<int> indexesToPrint = scientistService.getIndexesWith(query);
    printTable(indexesToPrint);
    printChangeDelete();
    changeOrDelete(indexesToPrint);
}
*/

/******************************************************************************
                         viewDisplay
             Birtir sorting-menu fyrir notanda
 ******************************************************************************/

void Console::viewDisplay()
{
    string str;
    sorting_menu();
}


/******************************************************************************
                         continueFunction
      Eftir að notandi velur að skoða listan þá er hann spurður hvort hann
      vilji skoða hann aftur með vali um y/n.
      @return(string cont) - y/n frá notenda
 ******************************************************************************/
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

/******************************************************************************
                         quit
      Hættir keyrslu á forritinu og vistar gögn í gagnagrunn.
 ******************************************************************************/
void Console::quit()
{
    quitMenu();

   //  scientistService.saveData();

   // cout << scientistService.getErrorString();

    exit(1);
}

/******************************************************************************
                         toContinue
      Notandi þarf að ýta á enter til að komast í fram hjá upphafs glugga í
      fyrstu valmynd.
 ******************************************************************************/

void Console::toContinue()
{
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

/******************************************************************************
                         toContinue
      Tekur á móti ákvörðun frá notanda um hvað á að gera frá fyrstu valmynd.
      @return(choice_made) - ákvörðun frá notenda
 ******************************************************************************/
string Console::choice()
{
    string choice_made;
    cin >> choice_made;

    return choice_made;
}

/******************************************************************************
                         choiceMade
      Tekur við ákvörðun frá notanda um hvað á að gera frá fyrstu valmynd.
      v-skoða lista, i-bæta við nýjum, s-leita, e-edit, q-hætta.
 ******************************************************************************/
void Console::choiceMade()
{
    cout << "-> ";

    string choice_made = choice();
    string cont = "y";
    //string cont;

    if (choice_made == "v")
    {
        do
        {
            viewMenu();
            cout << "-> ";
            string choice_made = choice();

            //do
            //{
                if (choice_made == "s")
                {
                    string str;
                    sorting_menu();
                    str = stringChoice();

                    sorting(str);
                }
                else if (choice_made == "c")
                {
                    string str;
                    cpuSortingMenu();

                    str = stringChoice();
                    //cpuSorting(str); sem a eftir ad utbua

                    cout << "listi yfir tolvur" << endl;

                    //TODO: sorta tölvur
                }
                else if (choice_made == "q")
                {
                    quit();
                }
                else
                {
                    cout << "Please enter a valid command!" << endl;
                }

                cont = continueFunction();

            //}while(cont == "y");
        }while(cont == "y");
    }
    else if (choice_made == "i")
    {
       insertMenu();
       string tmp = "n";

       do
       {
           cout << "-> ";
           string choice_made = choice();

           if (choice_made == "s")
           {
               pushBackScientist();
               tmp = "n";
           }
           else if (choice_made == "c")
           {
               cout << "bæta við tölvu" << endl;
               tmp = "n";
           }
           else if (choice_made == "q")
           {
               quit();
               tmp = "n";
           }
           else
           {
               cout << "Please enter a valid command!" << endl;
               tmp = "y";
           }
       }while (tmp == "y");
   }
   else if (choice_made == "s")
   {
       search();
   }
   else if(choice_made == "e")
   {
       string tmp = "n";
       editMenu();

       do
       {
           cout << "-> ";
           string choice_made = choice();

           if (choice_made == "s")
           {
               edit();
               tmp = "n";
           }
           else if (choice_made == "c")
           {
               cout << "edit computers" << endl;
               // TODO: edit fall fyrir tölvur
               tmp = "n";
           }
           else if (choice_made == "q")
           {
               quit();
               tmp = "n";
           }
           else
           {
               cout << "Please enter a valid command!" << endl;
               tmp = "y";
           }
       }while (tmp == "y");
   }
   else if (choice_made == "d")
   {
       string tmp = "n";

       do
       {
           void deleteMenu();
           cout << "-> ";
           string choice_made = choice();

           if (choice_made == "s")
           {
               cout << "delete scientists" << endl;
               tmp = "n";
           }
           else if (choice_made == "c")
           {
               cout << "delete computers" << endl;
               tmp = "n";
           }
           else if (choice_made == "q")
           {
               quit();
               tmp = "n";
           }
           else
           {
               cout << "Please enter a valid command!" << endl;
               tmp = "y";
           }
       }while(tmp == "y");
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


/******************************************************************************
                         stringChoice
      Tekur á móti ákvörðun um hvernig notandi vill sorta lista.
      @return(string str) - sorting command frá notenda
 ******************************************************************************/

string Console::stringChoice()
{
    string str;
    cout << "-> ";
    cin >> str;
    return str;
}

/********************************************************
                    sorting
  Tekur inn ávörðun frá notenda um hvernig hann skoðar listan.
  Prentar lista út í samræmi.
  @parameter(string str) - ákvörðun frá notenda
*********************************************************/

void Console::sorting(string str)
{
    vector<Scientist> allScientists;
    bool isRunning = true;

    while (isRunning == true)
    {
        if (str == "na" || str == "nd" || str == "gf" || str == "gm" || str == "ba" || str == "bd" || str == "da" || str == "dd" || str == "nta" || str == "ntd")
        {
            //scientistService.sortScientistsBy(str);
            printScientists(scientistService.getScientists());
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
                    findIndexToEdit
  Finnur það index af vísindamanni sem notandi vill edit-a
  @parameter(string oldName) - leitarstrengur frá notenda
  @return(int index) - tilvísun í ákveðin vísindamann í lista
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

/******************************************************************
                      pushBackScientist
    Býr til nýjan vísindamann í gagnagrunninn og ýtir honum aftast í listann
 ******************************************************************/

void Console::pushBackScientist()
{
    printPushBackMenu();
    string firstName, lastName, sex, nationality, furtherInfo;
    int YOB, YOD;

    do
    {
        createScientist(firstName, lastName, sex, YOB, YOD, nationality, furtherInfo);
    }while(!scientistService.appendScientist(firstName, lastName, sex, YOB, YOD, nationality, furtherInfo));
}

/******************************************************************
                      createScientist
    Býr til nýjan vísindamann í gagnagrunninn
            @parameter(int &name) - bendir á streng sem inniheldur nafn vísindamanns
            @parameter(int &sex) - bendir á streng sem inniheldur kyn vísindamanns
            @parameter(int &YOB) - bendir á tölu sem inniheldur fæðingarár
            @parameter(int &YOD) - bendir á tölu sem inniheldur dánarár
            @parameter(string &furtherInfo) - bendir á streng sem
                inniheldur auka upplýsingar notanda
            @parameter(string &nationality) - bendir á streng sem
                inniheldur þjóðernis geymslu notanda
 ******************************************************************/

void Console::createScientist(string &firstName, string &lastName, string &sex, int &YOB, int &YOD, string& nationality, string &furtherInfo)
{

    readFirstName(firstName);

    readLastName(lastName);

    readSex(sex);

    readNationality(nationality);

    readFurtherInfo(furtherInfo);

    readYears(YOB, YOD);

}

/******************************************************************
                      readName
    Tekur inn nafn fyrir vísindamann
            @parameter(int &name) - bendir á streng sem inniheldur nafn vísindamanns
 ******************************************************************/

void Console::readFirstName(string &firstName)
{
    do
    {
        cout << scientistService.getErrorString();
        cout << "First Name: ";
        cin.ignore();
        do
        {
        getline(cin, firstName);
        }while(firstName.length()<1);

    }while(!scientistService.validName(firstName));
}

void Console::readLastName(string &lastName)
{
    do
    {
        cout << scientistService.getErrorString();
        cout << "Last Name: ";
        do
        {
        cin >> lastName;
        }while(lastName.length()<1);

    }while(!scientistService.validName(lastName));
}

/******************************************************************
                      readSex
    Tekur inn kyn fyrir vísindamann
            @parameter(int &sex) - bendir á streng sem inniheldur kyn vísindamanns
 ******************************************************************/

void Console::readSex(string &sex)
{
    do
    {
        cout << scientistService.getErrorString();
        cout << "Gender: ";
        cin >> sex;
    }while(!scientistService.validSex(sex));
}

/******************************************************************
                      readYears
    Tekur inn fæðingar/dánar ár fyrir vísindamann
            @parameter(int &YOB) - bendir á tölu sem inniheldur fæðingarár
            @parameter(int &YOD) - bendir á tölu sem inniheldur dánarár
 ******************************************************************/

void Console::readYears(int& YOB, int& YOD)
{
    bool cont = false;
    bool validYears = false;
    do
    {
        cout << scientistService.getErrorString();
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

/******************************************************************
                      readBirthYear
    Athugar fæðingar ár á vísindamanni
            @parameter(int &YOB) - bendir á tölu sem inniheldur fæðingarár
            @parameter(bool &cont) - bendir á bool breytu sem segjir til
            um hvort halda eigi áfram
 ******************************************************************/

void Console::readBirthYear(int &YOB, bool &cont)
{
    cout << "Year of birth: ";
    cin >> YOB;

    if(cin.fail())
    {
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        scientistService.logYearError(4);
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

/******************************************************************
                      readDeathYear
    Athugar dánar ár á vísindamanni
            @parameter(int &YOD) - bendir á tölu sem inniheldur dánarár
            @parameter(bool &cont) - bendir á bool breytu sem segjir til
            um hvort halda eigi áfram
 ******************************************************************/

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
        cin.clear();
        cin.sync();
        scientistService.logYearError(6);
        cont = true;
        return;
    }
    else
    {
        YOD = stoi(input);
        return;
    }
}

/******************************************************************
                      readFurtherInfo
    Tekur inn auka upplýsingar fyrir vísindamann
            @parameter(string &furtherInfo) - bendir á streng sem
            inniheldur auka upplýsingar notanda
 ******************************************************************/

void Console::readFurtherInfo(string &furtherInfo)
{
    cout << "Further Information: ";
    cin.clear();
    getline(cin, furtherInfo);
    if(furtherInfo.length() > 0)
        furtherInfo.at(0) = toupper(furtherInfo.at(0));
}

/******************************************************************
                      readNationality
    Tekur inn þjóðerni fyrir vísindamann
            @parameter(string &nationality) - bendir á streng sem
            inniheldur þjóðernis geymslu notanda
 ******************************************************************/

void Console::readNationality(string &nationality)
{
    do
    {
    cout << scientistService.getErrorString();
    cout << "Nationality: ";
    cin.ignore();
    getline(cin, nationality);
    }while(!scientistService.validNationality(nationality));

    if(nationality.length() > 0)
        nationality.at(0) = toupper(nationality.at(0));
}


/******************************************************************
                      changeOrDelete
    Tekur við ákvörðun frá notanda um edit
            @parameter(vector<int> indexes) - vector (listi) af tölum
            sem segja til um stak vísindamanns í gagnagrunni
 ******************************************************************/

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

/******************************************************************
                      printTable
    Prentar út alla vísindamenn í gagnagrunni með viðmóti.
 ******************************************************************/


void Console::printScientists(vector<Scientist> allScientists)
{
    if(allScientists.size() == 0)
    {
        cout << endl << "-----------------------------------------------------No Scientists Found-----------------------------------------------------------------------------------" << endl;
        return;
    }
    cout << endl << endl << "---------------------------------------------------Scientists Found---------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

    printf("%-5s%-25s%-15s%-16s%-16s%-14s%-40s%-20s\n", "Nr.", "Name", "Gender", "Year of Birth", "Year of Death", "Nationality", "Further Information", "Computers Designed");

    cout <<"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (unsigned int i = 0; i < allScientists.size(); i++)
    {
        string computersString;
        vector <string> computers = allScientists[i].getComputersBuilt();

        for(unsigned int j = 0; j < computers.size(); j++)
        {
            computersString += computers[j];

            if(j != computers.size()-1)
                computersString += ", ";
        }

        Scientist tmp = allScientists[i];

        printf("%-5d%-10s%-15s%-15s%-16d%-16s%-14s%-40s%-20s\n",i+1, (tmp.getLastName()+",").c_str(), tmp.getFirstName().c_str(), tmp.getSex().c_str(), tmp.getYearOfBirth(), tmp.getYearOfDeathForPrinting().c_str(),
               tmp.getNationality().c_str(), tmp.getFurtherInfo().c_str(), computersString.c_str());
    }
}

void  Console::printComputers(vector<Computer> computers)
{
    if(computers.size() == 0)
    {
        cout << endl << "---------------------------------------------------No Computers Found-----------------------------------" << endl;
        return;
    }
    cout << endl << endl << "--------------------------------------------------Computers Found-------------------------------------------------" << endl << endl;

    printf("%-5s%-25s%-20s%-20s%-20s%-20s\n", "Nr.", "Name", "Year of build", "Type", "Built or not", "Creators");

    cout <<"-------------------------------------------------------------------------------------------------" << endl;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        Computer tmp = computers[i];

        string built;
        if(tmp.getBuilt())
            built = "Built";
        else
            built = "Not Built";

        string buildersString;
        vector<string> builders = computers[i].getBuilders();
        for(unsigned int j = 0; j < builders.size(); j++)
        {
            buildersString += builders[j];

            if(j != builders.size()-1)
                buildersString += ", ";
        }

        printf("%-5d%-25s%-20d%-20s%-20s%-20s\n",i+1, tmp.getName().c_str(), tmp.getYearBuilt(), tmp.getCpuType().c_str(), built.c_str(), buildersString.c_str());
    }
}

/******************************************************************
                      printTable
    Prentar út ákveðna valda vísindamenn í glugga með viðmóti
            @parameter(vector<int> indexesToPrint) - vector (listi) af þeim
            vísindamönnum sem skulu prentast
 ******************************************************************/

void Console::printTable (vector<int> indexesToPrint) // ÞAÐ ÞARF AÐ EYÐA ÞESSU FALLI OG KALLA ALLS STAÐAR Á PRINTSCIENTISTS(VECTOR) Í STAÐIN
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

            printf("%-5d%-35s%-15s%-16s%-16d%-14s%-20s\n",i+1, tmp.getFirstName().c_str(), tmp.getLastName().c_str(), tmp.getSex().c_str(), tmp.getYearOfBirth(), tmp.getYearOfDeathForPrinting().c_str(),
                   tmp.getNationality().c_str(), tmp.getFurtherInfo().c_str());

        }
        cout << endl;
    }
}
