#include "Complex.h"

#include <cmath>

Complex::Complex() {
    realValue      = 0;
    imaginaryValue = 0;
}
Complex::Complex(const Complex& target) {
    realValue      = target.realValue;
    imaginaryValue = target.imaginaryValue;
}

Complex::Complex(double r) {
    realValue      = r;
    imaginaryValue = 0;
}
Complex::Complex(double r, double i) {
    realValue      = r;
    imaginaryValue = i;
}

double Complex::real() {
    return realValue;
}
double Complex::imag() {
    return imaginaryValue;
}
double Complex::norm() {
    return sqrt(realValue * realValue + imaginaryValue * imaginaryValue);
}

double real(Complex c) {
    return c.realValue;
}
double imag(Complex c) {
    return c.imaginaryValue;
}
double norm(Complex c) {
    return sqrt(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue);
}
Complex Complex::operator+(Complex c) {
    return Complex(realValue + c.realValue, imaginaryValue + c.imaginaryValue);
}
Complex Complex::operator-(Complex c) {
    return Complex(realValue - c.realValue, imaginaryValue - c.imaginaryValue);
}
Complex Complex::operator*(Complex c) {
    double real  = realValue * c.realValue - imaginaryValue * c.imaginaryValue;
    double image = realValue * c.imaginaryValue + imaginaryValue * c.realValue;

    return Complex(real, image);
}
Complex Complex::operator/(Complex c) {
    Complex a = *this * Complex(c.realValue, -c.imaginaryValue);
    double  b = (c * Complex(c.realValue, -c.imaginaryValue)).realValue;

    a.realValue /= b;
    a.imaginaryValue /= b;

    return a;
}
Complex operator+(double d, Complex c) {
    return Complex(c.realValue + d, c.imaginaryValue);
}
Complex operator-(double d, Complex c) {
    return Complex(d - c.realValue, -c.imaginaryValue);
}
Complex operator*(double d, Complex c) {
    return Complex(c.realValue * d, c.imaginaryValue * d);
}
Complex operator/(double d, Complex c) {
    Complex a = d * Complex(c.realValue, -c.imaginaryValue);
    double  b = (c * Complex(c.realValue, -c.imaginaryValue)).realValue;

    a.realValue /= b;
    a.imaginaryValue /= b;

    return a;
}
bool operator==(Complex c1, Complex c2) {
    return c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue;
}

ostream& operator<<(ostream& strm, const Complex& c) {
    strm << c.realValue << " + " << c.imaginaryValue << "*i";
    return strm;
}
istream& operator>>(istream& strm, Complex& c) {
    char ignore;
    strm >> ignore >> ignore >> c.realValue >> ignore >> c.imaginaryValue >> ignore >> ignore;
    return strm;
}