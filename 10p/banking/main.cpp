#include "banking.h"

int main()
{
    Account Petr("Petr", "1234 4567", 100000.);
    Petr.show();
    Petr.deposit(100.);
    Petr.show();
    Petr.withdraw(5000.);
    Petr.show();
    return 0;
}
