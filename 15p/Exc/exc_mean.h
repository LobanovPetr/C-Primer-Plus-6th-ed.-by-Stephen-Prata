#ifndef MEAN_
#define MEAN_

#include <iostream>
#include <stdexcept>
#include <cmath>
class bad_hmean : public std::logic_error
{
public:
    bad_hmean() : std::logic_error("hmean(), invalid arguments: a = -b") { }
};

class bad_gmean : public std::logic_error
{
public:
    bad_gmean() : std::logic_error("gmean(), arguments should be >= 0") { }
};


inline double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2. * a * b / (a + b);
}

inline double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}
#endif
