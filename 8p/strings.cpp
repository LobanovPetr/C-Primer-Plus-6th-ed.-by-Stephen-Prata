// example of polymorphism

#include <iostream>

using std::cout;
using std::endl;

int numOfСall = 0;

void show(const char * str);
void show(const char * str, int);

int main()
{
    show("Hello");
    show("Hello1");
    show("H", 5);
    return 0;
}

void show(const char * str)
{
    cout << str << endl;
    numOfСall++;
}

void show(const char * str, int x)
{
    for (int i = 0; i < numOfСall; ++i)
    {
        cout << str << endl;
    }
    numOfСall++;
}
