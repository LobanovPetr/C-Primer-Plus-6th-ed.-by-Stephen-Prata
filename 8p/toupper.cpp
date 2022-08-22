//converts the string to uppercase

#include <cctype>
#include <string>
#include <iostream>

using std::string;

string toup(const string &);

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    
    string str;
    
    while(cout << "Enter a string, q to stop: ", getline(cin, str) && str != "q")
        cout << toup(str) << endl;
    
    return 0;
}

string toup(const string& str)
{
    string upstr = str;
    for (int i = 0; i < upstr.size(); ++i)
    {
        upstr[i] = toupper(upstr[i]);
    }
    return upstr;
}
