#include <iostream>
#include "imaginary.h"

using namespace std;

void showOff(Imaginary x, Imaginary y, int power)
{
    cout << "x     = ";
    x.print();

    cout << "y     = ";
    y.print();

    cout << "x + y = ";
    (y+x).print();

    cout << "x - y = ";
    (y-x).print();

    cout << "xy    = ";
    (y*x).print();

    cout << "x/y   = ";
    (x/y).print();

    cout << "|x|   = " << x.abs() << endl;
    cout << "|y|   = " << y.abs() << endl;

    cout << "x^" << power << "   = ";
    (x^power).print();
    cout << "y^" << power << "   = ";
    (y^power).print();

    cout << "x in polar form: ";
    x.printPolar();

    cout << "y in polar form: ";
    y.printPolar();
}

int main()
{
    int power = 5;

    Imaginary x(0,1);

    Imaginary y(1,0);

    showOff(x, y, power);
}
