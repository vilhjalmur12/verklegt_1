#include "cputype.h"

using namespace std;

CpuType::CpuType() { }

CpuType::~CpuType() {}

/****************************************************************************
                        cpuType - smiður
    stillir smiðinn þegar hann er búinn til með breytum sem byrjanargildi
            @parameter(int id) - ID tölvutegundar
            @parameter(string type) - tegund tölvu
 ****************************************************************************/

CpuType::CpuType(int id, string type)
{
    _ID = id;
    _type = type;
}

CpuType::CpuType(string type)
{
    _type = type;
}

/****************************************************************************
                                getID
        Dregur fram ID tölvutegundar úr meðlimabreytum og skilar því til baka
                @return(int _id) - skilar id tölvutegundar
 ****************************************************************************/

int CpuType::getId ()
{
    return _ID;
}

/****************************************************************************
                                getType
        Dregur fram tegund tölvu úr meðlimabreytum og skilar henni til baka
                @return(string _type) - skilar tegund tölvu
 ****************************************************************************/

string CpuType::getType ()
{
    return _type;
}
