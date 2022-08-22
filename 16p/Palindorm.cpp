#include <iostream>
#include <string>

using namespace std;

bool palindrom(const string& s)
{
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) if (s[i] != s[j]) return false;
    return true;
}

int main()
{
    cout << palindrom("aabb") << endl;
    cout << palindrom("abba") << endl;
    cout << palindrom("Otto") << endl;
    return 0;
}
