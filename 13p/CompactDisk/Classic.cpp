#include "Classic.h"
#include <iostream>
#include "cstring"
using std::strncpy;
using std::strcpy;
using std::cout;
using std::endl;

namespace mns
{
Classic::Classic(): Cd()
{
    strcpy(producer, "Producer name");
}

Classic::Classic(const char* perf, const char* lab, const char * prod, int sel, double pt): Cd(perf, lab, sel, pt)
{
    strncpy(producer, prod, 40);
}
void Classic::Report() const
{
    Cd::Report();
    cout << "Producer: " << producer << endl;
}
}
