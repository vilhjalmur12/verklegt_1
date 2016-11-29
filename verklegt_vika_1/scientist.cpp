#include "scientist.h"

Scientist::Scientist()
{

}

Scientist::Scientist(string name, string sex, int YOB, int YOD)
{
    _name = name;
    _sex = sex;
    _yearOfBirth = YOB;
    _yearOfDeath = YOD;
}
