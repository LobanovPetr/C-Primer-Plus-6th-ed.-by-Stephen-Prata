#include<iostream>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    int num;
    int sum = 0;
    
    while(cin >> num, num != 0)
        sum += num;
    
    cout << sum << endl;
    
    return 0;
}
