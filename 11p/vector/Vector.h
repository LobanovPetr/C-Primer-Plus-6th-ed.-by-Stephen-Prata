#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>
namespace Vector
{

enum Mode {Rect, Pol};
class Vector
{
    Mode mode;
    union
    {
        struct
        {
            double x, y;
        } rect;
        struct
        {
            double ang, mag;
        } pol;
    };
public:
    Vector(double = 0, double = 0, Mode = Rect);
    Vector(const Vector&);
    const Vector& operator=(const Vector&);
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Vector operator*(double) const;
    Vector operator-() const;
    double xval() const;
    double yval() const;
    double angval() const;
    double magval() const;
    
    friend Vector operator*(double, const Vector&);
    friend std::ostream& operator<<(std::ostream&, const Vector&);
};

std::ostream& operator<<(std::ostream&, const Vector&);
Vector operator*(double, const Vector&);

}

#endif
