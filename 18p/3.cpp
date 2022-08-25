#include <iostream>
using namespace std;

long double sum_values() { return 0; }

template<typename T, typename...Args>
long double sum_values(T t, Args... args)
{
    return t + sum_values(args...);
}

int main()
{
    cout << sum_values(1, 2, 5.6, 7, 20) << endl;
}
