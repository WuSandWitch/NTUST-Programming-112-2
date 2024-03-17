#include <iostream>

int gcd(int m, int n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int main() {
    int m, n;
    while (std::cin >> m >> n) {
        std::cout << gcd(m, n) << '\n';
    }
}