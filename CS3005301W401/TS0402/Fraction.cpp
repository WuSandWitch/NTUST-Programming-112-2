#include "Fraction.h"

#include <iomanip>

int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

void Fraction::setNumerator(int nu) {
    numerator = nu;
}

void Fraction::setDenominator(int de) {
    denominator = de;
}

void Fraction::getDouble() {
    double result = (double)numerator / (double)denominator;
    if (result == numerator / denominator)
        cout << numerator / denominator << '\n';
    else
        cout << fixed << setprecision(6) << result << '\n';
}

void Fraction::outputReducedFraction() {
    int n = gcd(numerator, denominator);
    if (n == denominator)
        cout << numerator / n << '\n';
    else
        cout << numerator / n << '/' << denominator / n << '\n';
}
