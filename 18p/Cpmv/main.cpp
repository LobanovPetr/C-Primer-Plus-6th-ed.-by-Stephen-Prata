#include "Cpmv.h"

int main()
{
    Cpmv one("one", "hi");
    one.Display();
    Cpmv two = one;
    one.Display();
    two.Display();
    Cpmv three(one + two);
    return 0;
}
