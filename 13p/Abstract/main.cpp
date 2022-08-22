#include "Header.h"
#include <iostream>
using namespace mns;

int main()
{
    Base* B[] { new baseDMA("Black Star", -5), new lacksDMA("green", "Petr", 100), new hasDMA("CoolStyle", "Georgi", -2) };
    for (int i = 0; i < 3; ++i)
    {
        std::cout << (*B[i]) << std::endl;
        delete B[i];
    }
    
    return 0;
}
