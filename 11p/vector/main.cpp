#include "Vector.h"
#include <iostream>
#include <fstream>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    using Vector::Mode;
    using Vector::Vector;
    
    srand(time(NULL));
    
    std::ofstream out;
    out.open("towrite.txt");
    
    cout.setf(std::ios_base::fixed);
    cout.precision(3);
    Vector v;
    double distance, step;
    int angl;
    
    
    cout << "Enter the distance and length of steep.\n";
    cin >> distance >> step;
    while(v.magval() < distance)
    {
        angl = rand() % 360;
        Vector tmp(angl, step, Mode::Pol);
        v = v + tmp;
        out << v << ' ' << v.magval() << endl;
    }
    out.close();
    
    return 0;
}
