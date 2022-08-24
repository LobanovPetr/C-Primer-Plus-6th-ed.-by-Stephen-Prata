#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void ShowStr(const string& s) { cout << s << endl; }

class Store
{
private:
    ostream& out;
public:
    Store(ostream& out_): out(out_) {}
    void operator()(const string& s) { size_t len = s.size(); out.write((char *)&len, sizeof(size_t));
        out.write(s.data(), s.size()); }
};

void GetStrs(istream& is, vector<string>& v);

int main()
{
    vector<string> vostr;
    string temp;
    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin, temp) && temp.size())
        vostr.push_back(temp);
    cout << "Here is your input.\n";
    
    for_each(vostr.begin(), vostr.end(), ShowStr);
    ofstream fout("string.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();
    
    vector<string> vistr;
    ifstream fin("string.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input.\n";
        return 0;
    }
    GetStrs(fin, vistr);
    for_each(vistr.begin(), vistr.end(), ShowStr);
}

void GetStrs(istream& is, vector<string>& v)
{
    size_t size;
    while(is && is.peek() != EOF)
    {
        is.read((char *)&size, sizeof(size));
        char * s = new char[size];
        is.read(s, size);
        v.push_back(string(s));
    }
}
