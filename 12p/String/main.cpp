#include "String.h"
#include <iostream>

using msc::String;
using std::cout;
using std::endl;

int main()
{
    {
        String s("Hello, world!");
        String b("1234");
        cout << s << endl;
        cout << s.Size() << endl;
        cout << s + b << endl;
        cout << s[4] << endl;
        s[4] = 'b';
        cout << s << endl;
        cout << s.stringlow() << endl;
        cout << s.stringup() << endl;
        s = b;
        cout << s << endl;
        cout << s.Size() << endl;
    }
}
