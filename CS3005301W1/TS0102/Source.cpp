#include <iostream>

using namespace std;

int main() {
	unsigned long long A;
	while (cin >> A) {
		unsigned long long hours = A / 3600;
		unsigned long long minutes = A / 60 % 60;
		unsigned long long seconds = A % 60;
		cout << hours << " hours " << minutes << " minutes and " << seconds << " seconds\n";
	}
}