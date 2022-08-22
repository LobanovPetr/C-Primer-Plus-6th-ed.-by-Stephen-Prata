#include "Person.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

namespace mns
{
void Person::Data() const { cout << "Fullname: " << fullname << endl; }

void Person::Show() const { Data(); }

void Gunslinger::Data() const
{
    cout << "Cuts: " << cut << endl;
    cout << "Time: " << time << endl;
}

int PokerPlayer::Draw() const { return rand() % 52 + 1; }





}
