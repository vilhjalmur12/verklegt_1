#ifndef CONSOLE_H
#define CONSOLE_H

#include "../Domain/scientist.h"
#include "../Domain/service.h"
#include "../Domain/cputype.h"
#include "../Domain/errorlog.h"
#include "../Domain/activitylog.h"

using namespace std;

const int maxBuildhYear = 200000000;

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
    void editComputer();
    void search();                  //Notandi sendur í leitar vél
    void viewDisplay();             //Notandi sendur i sorting_menu
    string continueFunction();      //Spyr hvort eigi að endurtaka aðgerð og geymir valið y/n
    void quit();                    //Hættir í forriti
    void callUser ();               //Notandi getur loggað sig inn eða skráð nýjan user

/**************************************************
                    Opnunarföll
**************************************************/
    void welcome();                 //Kallar á upphafsmynd
    void toContinue();              //Notandi þarf að ýta á ENTER til að halda áfram

/**************************************************
                   Valmyndarföll
**************************************************/
    void viewOrInsert();                     //Birta aðal valmynd
    void loginMenu();                        //Login menu
    string choice();                         //Geyma valmöguleika
    void choiceMade();                       //Kalla á framkvæmd eftir vali notanda
    void printChangeDelete();                //Bjóða uppá að eiga við lista
    void quitMenu();                         //Skjár segir bless þegar þú hættir í forriti
    void viewMenu();                         //Spyr hvort það eigi að birta lista vísindamanna eða tölva
    void insertMenu();                       //Spyr hvort það eigi að bæta við vísindamanni eða tölvu
    void viewRecycleMenu();
    void viewRecycleEntryMenu();
    void printTypeMenu(vector<CpuType> type);
    void printPushBackMenu();                //Birtir valmynd þegar nýr vísindamaður er settur í gagnagrunn
    void printEditMenu();                    //Birtir valmynd þegar edit-a á vísindamann
    void printEditComputerMenu();            //Birtir valmynd þegar edit-a á tölvu
    void printRelationMenu();                //Birtir valmynd þar sem notandi getur valið að búa til ný vensl eða fjarlægja vensl
    void printCpuPushBackMenu();             //Birtir valmynd þegar ný tölva er settur í gagnagrunn
    void relate();                           //Birtir valmynd um það að notandi geti búið til ný vensl eða fjarlægt gömul vensl

/**************************************************
                   Sorting föll
**************************************************/
    void sorting_menu();                    //Birta valmynd yfir möguleika til að raða lista um vísindamenn
    string stringChoice();                  //Geyma val notanda yfir hvernig hann vildi raða listanum
    void sorting(string str);               //Birta raðaðann lista
    void cpuSortingMenu();                  //Birta valmynd yfir möguleika til að raða lista um tölvur
    void cpuSorting(string str);            //Birta raðaðan lista út frá ákvörðun notanda

private:
/**************************************************
                   Meðlimabreytur
**************************************************/
    ErrorHandling throwError;               //Sendir forrit í villu tékk
    Service scientistService;               //Heldur utan um upplýsingar frá gagnagrunni fyrir service hlutan
    QString user;
/**************************************************
       Föll sem að setja gögn inn í gagnagrunninn
             eða hjálpa til við það
**************************************************/

    void pushBackScientist();                                       //Býr til nýjan vísindamann í gagnagrunninn og ýtir honum aftast í listann
    void pushBackComputer();                                        //Býr til nýja tölvu í gagnagrunninn og ýtir henni aftast í listann
    void createScientist(string &firstName, string &lastName, string &sex, int &YOB, int &YOD, string& nationality, string &furtherInfo);  //Býr til nýjan vísindamann til að setjs í gagnagrunninn
    void createComputer(string &name, string &CpuType, int &yearBuilt, bool &built);    //Býr til nýja tölvu til að setja í gagnagrunninn
    void insertNewType();                                           //Leyfir notandanum að slá inn tegund tölvu til að setja inn í gagnagrunninn
    string askToRelate(string option);
    void addRelations();                                            //Notendi hefur valið að vensla saman tölvu og vísindamann og getur nú framkvæmt það
    void addRelationsToCpu(int cIndex);                             //Venslum bætt við ákveðna tölvu
    void addRelationsToSci(int sIndex);                             //Venslum bætt við ákveðinn vísindamann
    void removeRelations();                                         //Vensl fjarlægð
    int getScID();                                                  //Sækir í ID vísindamanns í gagnagrunninn útfrá staðsetningu/indexi sem notandi slær inn
    int getCpuID();                                                 //Sækir í ID tölvu í gagnagrunninn útfrá staðsetningu/indexi sem notandi slær inn
    void idInput(unsigned int &index, unsigned int size);           //Staðsetning á ID sem er sótt fyrir getSciID og getCpuID slegið inn og villutjekkað
    void editOrDeleteInput(vector<int> indexes, int &index, int getNumber); //Staðsetning valin á vísindamanni eða tölvu sem á að edit-a eða eyða
    void readCpuName(string &name);                                 //Nafn á tölvu slegið inn
    void readCpuType(string &CpuType);                              //Tegund tölvu slegin inn og lesið
    void readYearBuilt(int& yearBuilt);                             //Byggingarár tölvu slegið inn
    void readBuilt(bool &built);                                    //Notandi slær inn hvort tölvan hafi verið byggð eða ekki
    Scientist makeNewScientist();                                   //Nýr vísindamaður búinn til með hjálp createScientist fallinu, honum er hér skilað í Scientist klasann
    Computer makeNewComputer();                                     //Ný tölva búin til með hjálp createComputer fallinu, henni er hér skilað í Scientist klasann
    void readFirstName(string &firstName);                          //Tekur inn fyrra nafn fyrir vísindamann
    void readLastName(string &lastName);                            //Tekur inn seinna nafn fyrir vísindamann
    void readSex(string& sex);                                      //Tekur inn kyn fyrir vísindamann
    void readFurtherInfo(string& furtherInfo);                      //Tekur inn auka upplýsingar fyrir vísindamann
    void readNationality(string& nationality);                      //Tekur inn þjóðerni fyrir vísindamann
    void readYears(int& YOB, int& YOD);                             //Tekur inn fæðingar/dánar ár fyrir vísindamann
    void readBirthYear(int& YOB, bool& cont);                       //Athugar fæðingar ár á vísindamanni
    void readDeathYear(int& YOD, bool& cont);                       //Athugar dánar ár á vísindamanni
    void editMenu();                                                //Spyr hvort það eigi að breyta vísindamanni eða tölvu
    void deleteMenu();                                              //Spyr hvort það eigi að eyða vísindamanni eða tölvu
    string getInput(string opt1, string opt2, string opt3);         //
    string getInput(string opt1, string opt2, string opt3, string opt4);
/**************************************************
        Recycled Bin og hjálparföll þess
**************************************************/

    void recycledBin();
    void recycleScientists();
    void recycleComputers();
    void idInputCanBeZero(unsigned int &index, unsigned int size);      //Staðsetning á ID sem er sótt fyrir recycle virknina slegið inn og villutjekkað
/**************************************************
              Hjálparföll við search
**************************************************/
    void printSearchMenu();                                             //Birtir leitar valmynd
    void changeOrDelete(vector<int> indexes);                           //Tekur við ákvörðun frá notanda um edit

/**************************************************
           Hjálparföll við choiceMade
**************************************************/
    void viewOperation();                                               //Tekur ákvörðun um hvað sé gert hafi verið valið að view'a
    void insertOperation();                                             //Tekur ákvörðun um hvað sé gert hafi verið valið að inserta
    void editOperation();                                               //Tekur ákvörðun um hvað sé gert hafi verið valið að edit'a
    void deleteOperation();                                             //Tekur ákvörðun um hvað sé gert hafi verið valið að deleta
    void deleteOperationHelper(string choice);
/**************************************************
                 Birta töflu
**************************************************/
    void printScientists(vector<Scientist> allScientists);              //Athugar hvort vísindamenn fundust, ef fundust þá prentaðir út
    void printComputers(vector<Computer> computers);                    //Athugar hvort tölvur fundust, ef fundust þá prentaðar út
};

#endif // CONSOLE_H
