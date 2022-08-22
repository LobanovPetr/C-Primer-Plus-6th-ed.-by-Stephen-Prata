#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool palindrom(const string& s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (!isalpha(s[i]) && !isdigit(s[i]))
        {
            ++i;
            continue;
        }
        if (!isalpha(s[j]) && !isdigit(s[j]))
        {
            --j;
            continue;
        }
        if (tolower(s[i++]) != tolower(s[j--])) return false;
    }
    return true;
}

int main()
{
    cout << palindrom("aabb") << endl;
    cout << palindrom("abba") << endl;
    cout << palindrom("Madam, I'm Adam") << endl;
}
