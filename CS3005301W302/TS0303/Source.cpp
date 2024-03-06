#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string       X;
    unsigned long int M, N;
    std::string       C;

    while (std::cin >> X >> M >> N >> C) {
        std::string result = "";

        int decimal_point_index = -1;  // -1 for not found point
        // Finding decimal point
        for (int i = 0; i < X.length(); i++) {
            if (X[i] == '.') {
                decimal_point_index = i;
                break;
            }
        }

        if (decimal_point_index == -1) {
            // Decimal part
            result += X;
            if (N != 0)
                result += ".";
            for (int i = 0; i < N; i++)
                result += "0";

            // Text C part
            if (M - result.length() > 0) {
                for (int i = result.length(); i < M; i++) {
                    result = C + result;
                }
            }
            std::cout << result << '\n';
            continue;
        }

        // Integer part
        for (int i = 0; i < decimal_point_index; i++) {
            result += X[i];
        }
        // Decimal part
        if (N != 0)
            result += ".";
        for (int i = decimal_point_index + 1; i < decimal_point_index + N + 1; i++) {
            if (i >= X.length()) {
                result += "0";
            } else {
                result += X[i];
            }
        }
        // Text C part
        if (M - result.length() > 0) {
            for (int i = result.length(); i < M; i++) {
                result = C + result;
            }
        }
        std::cout << result << '\n';
    }
}