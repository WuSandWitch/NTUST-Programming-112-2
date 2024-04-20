#include <iostream>
#include <string>
#include <vector>

int main() {

	std::string input;
	std::vector<std::string> data;

	std::string result = "";
	int max_length = 0;


	while (std::cin >> input) {
		data.push_back(input);

		std::string reversed_input = input;
		std::reverse(reversed_input.begin(), reversed_input.end());

		auto f = std::find(data.begin(), data.end(), reversed_input);
	
		if (f == data.end()) {
			continue;
		}

		if (reversed_input.length() > max_length) {
			result = reversed_input;
			max_length = reversed_input.length();
		}
	}
	std::cout<<result << '\n';
}