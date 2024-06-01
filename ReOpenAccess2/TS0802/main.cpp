#include <iostream>
#include <vector>

int main() {
	int m1, n1, m2, n2;

	std::cin >> m1 >> n1 >> m2 >> n2;
	

	std::vector<std::vector<int>> arr1(m1, std::vector<int>(n1, 0));
	std::vector<std::vector<int>> arr2(m2, std::vector<int>(n2, 0));

	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n1; j++) {
			std::cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++) {
			std::cin >> arr2[i][j];
		}
	}

	if (n1 != m2) {
		std::cout << "Matrix multiplication failed.\n";
		return 0;
	}

	std::vector<std::vector<int>> result(m1, std::vector<int>(n2, 0));

	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2; j++) {
			int sum = 0;

			for (int k = 0; k < n1; k++) {
				sum += arr1[i][k] * arr2[k][j];
			}

			result[i][j] = sum;
		}
	}
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < n2 - 1; j++) {
			std::cout << result[i][j] << ' ';
		}
		std::cout << result[i][n2 - 1];
		if (i != m1 - 1) std::cout << '\n';
	}

}