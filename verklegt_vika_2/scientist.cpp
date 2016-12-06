#include "scientist.h"
#include <iostream>

using namespace std;

Scientist::Scientist() { }

/****************************************************************************
                        Scientist - smiður
    stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
            @parameter(string name) - nafn á vísindamann
            @parameter(string sex) - kyn vísindamanns
            @parameter(int YOB) - fæðingarár vísindamanns
            @parameter(int YOD) - dánarár vísindamanns
            @parameter(string nationality) - frá hvaða landi er vísindamaðurinn
            @parameter(string furtherInfo) - auka upplýsingar um vísindamann
 ****************************************************************************/

Scientist::Scientist(string firstName, string lastName, string sex, int YOB, int YOD, string nationality, string furtherInfo)
{
    _firstName = firstName;
    _lastName = lastName;
    _gender = sex;
    _YOB = YOB;
    int _YOD = YOD;
    _nationality = nationality;
    _info = furtherInfo;
}

/****************************************************************************
                        pushScientist
    Stillir upplýsingar fyrir vísindamann í meðlimabreytur
            @parameter(string name) - nafn á vísindamann
            @parameter(string sex) - kyn vísindamanns
            @parameter(int YOB) - fæðingarár vísindamanns
            @parameter(int YOD) - dánarár vísindamanns
            @parameter(string nationality) - frá hvaða landi er vísindamaðurinn
            @parameter(string furtherInfo) - auka upplýsingar um vísindamann
 ****************************************************************************/

void Scientist::pushScientist(string firstName, string lastName, string sex, int DOB, int DOD, string nationality, string furtherInfo)
{
    _firstName = firstName;
    _lastName = lastName;
    _gender = sex;
    _YOB = DOB;
    _YOD = DOD;
    _nationality = nationality;
    _info = furtherInfo;
}  

/**************************************************
                 Operator föll
**************************************************/

ostream& operator << (ostream& out, Scientist sc)
{
   out << sc.getFirstName() << "/t" << sc.getLastName() << "/t" << sc.getSex() << "/t" << sc.getYearOfBirth() << "/t" << sc.getYearOfDeath() << "/t"
       << sc.getNationality() << "/t" << sc.getNationality() << "/t" << sc.getFurtherInfo();
   return out;
}

bool operator ==(Scientist lhs, Scientist rhs)
{
   return (lhs.getFirstName() == rhs.getFirstName() && lhs.getLastName() == rhs.getLastName() && lhs.getSex() == rhs.getSex() && lhs.getYearOfBirth() == lhs.getYearOfBirth() && lhs.getYearOfDeath() == rhs.getYearOfDeath())
           && lhs.getNationality() == rhs.getNationality() && lhs.getFurtherInfo() == rhs.getFurtherInfo();
}

/****************************************************************************
                        getName
        Dregur fram nafn vísindamanns úr meðlimabreytum og skilar því til baka
                @return(string _name) - skilar nafni vísindamanns
 ****************************************************************************/
string Scientist::getFirstName() const
{
        return _firstName;
}

string Scientist::getLastName() const
{
        return _lastName;
}

/****************************************************************************
                        getSex
        Dregur fram kyn vísindamanns úr meðlimabreytum og skilar því til baka
                @return(string _sex) - skilar kyni vísindamanns
 ****************************************************************************/

string Scientist::getSex() const
{
        return _gender;
}

/****************************************************************************
                      getYearOfBirth
     Dregur fram fæðingarár vísindamanns úr meðlimabreytum og skilar því til baka
              @return(int _yearOfBirth) - skilar fæðingarári vísindamanns
 ****************************************************************************/

int Scientist::getYearOfBirth() const
{
        return _YOB;
}

/****************************************************************************
                      getYearOfDeath
     Dregur fram dánarár vísindamanns úr meðlimabreytum og skilar því til baka
                @return(int _yearOfDeath) - skilar dánarári vísindamanns
 ****************************************************************************/

int Scientist::getYearOfDeath() const
{
        return _YOD;
}

/****************************************************************************
                     getYearOfDeathForPrinting
        Dregur fram dánarár vísindamanns úr meðlimabreytum og skilar því til baka
        sérstaklega fyrir töflu í útprentun fyrir console
                @return(string _"n/a") - skilar að vísindamaður er ekki dáinn
                @return(string to_string(_yearOfDeath) - útbýr streng úr tölu og sendir til baka
 ****************************************************************************/

string Scientist::getYearOfDeathForPrinting() const
{
        if(_YOD==200000000)
            return "n/a";
        else
            return to_string(_YOD);
}

/****************************************************************************
                        getNationality
        Dregur fram þjóðerni vísindamanns úr meðlimabreytum og skilar því til baka
                @return(string _nationality) - skilar þjóðerni vísindamanns
 ****************************************************************************/

string Scientist::getNationality() const
{
    return _nationality;
}

/****************************************************************************
                        getFurtherInfo
        Dregur fram auka upplýsingar vísindamanns úr meðlimabreytum og skilar því til baka
                @return(string _getFurtherInfo) - skilar upplýsingum vísindamanns
 ****************************************************************************/

string Scientist::getFurtherInfo() const
{
        return _info;
}
