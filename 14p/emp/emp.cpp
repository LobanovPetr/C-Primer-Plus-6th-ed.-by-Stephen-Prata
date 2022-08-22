#include "emp.h"

namespace mns
{

abstr_emp::~abstr_emp() { }

ostream& operator<<(ostream& os, const abstr_emp& ae)
{
    cout << ae.fname << ' ' << ae.lname;
    return os;
}

void abstr_emp::ShowAll() const
{
    cout << left << setw(20) << "FName:" << setw(20) << fname << endl;
    cout << left << setw(20) << "LName:" << setw(20) << lname << endl;
    cout << left << setw(20) << "Job:"   << setw(20) << job << endl;
}

void abstr_emp::SetAll()
{
    cout << "Enter first name: ";
    getline(cin, fname);
    cout << "Enter last name: ";
    getline(cin, lname);
    cout << "Enter job: ";
    getline(cin, job);
}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    cout << left << setw(20) << "Reports to:" << setw(20) << fink::ReportsTo() << endl;
    cout << left << setw(20) << "In charge of:" << setw(20) << manager::inChargeOf() << endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter reports to: ";
    getline(cin, fink::ReportsTo());
    cout << "Enter in charge of: ";
    cin >> manager::inChargeOf();
}

}
