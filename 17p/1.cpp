#include <iostream>

int main()
{
    using namespace std;
    int cnt = 0;
    while(cin.peek() != '$')
    {
        cin.get();
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
