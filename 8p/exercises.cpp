#include<iostream>
#include<string>

using std::cout;
using std::endl;
//inline void iqoute(int);
//inline void iqoute(double);
//inline void iqoute(string);
//
//void iqoute(int x)
//{
//    cout << '\"' << x << '\"'; << endl;
//    return;
//}
//
//void iqoute(double x)
//{
//    cout << '\"' << x << '\"'; << endl;
//    return;
//}
//
//void iqoute(string x)
//{
//    cout << '\"' << x << '\"'; << endl;
//    return;
//}

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

template<typename T>
T max(const T&, const T&);

template<>
box max(const box&, const box&);

int main()
{
    cout << max<double>(10, 11.) << endl;
    
    return 0;
}


template<typename T>
T max(const T& x, const T& y)
{
    return y < x ? x : y;
}

template<>
box max(const box& b1, const box& b2)
{
    return b2.volume < b1.volume ? b1 : b2;
}

//float
//float
//float &
//int
//double
