#include "emp.h"

namespace mns
{

abstr_emp::~abstr_emp() { }

void abstr_emp::ShowAll(ostream& os) const
{
    os << left << setw(20) << "FName:" << setw(20) << fname << endl;
    os << left << setw(20) << "LName:" << setw(20) << lname << endl;
    os << left << setw(20) << "Job:"   << setw(20) << job << endl;
}

void abstr_emp::SetAll(istream& is)
{
    getline(is, fname);
    getline(is, lname);
    getline(is, job);
}

istream& operator>>(istream& is, abstr_emp& ae)
{
    ae.SetAll(is);
    return is;
}
ostream& operator<<(ostream& os, const abstr_emp& ae)
{
    ae.ShowAll(os);
    return os;
}

void manager::ShowAll(ostream& os) const
{
    abstr_emp::ShowAll(os);
    os << left << setw(20) << "In charge of:" << setw(20) << inchargeof << endl;
}

void manager::SetAll(istream& is)
{
    abstr_emp::SetAll(is);
    is >> inchargeof;
    char ch;
    while(is.get(ch) && ch != '\n');
}

void fink::ShowAll(ostream& os) const
{
    abstr_emp::ShowAll(os);
    os << left << setw(20) << "Reports to:" << setw(20) << reportsto << endl;
}

void fink::SetAll(istream& is)
{
    abstr_emp::SetAll(is);
    getline(is, reportsto);
}


void highfink::ShowAll(ostream& os) const
{
    abstr_emp::ShowAll(os);
    os << left << setw(20) << "Reports to:" << setw(20) << fink::ReportsTo() << endl;
    os << left << setw(20) << "In charge of:" << setw(20) << manager::inChargeOf() << endl;
}

void highfink::SetAll(istream& is)
{
    abstr_emp::SetAll(is);
//    cout << "Enter reports to: ";
    getline(is, fink::ReportsTo());
//    cout << "Enter in charge of: ";
    is >> manager::inChargeOf();
    char ch;
    while(is.get(ch) && ch != '\n');
}

}
