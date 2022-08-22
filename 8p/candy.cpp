// prog to operate a box with candy

#include <iostream>
#include <cstring>

struct CandyBar
{
    char name[30];
    double weight;
    int calorie;
};

void setBar(CandyBar&, const char * = "Milleniu Munch", double = 2.85, int = 350);
void showBar(std::ostream&, const CandyBar&);

int main()
{
    using std::cout;
    CandyBar bar;
    setBar(bar, "merci", 150., 15);
    showBar(cout, bar);
    return 0;
}

void setBar(CandyBar& bar, const char * str, double weight, int calorie)
{
    strcpy(bar.name, str);
    bar.weight = weight;
    bar.calorie = calorie;
    return;
}

void showBar(std::ostream& os, const CandyBar& bar)
{
    std::ios_base::fmtflags initial;
    initial = os.setf(std::ios_base::fixed);
    os.precision(3);
    os << bar.name << ' ' << bar.weight << ' ' << bar.calorie << '\n';
    os.setf(initial);
}
