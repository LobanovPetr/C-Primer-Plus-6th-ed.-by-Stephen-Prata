#include "Person.h"
#include <iostream>

using namespace mns;

using std::cout;
using std::endl;

int main()
{
    Person* mobs[] = {
        new Gunslinger("Sniper", 10, 0.5),
        new PokerPlayer("PokerPlayer"),
        new BadDude("Hooligan", 5, 0.1)
    };
    
    for (int i = 0; i < 3; ++i)
    {
        mobs[i]->Show();
        cout << endl;
    }
    
    BadDude bd("bd1", 3, 0.2);
}
