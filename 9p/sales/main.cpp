#include "sales.h"

int main()
{
    using namespace SALES;
    Sales s1, s2;
    double ar[] {0, 0, 0, 0};
    setSales(s1);
    setSales(s2, ar, 1);
    showSales(s1);
    showSales(s2);
    return 0;
}
