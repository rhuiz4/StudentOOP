#include <iostream>
#include <istream>
#include <iomanip>
#include "complex.h"

using namespace std;

bool operator== (const Complex& c1, const Complex& c2) {
<<<<<<< HEAD
    return (c1.get_real() == c2.get_real())
    && (c1.get_imag() == c2.get_imag());
=======
    return (c1.get_real() == c2.get_real()) && (c1.get_imag() == c2.get_imag());
>>>>>>> upstream/master
}

ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
<<<<<<< HEAD
    os << setprecision(10) << c.real << showpos
    << c.imag << "i" << noshowpos << endl;
=======
>>>>>>> upstream/master
    return os;
}


/*
 * Read a `Complex` number from an input stream.
 * */
istream& operator>> (istream& is, Complex& c) {
<<<<<<< HEAD
    is >> c.real >> c.imag;
=======
>>>>>>> upstream/master
    return is;
}

Complex::Complex(double real, double imag) : real(real), imag(imag)
    {}

<<<<<<< HEAD
Complex::Complex(double real, double imag)
: real{real}, imag{imag} {}


Complex::operator bool() const {
<<<<<<< HEAD
    return ((real != 0) || (imag != 0));
}

Complex& Complex::operator++() {
    ++real;
    return (*this);
}

Complex Complex::operator++(int) {
    Complex temp(*this);
    real++;
    return temp;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    Complex sum{c1.get_real() + c2.get_real(), c1.get_imag() + c2.get_imag()};
    return sum;
=======
    return true;
=======
    /*
Complex::operator bool() const {
    return (real != 0.0) && (imag != 0.0);
>>>>>>> upstream/master
}
*/

Complex& Complex::operator++() {
    return *this;
}

Complex Complex::operator++(int dummy) {
    return *this;
>>>>>>> upstream/master
}

Complex Complex::operator*(const int i) {
<<<<<<< HEAD
    Complex prod(real * 2, imag * 2);
    return prod;
=======
    return *this;
>>>>>>> upstream/master
}
