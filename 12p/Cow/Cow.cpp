#include "cow.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

namespace spc
{
Cow::Cow()
{
    name[0] = '\0';
    hobby = nullptr;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strncpy(name, nm, 20);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow& c)
{
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
    if (this == &c)
        return *this;
    delete[] hobby;
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const
{
    cout << "Cow name: " << name << endl;
    if (hobby) cout << "Cow hobby: " << hobby << endl;
    cout << "Cow weight: " << weight << endl;
}

}
