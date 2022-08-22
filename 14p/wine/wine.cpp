#include "wine.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ios_base;
using std::cin;

namespace mns
{
Wine::Wine(const char* lab, int y, const int ys[], const int bs[]): label(lab), years_bottles(ArrayInt(ys, y), ArrayInt(bs, y)), years(y) { }

Wine::Wine(const char * lab, int y): label(lab), years_bottles(ArrayInt(y), ArrayInt(y)), years(y) { }

void Wine::GetBottles()
{
    cout << "Enter " << label << " data for " << years << " year(s):\n";
    for (int i = 0; i < years; ++i)
    {
        cout << "Enter the year: ";
        cin >> years_bottles.first[i];
        cout << "Enter the bottles for this year: ";
        cin >> years_bottles.second[i];
    }
}

const std::string& Wine::Label() const { return label; }

int Wine::sum() const { return years_bottles.second.sum(); }

void Wine::Show() const
{
    ios_base::fmtflags flags = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "Wine: " << label << endl;
    cout.width(15);
    cout << "Year";
    cout.width(15);
    cout << "Bottles\n";
    for (int i = 0; i < years; ++i)
    {
        cout.width(15);
        cout << years_bottles.first[i];
        cout.width(15);
        cout << years_bottles.second[i];
        cout << endl;
    }
    cout.setf(flags, ios_base::floatfield);
}


}
