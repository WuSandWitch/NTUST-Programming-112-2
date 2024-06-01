#include "Polynomial.h"

Polynomial::Polynomial() {
	this->coeffceints = {};
	this->size = 0;
}

Polynomial::Polynomial(double* param, int size) {
	this->coeffceints = {  };
	for (int i = 0; i < size; i++) {
		this->coeffceints.push_back(param[i]);
	}
	this->size = size;
}

Polynomial::Polynomial(const Polynomial& poly) {
	this->coeffceints = poly.coeffceints;
	this->size = poly.size;
}

int Polynomial::mySize() const {
	int zeroCount = 0;
	for (int i = 0; i < size; i++) {
		if (coeffceints[size - 1 - i] == 0) zeroCount++;
		else break;
	}
	return size - zeroCount;
}

void Polynomial::operator=(const Polynomial& poly) {
	this->size = poly.size;
	this->coeffceints = poly.coeffceints;
}

double Polynomial::operator[](int index) const {
	return coeffceints[index];
}

double& Polynomial::operator[](int index) {
	if (index >= mySize()) {
		coeffceints.resize(index + 1);
		size = index + 1;
	}
	return coeffceints[index];
}

Polynomial Polynomial::operator+(const Polynomial& poly) {
	int size1 = mySize();
	int size2 = poly.mySize();

	int newSize = std::max(size1, size2);
	
	Polynomial result;
	result.coeffceints.resize(newSize);
	result.size = newSize;

	for (int i = 0; i < newSize; i++) {
		double sum = 0;
		if (i < size1) sum += coeffceints[i];
		if (i < size2) sum += poly.coeffceints[i];
		result.coeffceints[i] = sum;
	}
	
	return result;
}

Polynomial Polynomial::operator+(const double& n) {
	coeffceints[0] += n;
	return *this;
}

Polynomial Polynomial::operator-(const Polynomial& poly) {
	int size1 = mySize();
	int size2 = poly.mySize();

	int newSize = std::max(size1, size2);

	Polynomial result;
	result.coeffceints.resize(newSize);
	result.size = newSize;

	for (int i = 0; i < newSize; i++) {
		double sum = 0;
		if (i < size1) sum += coeffceints[i];
		if (i < size2) sum -= poly.coeffceints[i];
		result.coeffceints[i] = sum;
	}

	return result;
}

Polynomial Polynomial::operator-(const double& n) {
	Polynomial result;
	result.coeffceints = coeffceints;
	result.size = size;

	result.coeffceints[0] -= n;
	return result;
}

Polynomial Polynomial::operator*(const Polynomial& poly) {
	int size1 = mySize();
	int size2 = poly.mySize();

	int newSize = (size1 - 1) * (size2 - 1);

	Polynomial result;
	result.coeffceints.resize(newSize);
	result.size = newSize;

	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			result.coeffceints[i + j] += coeffceints[i] * poly.coeffceints[j];
		}
	}

	return result;
}

Polynomial Polynomial::operator*(const double& n) {
	Polynomial result;
	result.coeffceints = coeffceints;
	result.size = size;

	for (int i = 0; i < result.mySize(); i++) {
		result.coeffceints[i] *= n;
	}
	return result;
}

double evaluate(const Polynomial& poly, const double& var) {
	double sum = 0;

	for (int i = 0; i < poly.mySize(); i ++) {
		sum += poly[i]*pow(var, i);
	}

	return sum;
}

Polynomial operator+(double n, Polynomial poly) {
	poly.coeffceints[0] += n;
	return poly;
}
Polynomial operator-(double n, Polynomial poly) {
	Polynomial result;
	result.coeffceints = poly.coeffceints;
	result.size = poly.mySize();

	for (int i = 0; i < result.mySize(); i++) {
		result.coeffceints[i] *= -1;
	}

	poly.coeffceints[0] += n;
	return result;
}
Polynomial operator*(double n, Polynomial poly) {
	Polynomial result = poly;

	for (int i = 0; i < result.mySize(); i++) {
		result.coeffceints[i] *= n;
	}
	return result;
}