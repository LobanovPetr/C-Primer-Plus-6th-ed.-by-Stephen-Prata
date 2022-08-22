#ifndef _SALES_
#define _SALES_
namespace SALES
{
const int QUARTERS = 4;
struct Sales
{
    double sales[QUARTERS];
    double average;
    double max;
    double min;
};
void setSales(Sales &, const double [], int n);
void setSales(Sales &);
void showSales(const Sales&);
}
#endif
