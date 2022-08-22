#include <iostream>
#include "golf.h"

int fillplayers(golf [], int size);
void showplayers(golf [], int size);
void sethandicap(golf [], int idx, int hc);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    const int S = 10;
    
    golf g[S];
    int size, idx, value;
    size = fillplayers(g, S);
    showplayers(g, size);
    cout << "Enter an index of the player to change the name.\n";
    cin >> idx;
    if(!cin)
    {
        cout << "Bye.\n";
        return 0;
    }
    cout << "Enter the new value.\n";
    if(!cin)
    {
        cout << "Bye.\n";
        return 0;
    }
    cin >> value;
    sethandicap(g, idx, value);
    showplayers(g, size);
    
    return 0;
}

int fillplayers(golf g[], int size)
{
    using std::cout;
    int i = 0;
    cout << "Enter the players' names and handicaps (empty string to stop)\n";
    while (i < size)
    {
        if (!setgolf(g[i]))
            return i;
        ++i;
    }
    return i;
}

void showplayers(golf g[], int size)
{
    using std::cout;
    using std::endl;
    int i = 0;
    while(i < size)
    {
        cout << i + 1 << " player:\n";
        showgolf(g[i++]);
        cout << endl;
    }
    return;
}

void sethandicap(golf g[], int idx, int hc)
{
    handicap(g[idx], hc);
    return;
}
