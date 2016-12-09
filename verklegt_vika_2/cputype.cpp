#include "cputype.h"

using namespace std;

cpuType::cpuType()
{

}

cpuType::~cpuType()
{

}

cpuType::cpuType(int id, string type)
{
    _ID = id;
    _type = type;
}

int cpuType::getId ()
{
    return _ID;
}

string cpuType::getType ()
{
    return _type;
}
