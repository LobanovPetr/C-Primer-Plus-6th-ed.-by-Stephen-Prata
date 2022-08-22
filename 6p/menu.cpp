//example of menu

#include <iostream>

using namespace std;

void showmenu(void);

int main()
{
    char ch;
    
    showmenu();
    
    while(cin >> ch, !(ch == 'c' || ch == 't' || ch == 'p' || ch == 'g'))
    {
        cout << "Please enter a c, p, t, or g: ";
    }
    
    switch (ch)
    {
        case 'c':
            cout << "Thank you for choicing latter c\n";
            break;
        case 't':
            cout << "Thank you for choicing latter t\n";
            break;
        case 'p':
            cout << "Thank you for choicing latter p\n";
            break;
        case 'g':
            cout << "Thank you for choicing latter g\n";
            break;
        default:
            break;
    }
    return 0;
}

void showmenu(void)
{
    cout << "Please enter one of the following choices:\n";
    cout << "c) carnivore \t p) pianist\n"
            "t) tree \t g) game\n";
}
