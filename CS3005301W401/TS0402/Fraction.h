#ifndef Fraction_H
#define Fraction_H
#include <iomanip>
#include <iostream>
using namespace std;

class Fraction {
    private:
    int numerator;
    int denominator;

    public:
    void setNumerator(int nu);
    void setDenominator(int de);
    void getDouble();
    void outputReducedFraction();
};

#endif  // Fraction_H