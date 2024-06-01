#include <iostream>
#include <fstream>
#include<string >
#include <set>

int main() {
	std::ifstream f("name.txt");
	std::set <std::string> names;

	std::string line;
	while (std::getline(f, line)) {
		names.insert(line);
	}

	for (auto i : names) {
		std::cout << i << '\n';
	}
}