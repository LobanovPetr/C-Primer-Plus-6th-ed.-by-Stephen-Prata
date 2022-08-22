#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    long double dapfbalance = 100.0L, cleobalance = 100.0L;
    int year = 0;
    
    while (cleobalance <= dapfbalance)
    {
        dapfbalance += 10;
        cleobalance *= 1.05;
        year++;
    }
    cout << "Year: " << year << endl;
    cout << "Cleo: " << cleobalance << endl;
    cout << "Daphne: " << dapfbalance << endl;
    return 0;
}
