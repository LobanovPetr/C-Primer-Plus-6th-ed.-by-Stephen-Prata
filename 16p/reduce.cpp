#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

int reduce(long [], int);

int reduce(long ar[], int size)
{
    sort(ar, ar + size);
    return unique(ar, ar + size) - ar;
}

int main()
{
    long ar[] {2, 2, 1, 3, 4, 5, 4};
    int size = sizeof(ar)/sizeof(long);
    long * end = ar + size;
    copy(ar, end, ostream_iterator<long, char>(cout, " "));
    size = reduce(ar, size);
    cout << endl;
    copy(ar, ar + size, ostream_iterator<long, char>(cout, " "));
    return 0;
}
