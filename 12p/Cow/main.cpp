#include "cow.h"

using spc::Cow;

int main()
{
    Cow a;
    Cow b("Hello", "Dancing", 100);
    Cow c(b);
    
    a.ShowCow();
    b.ShowCow();
    c.ShowCow();
    
    a = b;
    a.ShowCow();
}
