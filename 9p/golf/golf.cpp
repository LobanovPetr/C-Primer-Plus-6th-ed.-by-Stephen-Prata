#include "golf.h"

void setgolf(golf & g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
    return;
}

int setgolf(golf & g)
{
    using std::cin;
    using std::cout;
    
    cout << "Enter the name: ";
    if (!cin.get(g.fullname, Len))
    {
        cin.clear();
        while (cin.get() != '\n');
        return 0;
    }
    cout << "Enter the nandicap: ";
    cin >> g.handicap;
    cin.get();
    return 1;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
    return;
}

void showgolf(const golf &g)
{
    using std::cout;
    using std::endl;
    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
    return;
}
