#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <string>
#include <iostream>

using namespace std;

class Computers
{
public:
    Computers();
    Computers(string name, string cpuType, bool built, int yearBuilt);    // Stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
    void pushComputer(string name, string cpuType, bool built, int yearBuilt);   // Stillir upplýsingar fyrir tölvur í meðlimabreytur
    virtual ~Computers();

/**************************************************
      Föll til að ná upplýsingum um tolvurnar
**************************************************/

    string getName() const;         // Dregur fram nafn tolvunnar úr meðlimabreytum og skilar því til baka
    bool getBuilt() const;          // Dregur fram hvort tolvan hafi verid byggd og skilar true eda false
    int getYearBuilt() const;       // Dregur fram arid sem tolvan var byggd og skilar því til baka
    string getCpuType() const;      // Dregur fram tegund tölvunnar og skilar henni til baka


/**************************************************
                 Operator föll
**************************************************/
    friend ostream& operator << (ostream& out, Computers sc);       // Prentar út allar uppl um tölvu í eina línu (aðskilið af tab-keypress)
    friend bool operator == (Computers lhs, Computers rhs);     // Ber saman upplýsingarnar til að sjá hvor þær séu eins

private:
/**************************************************
                 Meðlimabreytur
**************************************************/
    string _name;
    string _cpuType;
    bool _built;
    int _yearBuilt;
    vector<string> workedOnComputer;
};

#endif // COMPUTERS_H
