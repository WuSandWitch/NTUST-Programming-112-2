#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	long double r;
	long double PI = 3.14159265358979323846;
	while (cin >> r) {
		cout << fixed << setprecision(6) <<  PI * 4 / 3 * pow(r, 3) << endl;
	}
}