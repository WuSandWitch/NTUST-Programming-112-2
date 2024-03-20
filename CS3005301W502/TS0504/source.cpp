#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

bool checkSquare(std::vector<std::vector<int>> arr, int block_index) {
    int start_i = (block_index / 3) * 3;
    int start_j = (block_index % 3) * 3;

    std::map<int, int> number_count;
    for (int i = 1; i <= 9; i++) {
        number_count[i] = 0;
    }

    for (int i = start_i; i < start_i + 3; i++) {
        for (int j = start_j; j < start_j + 3; j++) {
            number_count[arr[i][j]] += 1;
        }
    }
    for (auto i: number_count) {
        if (i.second == 0 || i.second > 1)
            return false;
    }
    return true;
}

int main() {
    std::string       line;
    std::stringstream ss;

    char number, ch;

    while (std::getline(std::cin, line)) {
        ss << line;
        std::vector<std::vector<int>> arr(9, std::vector<int>(9));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 8; j++) {
                ss >> number >> ch;
                arr[i][j] = number - '0';
            }
            ss >> number;
            arr[i][8] = number - '0';
            std::getline(std::cin, line);
            ss << line;
        }
        bool pass = true;

        for (int i = 0; i < 9; i++) {
            if (!checkSquare(arr, i)) {
                pass = false;
                break;
            }
        }

        if (!pass)
            std::cout << "False\n";
        else
            std::cout << "True\n";
    }
}