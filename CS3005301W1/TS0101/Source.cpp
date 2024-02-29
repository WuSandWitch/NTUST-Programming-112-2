#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
	double n, r, guess, previous;
	while (cin >> n) {
		previous = n / 2;
		r = n / previous;
		guess = (previous + r) / 2;

		while (abs(guess - previous) >= 0.01) {
			previous = guess;
			r = n / guess;
			guess = (guess + r) / 2;
		}
		cout << fixed << setprecision(2) << guess << endl;
	}
}