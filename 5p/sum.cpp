#include <iostream>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    int a, b;
    int sum = 0;
    
    cout << "Enter two numbers.\n";
    cin >> a >> b;
    
    for (int i = a; i <= b; ++i)
        sum += i;
    
    cout << "Your sum: " << sum << endl;
    
    return 0;
}
