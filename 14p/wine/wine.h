#ifndef WINE_
#define WINE_
#include <string>
#include <valarray>

namespace mns
{
template<typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair(const T1& a, const T2& b): first(a), second(b) { } 
};

using ArrayInt = std::valarray<int>;
using PairArray = Pair<ArrayInt, ArrayInt>;

class Wine
{
    std::string label;
    PairArray years_bottles;
    int years;
public:
    Wine(const char * , int , const int [],
         const int []);
    Wine(const char * = "label_name", int = 0);
    void GetBottles();
    const std::string& Label() const;
    int sum() const;
    void Show() const;
};



}

#endif
