#include "sales.h"
#include <iostream>

namespace SALES
{
void setSales(Sales& s, const double ar[], int n)
{
    int i = 0;
    double max, min, sum;
    if (n <= 0)
    {
        while(i < 4)
            s.sales[i++] = 0;
        s.max = 0;
        s.min = 0;
        s.average = 0;
        return;
    }
    max = min = sum = s.sales[0] = ar[0];
    ++i;
    while(i < 4 && i < n)
    {
        s.sales[i] = ar[i];
        max = s.sales[i] > max? s.sales[i]: max;
        min = s.sales[i] < min? s.sales[i]: min;
        sum += s.sales[i];
        ++i;
    }
    s.max = max;
    s.min = min;
    s.average = sum / i;
    while(i < 4)
        s.sales[i++] = 0;
}

void setSales(Sales & s)
{
    using std::cout;
    using std::cin;
    using std::endl;
    
    double sale;
    int i = 0;
    double min, max, sum;
    cout << "Enter sales for quarters (q to stop).\n";
    
    if (!(cin >> s.sales[i]))
    {
        while(i < 4)
            s.sales[i++] = 0;
        s.max = 0;
        s.min = 0;
        s.average = 0;
        cin.clear();
        while(cin.get() != '\n');
        
        return;
    }
    ++i;
    min = max = sum = s.sales[0];
    
    while(i < 4 && cin >> s.sales[i])
    {
        max = s.sales[i] > max? s.sales[i]: max;
        min = s.sales[i] < min? s.sales[i]: min;
        sum += s.sales[i];
        ++i;
    }
    s.max = max;
    s.min = min;
    s.average = sum / i;
    while(i < 4)
        s.sales[i++] = 0;
    if (!cin)
    {
        cin.clear();
        while(cin.get() != '\n');
        return;
    }
}

void showSales(const Sales& s)
{
    using std::cout;
    using std::endl;
    cout << "Sales for quarters: ";
    for (int i = 0; i < 4; ++i)
    {
        cout << s.sales[i] << ' ';
    }
    cout << endl;
    cout << "Max: " << s.max << endl;
    cout << "Min: " << s.min << endl;
    cout << "Average: " << s.average << endl;
    return;
}

}

