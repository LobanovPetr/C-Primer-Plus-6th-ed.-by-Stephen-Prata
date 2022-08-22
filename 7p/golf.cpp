// prog asks user to enter 10 results of golf
// and let to enter less than 10
// it shows game statistics

#include <iostream>
using namespace std;

int input(int ar[]);
void show(const int ar[], int size);
double mean(const int ar[], int size);

int main()
{
    int ar[10];
    int size;
    size = input(ar);
    cout << "Results: ";
    show(ar, size);
    if (size > 0)
        cout << "Mean " << mean(ar, size) << endl;
    return 0;
}

int input(int ar[])
{
    int i = 0;
    while(i < 10 && cout << "Enter the " << i << " element: "  && cin >> ar[i++]);
    return i;
}

void show(const int ar[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << ar[i] << ' ';
    }
    cout << endl;
}

double mean(const int ar[], int size)
{
    double m = 0.;
    for (int i = 0; i < size; ++i)
    {
        m += ar[i];
    }
    return m/size;
}
