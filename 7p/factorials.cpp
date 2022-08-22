// count n! by recursion

#include <iostream>

long long fact(int n);

int main()
{
    using namespace std;
    int n;
    while(cout << "Enter the number, q to exit\n", cin >> n)
        cout << n << "! = " << fact(n) << endl;
    return 0;
}

long long fact(int n)
{
    if (n < 2)
        return 1;
    return n * fact(n - 1);
}

