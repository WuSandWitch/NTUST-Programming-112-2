#pragma once
#include <iostream>
#include <vector>

class VecNf {
    private:
    std::vector<double> elements;
    int                 count;

    public:
    VecNf() {
        this->count = 0;
    }
    VecNf(float* target, int cnt) {
        for (int i = 0; i < cnt; i++) {
            this->elements.push_back(target[i]);
        }

        this->count = cnt;
    }
    VecNf(const VecNf& rhs) {
        this->elements = rhs.elements;
        this->count    = rhs.count;
    }
    int Size() {
        return count;
    }
    void operator=(const VecNf rhs) {
        this->elements = rhs.elements;
        this->count    = rhs.count;

        std::cout << "ASSIGNMENT!!!\n";
    }

    double& operator[](int index) {
        if (index + 1 > count) {
            elements.resize(index + 1);
            count = index + 1;
        }

        return elements[index];
    }

    VecNf operator+(const VecNf rhs) {
        VecNf ans;

        if (this->count != rhs.count) {
            std::cout << "dimensions inconsistent\n";
        } else {
            ans.elements.resize(count);
            ans.count = count;

            for (int i = 0; i < count; i++) {
                ans.elements[i] = elements[i] + rhs.elements[i];
            }
        }
        return ans;
    }

    VecNf operator-(const VecNf rhs) {
        VecNf ans;

        if (this->count != rhs.count) {
            std::cout << "dimensions inconsistent\n";
        } else {
            ans.elements.resize(count);
            ans.count = count;

            for (int i = 0; i < count; i++) {
                ans.elements[i] = elements[i] - rhs.elements[i];
            }
        }
        return ans;
    }

    double operator*(const VecNf rhs) {
        double ans = 0;

        if (this->count != rhs.count) {
            std::cout << "dimensions inconsistent\n";
        } else {
            for (int i = 0; i < count; i++) {
                ans += elements[i] * rhs.elements[i];
            }
        }
        return ans;
    }

    friend VecNf operator*(const double lhs, const VecNf rhs) {
        VecNf ans(rhs);

        for (int i = 0; i < rhs.count; i++) {
            ans[i] *= lhs;
        }

        return ans;
    }
};