#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	while (cin >> input) {
		if (input.length() < 10) {
			for (int i = 0; i < 10 - input.length(); i++) printf(" ");
		}

		cout << input << endl;
	}
}