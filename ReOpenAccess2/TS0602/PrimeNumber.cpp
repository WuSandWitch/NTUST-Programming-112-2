#include "PrimeNumber.h"


PrimeNumber::PrimeNumber() {
	this->value = 1;
}

PrimeNumber::PrimeNumber(int _value) {
	this->value = _value;
}

int PrimeNumber::get() {
	return value;
}


bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;

	for (int i = 3; i < n; i++) {
		if (n % i == 0) return false;
	}
	return true;
} 

// ++a
PrimeNumber& PrimeNumber::operator++() {
	int n = value + 1;

	while (!isPrime(n)) {
		n++;
	}
	
	this->value = n;
	return *this;
}

// a++
PrimeNumber PrimeNumber::operator++(int) {
	PrimeNumber tmp = *this;
	++* this;
	return tmp;
}

PrimeNumber& PrimeNumber::operator--() {
	if (value == 2) {
		this->value = 1;
		PrimeNumber result = PrimeNumber();
		return result;
	}

	int n = value - 1;

	while (!isPrime(n)) {
		n--;
	}

	this->value = n;
	return *this;
}
PrimeNumber PrimeNumber::operator--(int) {
	PrimeNumber tmp = *this;
	--* this;
	return tmp;
}
