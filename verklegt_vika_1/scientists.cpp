#include "scientists.h"

#include <iostream>

using namespace std;

Scientists readScientists()
{
    Scientists scientists;

    cout << "Name: ";
    cin >> scientists.name;

    cout << "Sex: ";
    cin >> scientists.sex;

    cout << "Birth Year: ";
    cin >> scientists.birthYear;

    cout << "Death Year: ";
    cin >> scientists.deathYear;

    return scientists;
}

void displayScientists(Scientists& scientists) {
    cout << "Name: " << scientists.name << endl;
    cout << "Sex: " << scientists.sex << endl;
    cout << "Birth Year: " << scientists.birthYear << endl;
    cout << "Death Year: " << scientists.birthYear << endl;

}
