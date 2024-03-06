#include <math.h>

#include <iostream>

int main() {
    int year;

    while (std::cin >> year) {
        // Since n! <= 2^bit_count
        // => log2 n! <= bits_count
        unsigned long long int bits_count = pow(2, (year - 1900) / 10 + 2);

        int    n              = 1;
        double log2_factorial = 0;

        // Calculate the max log2 n!
        while (log2_factorial <= bits_count) {
            log2_factorial += log(n) / log(2);
            n++;
        }
        // Back the n
        if (log2_factorial != bits_count) {
            n -= 2;
        }

        std::cout << n << '\n';
    }
}