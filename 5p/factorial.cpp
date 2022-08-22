#include <iostream>
#include <array>
#include <iomanip>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::array;
    
    const int size = 100;
    array<long double, size> factorials;
    factorials[0] = factorials[1] = 1;
    
    cout << std::setprecision(16);
    
    for (int i = 2; i < 101; ++i)
        factorials[i] = factorials[i - 1] * i;
    
    for (int i = 0; i < 101; ++i)
        cout << i << " factorial : " << factorials[i] << endl;
    
    return 0;
}
