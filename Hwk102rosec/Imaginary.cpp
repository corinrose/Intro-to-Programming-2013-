#include "Imaginary.h"
#include <iostream>
#include <cmath>

using namespace std;

Imaginary::Imaginary(double aVal, double bVal)
{
    a = aVal;
    b = bVal;
}

Imaginary Imaginary::operator+(Imaginary x)
{
    Imaginary sum(a + x.a, b + x.b);
    return sum;
}

Imaginary Imaginary::operator-(Imaginary x)
{
    Imaginary difference(a - x.a, b - x.b);
    return difference;
}

Imaginary Imaginary::operator*(Imaginary x)
{
    Imaginary product((a*x.a-b*x.b), (a*x.b + x.a*b));
    return product;
}

Imaginary Imaginary::operator/(Imaginary x)
{
    Imaginary quotient((a*x.a + b*x.b)/(x.a*x.a + x.b*x.b), (a*x.b - b*x.a)/(x.a*x.a + x.b*x.b));
    return quotient;
}

Imaginary Imaginary::operator+(double x)
{
    Imaginary sum(a + x, b);
    return sum;
}

Imaginary Imaginary::operator-(double x)
{
    Imaginary difference(a - x, b);
    return difference;
}

Imaginary Imaginary::operator*(double x)
{
    Imaginary product(a*x, b*x);
    return product;
}

Imaginary Imaginary::operator/(double x)
{
    Imaginary quotient(a/x, b/x);
    return quotient;
}

double Imaginary::abs()
{
    double abs = sqrt(a*a + b*b);
    return abs;
}

Imaginary Imaginary::operator^(double x)
{
    Imaginary y(a, b);
    Imaginary result(a, b);
    for (int i = 1; i < x; i++)
        result = result*y;

    return result;
}

void Imaginary::print()
{
    if (a == 0)
        {
            cout << b << 'i' << endl;
            return;
        }

    if (b > 0)
        cout << a << '+' << b << 'i' << endl;
    else if (b < 0)
        cout << a << b << 'i' << endl;
    else if (b == 0)
        cout << a << endl;
}

void Imaginary::printPolar()
{
    double r = sqrt(a*a + b*b);
    double sin = b/r;
    double angle = asin(sin);

    cout << r << "cis(" << angle/M_PI << "pi)" << endl;
}
