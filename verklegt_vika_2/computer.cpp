#include "computer.h"

Computer::Computer() { }

/****************************************************************************
                        Computer - smiður
    stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
            @parameter(string name) - nafn á tolvu
            @parameter(string cpuType) - tegund tolvu
            @parameter(bool built) - skialr true ef tolvan var byggd
            @parameter(int yearBuilt) - byggingarar tolvu
 ****************************************************************************/

Computer::Computer(int ID, string name, string cpuType, bool built, int yearBuilt)
{
    _ID = ID;
    _name = name;
    _cpuType = cpuType;
    _built = built;
    _yearBuilt = yearBuilt;
}

Computer::Computer(string name, string cpuType, bool built, int yearBuilt)
{
    _name = name;
    _cpuType = cpuType;
    _built = built;
    _yearBuilt = yearBuilt;
}

Computer::~Computer() { }

/****************************************************************************
                        pushComputer
    Stillir upplýsingar fyrir tölvu í meðlimabreytur
            @parameter(string name) - nafn á tölvu
            @parameter(string cpuType) - tegund tölvu
            @parameter(bool built) - skilar true ef tölvan var byggð
            @parameter(int yearBuilt) - byggingarár tölvu
 ****************************************************************************/

void Computer::pushComputer(string name, string cpuType, bool built, int yearBuilt)
{
    _name = name;
    _cpuType = cpuType;
    _built = built;
    _yearBuilt = yearBuilt;
}

int Computer::getID() const
{
    return _ID;
}

/****************************************************************************
                        getName
        Dregur fram nafn tölvu úr meðlimabreytum og skilar því til baka
                @return(string _name) - skilar nafni tölvu
 ****************************************************************************/

string Computer::getName() const
{
    return _name;
}

/**************** BREYTA *********************/
bool Computer::getBuilt() const
{
    return _built;
}

/****************************************************************************
                        getYearBuilt
        Dregur fram byggingarár tölvu úr meðlimabreytum og skilar því til baka
                @return(int _yearBuilt) - skilar byggingarári tölvu
 ****************************************************************************/

int Computer::getYearBuilt() const
{
    return _yearBuilt;
}
/****************************************************************************
                        get cpuType
        Dregur fram tegund tölvu úr meðlimabreytum og skilar henni til baka
                @return(string _cpuType) - skilar tegund tölvu
 ****************************************************************************/
string Computer::getCpuType() const
{
    return _cpuType;
}

/****************************************************************************
                        get computerAuthor
        Dregur fram hver byggdi tölvu úr meðlimabreytum og skilar því til baka
                @return(vector<string> _computerAuthor) - skilar þeim sem
                                        byggði tölvuna í vector
 ****************************************************************************/

vector<string> Computer::getBuilders() const
{
    return _builders;
}

void Computer::addBuilder(string lastName)
{
    _builders.push_back(lastName);
}

/**************************************************
             Operator föll
**************************************************/

/*
friend ostream& operator << (ostream& out, Computer co)     // Prentar út allar uppl um tölvu í eina línu (aðskilið af tab-keypress)
{
    out << co.getName() << "\t" << co.getCpuType() << "\t" << co.getBuilt() << "\t" << co.getYearBuilt();
    return out;
}

friend bool operator == (Computer lhs, Computer rhs)     // Ber saman upplýsingarnar til að sjá hvor þær séu eins
{
    (lhs.getName() == rhs.getName() && lhs.getCpuType() == rhs.getCpuType() && lhs.getBuilt() == lhs.getBuilt() && lhs.getYearBuilt() == rhs.getYearBuilt());
}
*/
