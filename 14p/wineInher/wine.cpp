#include "wine.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ios_base;
using std::cin;

namespace mns
{
Wine::Wine(const char* lab, int y, const int ys[], const int bs[]): std::string(lab), PairArray(ArrayInt(ys, y), ArrayInt(bs, y)), years(y) { }

Wine::Wine(const char * lab, int y): std::string(lab), PairArray(ArrayInt(y), ArrayInt(y)), years(y) { }

void Wine::GetBottles()
{
    cout << "Enter " << (const std::string&)(*this) << " data for " << years << " year(s):\n";
    for (int i = 0; i < years; ++i)
    {
        cout << "Enter the year: ";
        cin >> PairArray::first[i];
        cout << "Enter the bottles for this year: ";
        cin >> PairArray::second[i];
    }
}

const std::string& Wine::Label() const { return (const std::string&)(*this); }

int Wine::sum() const { return PairArray::second.sum(); }

void Wine::Show() const
{
    ios_base::fmtflags flags = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Wine: " << (const std::string&)(*this) << endl;
    cout.width(15);
    cout << "Year";
    cout.width(15);
    cout << "Bottles\n";
    for (int i = 0; i < years; ++i)
    {
        cout.width(15);
        cout << PairArray::first[i];
        cout.width(15);
        cout << PairArray::second[i];
        cout << endl;
    }
    cout.setf(flags, ios_base::floatfield);
}


}
