#include <iostream>
#include <map>
#include <string>
#include <vector>

bool check(std::map<char, std::vector<char>> dictionary, char destination, char target, std::vector<char> path = std::vector<char>()) {
    if (destination == target)
        return true;

    if (std::find(path.begin(), path.end(), destination) != path.end())
        return false;

    if (dictionary.find(destination) == dictionary.end())
        return false;

    bool canTranslate = false;

    path.push_back(destination);
    for (char i: dictionary[destination]) {
        if (check(dictionary, i, target, path))
            return true;
    }

    return false;
}

int main() {
    int dictionary_length, n;

    char        destination, target;
    std::string inputA, inputB;
    while (std::cin >> dictionary_length >> n) {
        if (dictionary_length == 0 && n == 0)
            break;

        std::map<char, std::vector<char>> dictionary;

        for (int i = 0; i < dictionary_length; i++) {
            std::cin >> destination >> target;
            if (dictionary.find(destination) == dictionary.end()) {
                dictionary[destination] = std::vector<char>();
            }
            dictionary[destination].push_back(target);
        }

        for (int i = 0; i < n; i++) {
            bool canTranslate = true;
            std::cin >> inputA >> inputB;

            if (inputA.length() != inputB.length()) {
                canTranslate = false;
            } else {
                for (int j = 0; j < inputA.length(); j++) {
                    if (!check(dictionary, inputA[j], inputB[j])) {
                        canTranslate = false;
                        break;
                    }
                }
            }

            if (canTranslate) {
                std::cout << "yes\n";
            } else {
                std::cout << "no\n";
            }
        }
    }
}