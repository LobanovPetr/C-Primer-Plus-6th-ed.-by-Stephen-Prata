// program asks user to enter the numbers
// and show their harmonic mean
// until user enters 0

#include<iostream>

double hMean(int x, int y);

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    
    int x, y;
    int i;
    
    do
    {
        i = 0;
        cout << "Enter the numbers to count harmonic mean\n";
        while(!(cin >> x >> y) && (++i < 4))
        {
            cout << "Incorrect input try again\n";
            cout << 4 - i << " tries left.\n";
            cin.clear();
            while(cin.get() != '\n');
        }
        if (i >= 4)
        {
            cout << "Incorrect input programms stops.\n";
            return 1;
        }
        cout << hMean(x, y) << endl;
    }
    while(x != 0 && y != 0);
    return 0;
}

double hMean(int x, int y)
{
    return (2.0 * x * y) / (x + y);
}
