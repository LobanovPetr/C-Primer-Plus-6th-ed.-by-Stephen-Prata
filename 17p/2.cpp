#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string s;
    char ch;
    while(cin.get(ch))
    {
        s += ch;
    }
    cout << "Result string:\n";
    cout << s;
    return 0;
}
