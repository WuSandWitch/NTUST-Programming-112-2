#include <math.h>

#include <iostream>
#include <string>

int main() {
    std::string input;

    while (std::cin >> input) {
        int n     = ceil(sqrt(input.length()));
        int index = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Calculate index of matrix
                index = j * n + i;
                if (index >= input.length())
                    continue;

                std::cout << input[index];
            }
            std::cout << '\n';
        }
    }
}