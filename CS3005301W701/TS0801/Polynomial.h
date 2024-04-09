#pragma once
#include <stdlib.h>

#include <cmath>
#include <vector>

class Polynomial {
    public:
    int                 size;
    std::vector<double> coeffcients;
    Polynomial() {
        size = 0;
    }
    Polynomial(double* param, int size) {
        this->size = size;
        this->coeffcients.resize(size);
        for (int i = 0; i < size; i++) {
            coeffcients[i] = param[i];
        }
    }
    Polynomial(const Polynomial& target) {
        this->size        = target.size;
        this->coeffcients = target.coeffcients;
    }
    ~Polynomial() {
        this->coeffcients = {};
    }
    void operator=(const Polynomial& poly) {
        this->size        = poly.size;
        this->coeffcients = poly.coeffcients;
    }

    int mySize() const {
        int nonZero = 0;
        for (int i = 0; i < size; i++) {
            if (coeffcients[size - i - 1] != 0) {
                nonZero = i;
                break;
            }
        }
        return size - nonZero;
    }

    double operator[](int index) const {
        return coeffcients[index];
    }
    double& operator[](int index) {
        if (index >= mySize()) {
            this->coeffcients.resize(index + 1);
            this->size = index + 1;
        }
        return this->coeffcients[index];
    }

    Polynomial operator+(const Polynomial& target) {
        int size1 = size;
        int size2 = target.size;

        std::vector<double> coeffcientB = target.coeffcients;

        Polynomial result;
        result.coeffcients.resize(std::max(size1, size2));
        result.size = std::max(size1, size2);

        for (int i = 0; i < std::max(size1, size2); i++) {
            double current = 0;
            if (i < size1)
                current += coeffcients[i];
            if (i < size2)
                current += target.coeffcients[i];
            result.coeffcients[i] = current;
        }
        return result;
    }
    Polynomial operator+(const double& target) {
        Polynomial result;

        result.coeffcients = this->coeffcients;
        result.size        = this->size;

        result.coeffcients[0] += target;

        return result;
    }
    Polynomial operator-(const Polynomial& target) {
        int size1 = size;
        int size2 = target.size;

        std::vector<double> coeffcientB = target.coeffcients;

        Polynomial result;
        result.coeffcients.resize(std::max(size1, size2));
        result.size = std::max(size1, size2);

        for (int i = 0; i < std::max(size1, size2); i++) {
            double current = 0;
            if (i < size1)
                current += coeffcients[i];
            if (i < size2)
                current -= target.coeffcients[i];
            result.coeffcients[i] = current;
        }
        return result;
    }
    Polynomial operator-(const double& target) {
        Polynomial result;

        result.coeffcients = this->coeffcients;
        result.size        = this->size;

        result.coeffcients[0] -= target;

        return result;
    }
    Polynomial operator*(const Polynomial& target) {
        int size1 = size;
        int size2 = target.size;

        Polynomial result;
        result.size = this->size + target.size;
        result.coeffcients.resize(this->size + target.size);

        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                result.coeffcients[i + j] += this->coeffcients[i] * target.coeffcients[j];
            }
        }

        return result;
    }
    Polynomial operator*(const double& target) {
        Polynomial result;
        result.size        = this->size;
        result.coeffcients = this->coeffcients;

        for (int i = 0; i < size; i++) {
            result.coeffcients[i] *= target;
        }

        return result;
    }
};

double evaluate(const Polynomial& poly, const double& var) {
    double result = 0;
    for (int i = 0; i < poly.mySize(); i++) {
        result += pow(var, i) * poly[i];
    }
    return result;
}

Polynomial operator+(double constant, Polynomial poly) {
    Polynomial result;
    result.coeffcients = poly.coeffcients;
    result.size        = poly.size;

    result.coeffcients[0] += constant;
    return result;
}
Polynomial operator-(double constant, Polynomial poly) {
    Polynomial result;
    result.coeffcients = poly.coeffcients;
    result.size        = poly.size;

    for (int i = 0; i < result.size; i++) {
        result[i] *= -1;
    }
    result[0] += constant;
    return result;
}
Polynomial operator*(double constant, Polynomial poly) {
    Polynomial result;
    result.coeffcients = poly.coeffcients;
    result.size        = poly.size;

    for (int i = 0; i < result.size; i++) {
        result[i] *= constant;
    }
    return result;
}