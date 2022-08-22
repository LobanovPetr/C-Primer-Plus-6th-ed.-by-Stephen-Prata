#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

class line
{
    string s;
public:
    operator string() const {return s;}
    friend istream& operator>>(istream&, line&);
};

istream& operator>>(istream& os, line& l)
{
    getline(os, l.s);
    return os;
}

int main()
{
    ifstream Mat("mat.dat");
    ifstream Pat("pat.dat");
    ofstream matNpat("matnpat.dat");
    
    if (!Mat.is_open())
    {
        cout << "Can't open mat.dat\n";
        return 0;
    }
    if (!Pat.is_open())
    {
        cout << "Can't open pat.dat\n";
        return 0;
    }
    if (!matNpat.is_open())
    {
        cout << "Can't open matnpat.dat\n";
        return 0;
    }
    
    vector<string> array((istream_iterator<line>(Mat)), istream_iterator<line>());
    copy(istream_iterator<line>(Pat), istream_iterator<line>(), back_insert_iterator<vector<string> >(array));
    sort(array.begin(), array.end());
    auto new_end = unique(array.begin(), array.end());
    copy(array.begin(), new_end, ostream_iterator<string, char>(matNpat, "\n"));
    
    return 0;
}
