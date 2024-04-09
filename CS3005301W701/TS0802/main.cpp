#include <iostream>
#include <vector>

int main() {
    int m1, n1, m2, n2;
    while (std::cin >> m1 >> n1 >> m2 >> n2) {
        std::vector<std::vector<int>> matrix1(m1, std::vector<int>(n1, 0));
        std::vector<std::vector<int>> matrix2(m2, std::vector<int>(n2, 0));

        int num;
        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n1; j++) {
                std::cin >> num;
                matrix1[i][j] = num;
            }
        }
        for (int i = 0; i < m2; i++) {
            for (int j = 0; j < n2; j++) {
                std::cin >> num;
                matrix2[i][j] = num;
            }
        }

        if (n1 != m2) {
            std::cout << "Matrix multiplication failed.\n";
            continue;
        }

        for (int i = 0; i < m1; i++) {
            for (int j = 0; j < n2; j++) {
                int sum = 0;
                for (int k = 0; k < m2; k++) {
                    sum += matrix1[i][k] * matrix2[k][j];
                }
                std::cout << sum;
                if (j != n2 - 1)
                    std::cout << ' ';
            }
            std::cout << '\n';
        }
    }
}