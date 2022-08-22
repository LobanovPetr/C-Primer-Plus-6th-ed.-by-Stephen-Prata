// converts inches to foots
#include <iostream>

void inchtofoots(void);

int main()
{
    inchtofoots();
    return 0;
}

void inchtofoots(void)
{
    using namespace std;
    int inches;
    int foots;
    int reminder;
    const int coeff = 12;
    cout << "Enter the height in inches: __\b\b";
    cin >> inches;
    foots = inches / coeff;
    reminder = inches % coeff;
    cout << "Your height in foots: " << foots
    << " foots and " << reminder << " inches\n";
    
}
