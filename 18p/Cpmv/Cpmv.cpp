#include "Cpmv.h"
#include <iostream>

Cpmv::Cpmv(): pi(nullptr) {}
Cpmv::Cpmv(const std::string& q, const std::string & z)
{
    pi = new Info {q, z};
}
Cpmv::Cpmv(const Cpmv& c)
{
    std::cout << "copy constructor\n";
    pi = new Info {*c.pi};
}
Cpmv::Cpmv(Cpmv&& c)
{
    std::cout << "move constructor\n";
    delete pi;
    pi = c.pi;
    c.pi = nullptr;
}
Cpmv::~Cpmv()
{
    delete pi;
    pi = nullptr;
}
Cpmv& Cpmv::operator=(const Cpmv& c)
{
    std::cout << "copy operator\n";
    if (this == &c)
        return *this;
    delete pi;
    pi = new Info {*c.pi};
    return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& c)
{
    std::cout << "move operator\n";
    if (this == &c)
        return *this;
    delete pi;
    pi = c.pi;
    c.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv& c) const
{
    Cpmv toReturn(*this);
    toReturn.pi->qcode += c.pi->qcode;
    toReturn.pi->zcode += c.pi->zcode;
    return toReturn;
}

void Cpmv::Display() const
{
    if (pi == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    std::cout << "qcode: " << pi->qcode << std::endl;
    std::cout << "zcode: " << pi->zcode << std::endl;
}
