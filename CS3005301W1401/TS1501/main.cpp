#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> nameSet;

    std::ifstream file("name.txt");

    std::string name;
    while (std::getline(file, name)) {
        nameSet.insert(name);
    }

    for (auto i: nameSet) {
        std::cout << i << '\n';
    }
}