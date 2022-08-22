#include "Header.h"
#include <cstring>

using std::strlen;
using std::strcpy;

namespace mns
{

std::ostream& operator<<(std::ostream& os, const Base& b)
{
    b.show(os);
    return os;
}

Base::Base(const char * lb, int r)
{
    label = new char[strlen(lb) + 1];
    strcpy(label, lb);
    rating = r;
}

Base::Base(const Base& b)
{
    label = new char[strlen(b.label) + 1];
    strcpy(label, b.label);
    rating = b.rating;
}

Base& Base::operator=(const Base& b)
{
    if (this == &b)
        return *this;
    delete [] label;
    label = new char[strlen(b.label) + 1];
    strcpy(label, b.label);
    rating = b.rating;
    return *this;
}

Base::~Base()
{
    delete [] label;
}

void Base::show(std::ostream& os) const
{
    os << "label " << label << ", rating " << rating;
}

baseDMA::baseDMA(const char * lab, int r): Base(lab, r) { }

void baseDMA::show(std::ostream &os) const { Base::show(os); }

lacksDMA::lacksDMA(const char* col, const char* lab, int r): Base(lab, r)
{
    strncpy(color, col, COL_LEN);
}

lacksDMA::lacksDMA(const char * col, const Base& b): Base(b)
{
    strncpy(color, col, COL_LEN);
}

void lacksDMA::show(std::ostream& os) const
{
    Base::show(os);
    os << ", color " << color;
}

hasDMA::hasDMA(const char* st, const char * lab, int r): Base(lab, r)
{
    style = new char[strlen(st) + 1];
    strcpy(style, st);
}

hasDMA::hasDMA(const char * st, const Base& b): Base(b)
{
    style = new char[strlen(st) + 1];
    strcpy(style, st);
}

hasDMA::hasDMA(const hasDMA& h) : Base(h)
{
    style = new char[strlen(h.style) + 1];
    strcpy(style, h.style);
}

hasDMA& hasDMA::operator=(const hasDMA& h)
{
    if (this == &h)
        return *this;
    Base::operator=(h);
    delete [] style;
    style = new char[strlen(h.style) + 1];
    strcpy(style, h.style);
    return *this;
}

hasDMA::~hasDMA()
{
    delete [] style;
}

void hasDMA::show(std::ostream& os) const
{
    Base::show(os);
    os << ", style " << style;
}

}
