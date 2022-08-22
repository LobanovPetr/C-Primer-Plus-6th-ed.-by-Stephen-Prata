#ifndef MEAN_
#define MEAN_

#include <iostream>
#include <stdexcept>
#include <cmath>

class Ancestor: public std::logic_error
{
public:
    double v1, v2;
    Ancestor(double x = 0, double y = 0, const char * s = "ligic error"): v1(x), v2(y), std::logic_error(s) {}
    virtual void prob() = 0;
};

class bad_hmean : public Ancestor
{
public:
    bad_hmean(double x = 0, double y = 0): Ancestor(x, y) { }
    virtual void prob() { std::cout << "hmean(x = " << v1 << ", y = " << v2 <<") : x = -y\n"; }
};

class bad_gmean : public Ancestor
{
public:
    bad_gmean(double x = 0, double y = 0): Ancestor(x, y) { }
    virtual void prob() { std::cout << "gmean(x = " << v1 << ", y = " << v2 <<") : x or y is negative\n";}
};


inline double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a, b);
    return 2. * a * b / (a + b);
}

inline double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}
#endif
