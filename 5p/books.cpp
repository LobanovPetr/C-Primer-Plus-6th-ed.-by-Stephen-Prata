#include <iostream>

int main()
{
    using std::cin;
    using std::endl;
    using std::cout;
    
    const char * months[] {
        "January",
        "Febuary",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    
    int sales[12];
    int sum {};
    
    for (int i = 0; i < 12; ++i)
    {
        cout << "Enter the sales for " << months[i] << endl;
        cin >> sales[i];
    }
    for (int i = 0; i < 12; ++i)
    {
        sum += sales[i];
    }
    cout << "Total sales: " << sum << endl;
    
    return 0;
}
