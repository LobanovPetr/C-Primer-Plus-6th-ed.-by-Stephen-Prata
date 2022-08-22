#include <iostream> #include <iostream>
int main() #include <string>
{int main()
    using namespace std; {
    int cnt = 0;     using namespace std;
    while(cin.peek() != '$')     string s;
    {     char ch;
        cin.get();     while(cin.get(ch))
        cnt++;     {
    }         s += ch;
    cout << cnt << endl;     }
    return 0;     cout << "Result string:\n";
}     cout << s;
     return 0;
 }

