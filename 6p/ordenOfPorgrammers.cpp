// there is a array of programmers
// you can call them by a name, title or a secret name
// or by prefernce of a programmer

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int strsize = 20;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int prefernce;
};

void menu(void);
void showBy(bop *, int);
void showByInt(bop *, int);

int main()
{
    
    bop programmers[3]
    {
        {"Petr", "Boss", "King", 0},
        {"Koly", "Boss", "CoolGuy", 2},
        {"Toly", "preBoss", "Gipsy", 2}
    };
    
    char ch;
    
    menu();
    cout << "Enter your choice: ";
    while(cin >> ch, ch != 'q')
    {
        switch (ch)
        {
            case 'a':
                showBy(programmers, 0);
                break;
            case 'b':
                showBy(programmers, 1);
                break;
            case 'c':
                showBy(programmers, 2);
                break;
            case 'd':
                showBy(programmers, 3);
                break;
            default:
                break;
        }
        cout << "Enter your choice: ";
    }
    cout << "Bye!\n";
    return 0;
}

void menu(void)
{
    cout << "a. display by name \t b. display by title\n"
            "c. display by bopname \t d. display by preference\n"
            "q. quit\n";
}

void showBy(bop * progs, int t)
{
    for (int i = 0; i < 3; ++i)
    {
        if (t != 3)
            showByInt(progs + i, t);
        else
            showByInt(progs + i, (progs + i)->prefernce);
    }
    return;
}

void showByInt(bop * prog, int c)
{
    switch (c)
    {
        case 0:
            cout << prog->fullname << endl;
            break;
        case 1:
            cout << prog->title << endl;
            break;
        case 2:
            cout << prog->bopname << endl;
            break;
        default:
            break;
    }
    return;
}
