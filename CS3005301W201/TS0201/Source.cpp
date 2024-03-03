#include <math.h>
#include <iostream>
#include <vector>

int main() {
    int    n;
    double num;

    while (std::cin >> n) {
        double              sum = 0;
        std::vector<double> arr;

        for (int i = 0; i < n; i++) {
            std::cin >> num;
            sum += num;
            arr.push_back(num);
        }

        double average            = sum / (double)n;
        // Calculate standard deviation
        double standard_deviation = 0;
        for (double i: arr) {
            standard_deviation += (i - average) * (i - average);
        }
        standard_deviation = sqrt(standard_deviation / n);

        std::cout << "Average:" << average << '\t';
        std::cout << "Standard deviation:" << standard_deviation << '\n';
    }
}