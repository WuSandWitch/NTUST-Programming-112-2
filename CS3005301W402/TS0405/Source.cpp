#include <algorithm>
#include <iostream>

int f(int n, int length = 1) {
    if (n == 1)
        return length;
    if (n % 2 == 0)
        return f(n / 2, length + 1);
    else
        return f(3 * n + 1, length + 1);
}

int main() {
    int i, j;
    while (std::cin >> i >> j) {
        std::cout << i << ' ' << j << ' ';
        if (i > j)
            std::swap(i, j);

        int max_length = 0;
        for (; i <= j; i++) {
            int length = f(i);
            if (length > max_length)
                max_length = length;
        }
        std::cout << max_length << '\n';
    }
}