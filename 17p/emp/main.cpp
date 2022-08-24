#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <utility>
#include <iomanip>
#include "emp.h"

using namespace mns;
using namespace std;

int read_data(istream& is, vector<unique_ptr<abstr_emp> >& v);
void menu();
int read_emp(istream& is, unique_ptr<abstr_emp>& ptr);

int main()
{
    fstream fin("data.dat", ios_base::in | ios_base::out);
    if (!fin.is_open())
    {
        cout << "Can't open file\n";
        return 0;
    }
    vector<unique_ptr<abstr_emp> > v;
    if(read_data(fin, v))
    {
        return 0;
    }
    cout << "Data in file:\n";
    for (const auto& it: v)
    {
        cout << *it << '\n';
    }
    
    int choose;
    char ch;
    while(menu(), cin >> choose)
    {
        unique_ptr<abstr_emp> ptr;
        if (choose == 4)
        {
            for (const auto& it: v)
            {
                cout << *it << '\n';
            }
            continue;
        }
        cin.putback(choose + '0');
        if (read_emp(cin, ptr))
        {
            cout << "Incorrect data\n";
            continue;
        }
        fin << choose;
        fin << '\n';
        fin << *ptr;
        v.push_back(std::move(ptr));
    }
    return 0;
}

int read_data(istream& is, vector<unique_ptr<abstr_emp> >& v)
{
    unique_ptr<abstr_emp> ptr;
    while (is.peek() != EOF)
    {
        if (read_emp(is, ptr))
        {
            cout << "Incorrect data\n";
            return 1;
        }
        v.push_back(std::move(ptr));
    }
    if (!is.eof())
    {
        cout << "Problem with file\n";
        return 1;
    }
    is.clear();
    return 0;
}

int read_emp(istream& is, unique_ptr<abstr_emp>& ptr)
{
    int type;
    is >> type;
    while(is && is.get() != '\n');
    switch (type)
    {
        case 0:
            ptr = unique_ptr<abstr_emp>(new employee);
            is >> *ptr;
            if (!is)
            {
                return 1;
            }
            break;
        case 1:
            ptr = unique_ptr<abstr_emp>(new manager);
            is >> *ptr;
            if (!is)
            {
                return 1;
            }
            break;
        case 2:
            ptr = unique_ptr<abstr_emp>(new fink);
            is >> *ptr;
            if (!is)
            {
                return 1;
            }
            break;
        case 3:
            ptr = unique_ptr<abstr_emp>(new highfink);
            is >> *ptr;
            if (!is)
            {
                return 1;
            }
            break;
        default:
            return 1;
    }
    return 0;
}

void menu()
{
    cout << "Menu:\n";
    cout << "0) to add employee   1) to add manager\n"
            "2) to add fink       3) to add highfink\n"
            "4) to show list      q) to exit\n";
}
