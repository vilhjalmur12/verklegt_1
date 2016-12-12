#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string firstName, string lastName, string sex, int YOB, int YOD, string nationality, string furtherInfo);
    Scientist(int ID, string firstName, string lastName, string sex, int YOB, int YOD, string nationality, string furtherInfo);            // stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
    void pushScientist(string firstName, string lastName, string sex, int DOB, int DOD, string nationality, string furtherInfo);   // Stillir upplýsingar fyrir vísindamann í meðlimabreytur

/**************************************************
      Föll til að ná upplýsingum um fræðingana
**************************************************/

    int getID() const;
    string getFirstName() const;                // Dregur fram nafn vísindamanns úr meðlimabreytum og skilar því til baka
    string getLastName() const;
    string getSex() const;                      // Dregur fram kyn vísindamanns úr meðlimabreytum og skilar því til baka
    int getYearOfBirth() const;                 // Dregur fram fæðingarár vísindamanns úr meðlimabreytum og skilar því til baka
    int getYearOfDeath() const;                 // Dregur fram dánarár vísindamanns úr meðlimabreytum og skilar því til baka
    string getYearOfDeathForPrinting() const ;  // Dregur fram dánarár vísindamanns úr meðlimabreytum og skilar því til baka sérstaklega fyrir töflu í útprentun fyrir console
    string getNationality() const;              // Dregur fram þjóðerni vísindamanns úr meðlimabreytum og skilar því til baka
    string getFurtherInfo() const;              // Dregur fram auka upplýsingar vísindamanns úr meðlimabreytum og skilar því til baka
    vector<string> getComputersBuilt() const;
    bool getDeleted() const;

    void addComputerBuilt(string computer);

/**************************************************
                 Operator föll
**************************************************/
    friend ostream& operator << (ostream& out, Scientist sc);       // Prentar út allar uppl um vísindamann í eina línu (aðskilið af tab-keypress)
    friend bool operator == (Scientist lhs, Scientist rhs);         // Ber saman upplýsingarnar til að sjá hvor þær séu eins

private:
/**************************************************
                 Meðlimabreytur
**************************************************/
    int     _ID;
    string _firstName;
    string _lastName;
    string _gender;
    int    _YOB;
    int    _YOD;
    string _nationality;
    string _info;
    vector<string> _computersBuilt;
    bool _deleted;
};

#endif // SCIENTIST_H
