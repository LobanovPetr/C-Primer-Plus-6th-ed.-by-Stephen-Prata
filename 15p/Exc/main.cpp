#include "exc_mean.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    try
    {
        hmean(3.5, -3.5);
    }
    catch(std::logic_error& exc)
    {
        cout << exc.what() << endl;
    }
    catch(...)
    {
        cout << "Unpredictable error\n";
    }
    
    try
    {
        gmean(-2, -5);
    }
    catch (std::logic_error& exc)
    {
        cout << exc.what() << endl;
    }
    catch(...)
    {
        cout << "Unpredictable error\n";
    }
    return 0;
}
