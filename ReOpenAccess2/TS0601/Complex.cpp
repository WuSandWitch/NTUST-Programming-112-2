#include "Complex.h"


Complex::Complex() {
	this->realValue = 0;
	this->imaginaryValue = 0;
}

Complex::Complex(double r) {
	this->realValue = r;
	this->imaginaryValue = 0;
}

Complex::Complex(double r, double i) {
	this->realValue = r;
	this->imaginaryValue = i;
}


double Complex::real() { return this->realValue; };

double Complex::imag() { return this->imaginaryValue; };

double Complex::norm() {
	double n = sqrt(realValue * realValue + imaginaryValue * imaginaryValue);
	return n;
}

double real(Complex c) {
	return c.realValue;
}

double imag(Complex c) {
	return c.imaginaryValue;
}

double norm(Complex c) {
	double n = sqrt(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue);
	return n;
}

Complex Complex::operator+(Complex c) {
	return Complex(realValue + c.realValue, imaginaryValue + c.imaginaryValue);
}

Complex Complex::operator-(Complex c) {
	return Complex(realValue - c.realValue, imaginaryValue - c.imaginaryValue);
}

Complex Complex::operator*(Complex c) {
	double r = realValue * c.realValue - imaginaryValue * c.imaginaryValue;
	double i = realValue * c.imaginaryValue + imaginaryValue * c.realValue;
	return Complex(r, i);
}

Complex Complex::operator/(Complex c) {
	Complex a = c * Complex(c.realValue, -c.imaginaryValue);

	Complex result = *this * Complex(c.realValue, -c.imaginaryValue);
	result.realValue /= a.realValue;
	result.imaginaryValue /= a.realValue;

	return result;
}

Complex operator+(double d, Complex c) {
	return Complex(c.realValue + d, c.imaginaryValue);
}

Complex operator-(double d, Complex c) {
	return Complex(d - c.realValue, -c.imaginaryValue);
}

Complex operator*(double d, Complex c) {
	return Complex(d * c.realValue, d * c.imaginaryValue);
}

Complex operator/(double d, Complex c) {
	Complex a = c * Complex(c.realValue, -c.imaginaryValue);

	Complex result = Complex(d) * Complex(c.realValue, -c.imaginaryValue);
	result.realValue /= a.realValue;
	result.imaginaryValue /= a.realValue;

	return result;
}

bool operator==(Complex c1, Complex c2) {
	return c1.realValue == c2.realValue && c1.imaginaryValue == c2.imaginaryValue;
}

ostream& operator<<(ostream& strm, const Complex& c) {
	strm << c.realValue << " + " << c.imaginaryValue << "*i";
	return strm;
}

istream& operator>>(istream& strm, Complex& c) {
	char tmp;
	strm >> tmp >> tmp >> c.realValue >> tmp >> c.imaginaryValue >> tmp >> tmp;
	return strm;
}