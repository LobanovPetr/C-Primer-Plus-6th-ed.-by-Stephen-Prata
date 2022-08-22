#include "workerMultiInher.h"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

void choices();

int main()
{
    char ch;
    Worker* w[6] = {new Waiter("Petr", 0, 10), new Singer("Georgi", 1, 3), new SingerWaiter("Toly", 2, 11, 4)};
    for (int i = 0; i < 3; ++i)
    {
        w[i]->Show();
    }
    for (int i = 3; i < 6; ++i)
    {
        choices();
        cin >> ch;
        while(cin.get() != '\n');
        switch (ch) {
            case 'w':
                w[i] = new Waiter();
                break;
            case 's':
                w[i] = new Singer();
                break;
            case 'r':
                w[i] = new SingerWaiter();
                break;
            default:
                w[i] = new Waiter();
                break;
        }
        w[i]->Set();
    }
    for (int i = 0; i < 6; ++i)
    {
        w[i]->Show();
    }
}

void choices()
{
    cout << "w - waiter\n";
    cout << "s - singer\n";
    cout << "r - singerwaiter\n";
}
