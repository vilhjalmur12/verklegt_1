#ifndef COMPUTERS_H
#define COMPUTERS_H

#include <string>
#include <iostream>

using namespace std;

class Computers
{
    /*Nafn, byggingarár, tegund og byggðe/ekki byggð?
String, int, string, bool
Gera notenda kleift að tengja saman tölvur og vísindamenn (fleiri en 1)
Finna leið til að implementa vensl í forriti og database.
Setja lika inn einn strengjavektor um það hverjit unnu við að búa til hvaða tölvu
*/
public:
    Computers();
    Computers(string name, string cpuType, bool built, int yearBuilt);    // Stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
    void pushComputer(string name, string cpuType, bool built, int yearBuilt);   // Stillir upplýsingar fyrir tölvur í meðlimabreytur

/**************************************************
      Föll til að ná upplýsingum um fræðingana
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
};

#endif // COMPUTERS_H
