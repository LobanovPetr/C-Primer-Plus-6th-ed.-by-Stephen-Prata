#include "Classic.h"
#include <iostream>
#include "cstring"
using std::strncpy;
using std::strcpy;
using std::cout;
using std::endl;
using std::strlen;

namespace mns
{
Classic::Classic(): Cd()
{
    producer = new char[30];
    strcpy(producer, "Producer_name");
}

Classic::Classic(const char* perf, const char* lab, const char * prod, int sel, double pt): Cd(perf, lab, sel, pt)
{
    producer = new char[strlen(prod) + 1];
    strcpy(producer, prod);
}

Classic::Classic(const Classic& cls) : Cd(cls)
{
    producer = new char[strlen(cls.producer) + 1];
    strcpy(producer, cls.producer);
}

Classic& Classic::operator=(const Classic& cls)
{
    if (this == &cls)
        return *this;
    Cd::operator=(cls);
    delete [] producer;
    producer = new char[strlen(cls.producer) + 1];
    strcpy(producer, cls.producer);
    return *this;
}

void Classic::Report() const
{
    Cd::Report();
    cout << "Producer: " << producer << endl;
}
Classic::~Classic()
{
    delete [] producer;
}
}
