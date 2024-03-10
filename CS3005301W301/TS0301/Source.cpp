#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
    std::string input;
    while (std::getline(std::cin, input)) {
        // Init the stringstream
        std::stringstream ss(input);
        ss >> std::noskipws;

        std::map<int, int, std::greater<int>> num_count;

        int  num;
        char ch;

        while (!ss.eof()) {
            ss >> num >> ch;

            if (num_count.count(num) > 0) {
                num_count[num]++;
            } else {
                num_count[num] = 1;
            }
        }

        std::cout << "N\tcount\n";
        for (auto i: num_count) {
            std::cout << i.first << '\t' << i.second << '\n';
        }
    }
}