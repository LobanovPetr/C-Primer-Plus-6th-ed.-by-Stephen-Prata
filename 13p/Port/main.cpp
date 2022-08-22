#include "Port.h"
#include <iostream>
using std::cout;
using std::endl;

using namespace mns;

int main()
{
    Port p("Brandi", "Green", 10);
    VintagePort vp("HawanaClub", 15, "petr", 1985);
    Port& ref_p = vp;
    cout << vp << endl;
    cout << ref_p << endl;
    return 0;
}
