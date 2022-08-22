#include "Cd.h"
#include <cstring>
#include <iostream>

using std::strncpy;
using std::strcpy;
using std::cout;
using std::endl;
using std::strlen;

namespace mns
{
Cd::Cd(const char* perf, const char* lab, int sel, double pt)
{
    performers = new char[strlen(perf) + 1];
    label = new char[strlen(lab) + 1];
    strcpy(performers, perf);
    strcpy(label, lab);
    selections = sel;
    playtime = pt;
}

Cd::Cd()
{
    performers = new char[20];
    label = new char[20];
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

Cd::Cd(const Cd& cd)
{
    performers = new char[strlen(cd.performers) + 1];
    label = new char[strlen(cd.label) + 1];
    strcpy(performers, cd.performers);
    strcpy(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
}

Cd& Cd::operator=(const Cd& cd)
{
    if (this == &cd)
        return *this;
    delete [] performers;
    delete [] label;
    performers = new char[strlen(cd.performers) + 1];
    label = new char[strlen(cd.label) + 1];
    strcpy(performers, cd.performers);
    strcpy(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
    return *this;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

}
