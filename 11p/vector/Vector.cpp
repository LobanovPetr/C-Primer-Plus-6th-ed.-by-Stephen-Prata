#include "Vector.h"
#include <iostream>
#include <cmath>

namespace Vector
{
using std::sin;
using std::cos;
using std::atan2;
using std::sqrt;

Vector::Vector(double fv, double sv, Mode md)
{
    rect.x = fv;
    rect.y = sv;
    if (md == Rect)
        mode = Rect;
    else if (md == Pol)
        mode = Pol;
    else
        std::cout << "Incorrect mode.\n";
}

Vector::Vector(const Vector& v)
{
    mode = v.mode;
    rect.x = v.rect.x;
    rect.y = v.rect.y;
}

const Vector& Vector::operator=(const Vector& v)
{
    mode = v.mode;
    rect.x = v.rect.x;
    rect.y = v.rect.y;
    return *this;
}

double Vector::xval() const
{
    if (mode == Rect)
        return rect.x;
    else
        return cos(pol.ang) * pol.mag;
}

double Vector::yval() const
{
    if (mode == Rect)
        return rect.y;
    else
        return sin(pol.ang) * pol.mag;
}

double Vector::angval() const
{
    if (mode == Pol)
        return pol.ang;
    else
        return atan2(rect.y, rect.x);
}

double Vector::magval() const
{
    if (mode == Pol)
        return pol.mag;
    else
        return sqrt(rect.x * rect.x + rect.y * rect.y);
}

Vector Vector::operator+(const Vector& v) const
{
    return Vector(xval() + v.xval(), yval() + v.yval());
}

Vector Vector::operator-(const Vector& v) const
{
    return Vector(xval() - v.xval(), yval() - v.yval());
}

Vector Vector::operator*(double n) const
{
    return Vector(xval() * n , yval() * n);
}

Vector operator*(double n, const Vector& v)
{
    return v * n;
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    os << '(' << v.xval() << ", " << v.yval() << ')';
    return os;
}

Vector Vector::operator-() const
{
    return Vector(-xval(), -yval());
}



}
