#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

template<typename T>
int reduce(T [], int);

template<typename T>
int reduce(T ar[], int size)
{
    sort(ar, ar + size);
    return unique(ar, ar + size) - ar;
}

int main()
{
    string ar[] {"hello", "it", "hello", "me", "it"};
    int size = sizeof(ar)/sizeof(string);
    string* end = ar + size;
    copy(ar, end, ostream_iterator<string, char>(cout, " "));
    size = reduce(ar, size);
    cout << endl;
    copy(ar, ar + size, ostream_iterator<string, char>(cout, " "));
    return 0;
}
