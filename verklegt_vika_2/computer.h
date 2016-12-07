#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int ID, string name, string cpuType, bool built, int yearBuilt);           // Stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
    virtual ~Computer();
    void pushComputer(string name, string cpuType, bool built, int yearBuilt);   // Stillir upplýsingar fyrir tölvur í meðlimabreytur

/**************************************************
      Föll til að ná upplýsingum um tolvurnar
**************************************************/

    int getID() const;
    string getName() const;             // Dregur fram nafn tolvunnar úr meðlimabreytum og skilar því til baka
    bool getBuilt() const;              // Dregur fram hvort tolvan hafi verid byggd og skilar true eda false
    int getYearBuilt() const;           // Dregur fram arid sem tolvan var byggd og skilar því til baka
    string getCpuType() const;          // Dregur fram tegund tölvunnar og skilar henni til baka
    vector<string> getBuilders() const;   // Dregur fram hver byggdi tolvuna og skilar nafninu til baka i vector

    void addBuilder(string lastName);

/**************************************************
                 Operator föll
**************************************************/
    friend ostream& operator << (ostream& out, Computer co);       // Prentar út allar uppl um tölvu í eina línu (aðskilið af tab-keypress)
    friend bool operator == (Computer lhs, Computer rhs);         // Ber saman upplýsingarnar til að sjá hvor þær séu eins

private:
/**************************************************
                 Meðlimabreytur
**************************************************/
    int _ID;
    string _name;
    string _cpuType;
    bool _built;
    int _yearBuilt;
    vector<string> _builders;
};

#endif // COMPUTERS_H
