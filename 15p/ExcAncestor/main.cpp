#include "exc_mean.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    double x, y;
    while(cout << "Enter the numbers\n", cin >> x >> y)
    {
        try
        {
            cout << "Gmean: " << gmean(x, y) << endl;
            cout << "Hmean: " << hmean(x, y) << endl;
        }
        catch(Ancestor& exc)
        {
            exc.prob();
            break;
        }
    }
    return 0;
}
