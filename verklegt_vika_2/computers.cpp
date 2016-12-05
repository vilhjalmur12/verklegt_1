#include "computers.h"

Computers::Computers() { }

Computers::~Computers() { }

string Computers::getName() const
{

}

bool Computers::getBuilt() const
{

}

int Computers::getYearBuilt() const
{

}

string Computers::getCpuType() const
{

}


/**************************************************
             Operator föll
**************************************************/
friend ostream& operator << (ostream& out, Computers sc);       // Prentar út allar uppl um tölvu í eina línu (aðskilið af tab-keypress)
friend bool operator == (Computers lhs, Computers rhs);     // Ber saman upplýsingarnar til að sjá hvor þær séu eins
