#ifndef CONSOLE_H
#define CONSOLE_H

#include "scientist.h"
#include "service.h"

#include <vector>
#include <string>

using namespace std;

class Console
{
public:
    Console();
    virtual ~Console();
/**************************************************
                    Keyrsluföll
**************************************************/
    void run();                     //Keyrir forrit í gang
    void edit();                    //Notandi sendur í edit glugga
    void search();                  //Notandi sendur í leitar vél
    void viewDisplay();             //Notandi sendur i sorting_menu
    string continueFunction();      //Spyr hvort eigi að endurtaka aðgerð og geymir valið y/n
    void quit();                    //Hættir í forriti
    void callUser ();               //Notandi getur loggað sig inn eða skráð nýjan user

/**************************************************
                    Opnunarföll
**************************************************/
    void welcome();         //Kallar á upphafsmynd
    void toContinue();      //Notandi þarf að ýta á ENTER til að halda áfram

/**************************************************
                   Valmyndarföll
**************************************************/
    void viewOrInsert();        //Birta aðal valmynd
    void loginMenu();           //Login menu
    string choice();            //Geyma valmöguleika
    void choiceMade();          //Kalla á framkvæmd eftir vali notanda
    void printChangeDelete();   //Bjóða uppá að eiga við lista
    void quitMenu();            //Skjár segir bless þegar þú hættir í forriti

/**************************************************
                   Sorting föll
**************************************************/
    void sorting_menu();        //Birta valmynd yfir möguleika til að raða lista um vísindamenn
    string stringChoice();      //Geyma val notanda yfir hvernig hann vildi raða listanum
    void sorting(string str);   //Birta raðaðann lista
    void cpuSortingMenu();      //Birta valmynd yfir möguleika til að raða lista um tölvur

private:
/**************************************************
                   Meðlimabreytur
**************************************************/
    QString user;               //Nafn fyrir user
    ErrorHandling throwError;   //Sendir forrit í villu tékk
    Service scientistService;   //Heldur utan um upplýsingar frá gagnagrunni fyrir service hlutan
/**************************************************
               Hjálparföll við edit
**************************************************/
    int findIndexToEdit(string oldName);                                                                            //Finnur nr. á vísindamann sem á að edit-a
    void printPushBackMenu();                                                                                       //Birtir valmynd þegar nýr vísindamaður er settur í gagnagrunn
    void printEditMenu();                                                                                           //Birtir valmynd þegar edit-a á vísindamann
    void pushBackScientist();                                                                                       //Býr til nýjan vísindamann í gagnagrunninn og ýtir honum aftast í listann
    void createScientist(int &ID, string &firstName, string &lastName, string &sex, int &YOB, int &YOD, string& nationality, string &furtherInfo);  //Býr til nýjan vísindamann
    void readFirstName(string &firstName);                                                                          //Tekur inn fyrra nafn fyrir vísindamann
    void readLastName(string &lastName);                                                                            //Tekur inn seinna nafn fyrir vísindamann
    void readSex(string& sex);                                                                                      //Tekur inn kyn fyrir vísindamann
    void readFurtherInfo(string& furtherInfo);                                                                      //Tekur inn auka upplýsingar fyrir vísindamann
    void readNationality(string& nationality);                                                                      //Tekur inn þjóðerni fyrir vísindamann
    void readYears(int& YOB, int& YOD);                                                                             //Tekur inn fæðingar/dánar ár fyrir vísindamann
    void readBirthYear(int& YOB, bool& cont);                                                                       //Athugar fæðingar ár á vísindamanni
    void readDeathYear(int& YOD, bool& cont);                                                                       //Athugar dánar ár á vísindamanni
    void printCpuPushBackMenu();                                                                                    //Birtir valmynd þegar ný tölva er settur í gagnagrunn
    void viewMenu();                                                                                                //Spyr hvort það eigi að skoða vísindamann eða tölvu
    void editMenu();                                                                                                //Spyr hvort það eigi að breyta vísindamanni eða tölvu
    void deleteMenu();                                                                                              //Spyr hvort það eigi að eyða vísindamanni eða tölvu


/**************************************************
              Hjálparföll við search
**************************************************/
    void printSearchMenu();                         //Birtir leitar valmynd
    void changeOrDelete(vector<int> indexes);       //Tekur við ákvörðun frá notanda um edit

/**************************************************
                 Birta töflu
**************************************************/
    void printTable();                              //Birtir töflu af vísindamönnum
    void printTable(vector<int> indexesToPrint);    //Birtir töflu af vísindamönnum fyrir edit
};

#endif // CONSOLE_H
