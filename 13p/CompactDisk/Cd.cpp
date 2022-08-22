#include "Cd.h"
#include <cstring>
#include <iostream>

using std::strncpy;
using std::strcpy;
using std::cout;
using std::endl;

namespace mns
{
Cd::Cd(const char* perf, const char* lab, int sel, double pt)
{
    strncpy(performers, perf, 50);
    strncpy(label, lab, 20);
    selections = sel;
    playtime = pt;
}

Cd::Cd()
{
    strcpy(performers, "Performers_name");
    strcpy(label, "Label_name");
    selections = 0;
    playtime = 0;
}

void Cd::Report() const
{
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}

}
