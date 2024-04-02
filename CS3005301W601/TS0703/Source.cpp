#include <iostream>
#include <string>

std::string numbers[3][10] = {
  {" _ ", "   ", " _ ", " _ ", "   ", " _ ", " _ ", " _ ", " _ ", " _ "},
  {"| |", "  |", " _|", " _|", "|_|", "|_ ", "|_ ", "  |", "|_|", "|_|"},
  {"|_|", "  |", "|_ ", " _|", "  |", " _|", "|_|", "  |", "|_|", " _|"}};

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        for (int i = 0; i < 3; i++) {
            for (char ch: line) {
                if (!isdigit(ch))
                    continue;
                int num = ch - '0';
                std::cout << numbers[i][num];
            }
            std::cout << '\n';
        }
    }
}