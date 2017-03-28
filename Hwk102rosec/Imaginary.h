#ifndef IMAGINARY_H
#define IMAGINARY_H


class Imaginary
{
    private:
        double a;
        double b;
    public:
        Imaginary(double aVal, double bVal);

        void print(); // prints number in a+bi form

        void printPolar(); // prints number in polar form, kind of gross...

        // operations with two complex numbers
        Imaginary operator+(Imaginary x);
        Imaginary operator-(Imaginary x);
        Imaginary operator*(Imaginary x);
        Imaginary operator/(Imaginary x);

        // operations with a complex and a real number
        Imaginary operator+(double x);
        Imaginary operator-(double x);
        Imaginary operator*(double x);
        Imaginary operator/(double x);

        double abs(); // absolute value of a complex number (how far it is from 0,0 on complex plane)

        Imaginary operator^(double x); // raising a complex num to a power
};

#endif // IMAGINARY_H
