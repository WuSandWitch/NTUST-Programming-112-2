#include "PrimeNumber.h"

int PrimeNumber::get() {
    return value;
}

PrimeNumber::PrimeNumber() {
    value = 1;
}
PrimeNumber::PrimeNumber(int _value) {
    value = _value;
}
PrimeNumber& PrimeNumber::operator++() {
    int current = value + 1;

    while (true) {
        int i = current - 1;

        for (i; i > 1; i--) {
            if (current % i == 0) {
                break;
            }
        }

        if (i == 1) {
            value = current;
            break;
        } else {
            current++;
        }
    }

    return *this;
}
PrimeNumber PrimeNumber::operator++(int) {
    PrimeNumber backup = *this;

    int current = value + 1;

    while (true) {
        int i = current - 1;

        for (i; i > 1; i--) {
            if (current % i == 0) {
                break;
            }
        }

        if (i == 1) {
            value = current;
            break;
        } else {
            current++;
        }
    }

    return backup;
}
PrimeNumber& PrimeNumber::operator--() {
    int current = value - 1;

    while (true) {
        int i = current - 1;

        for (i; i > 1; i--) {
            if (current % i == 0) {
                break;
            }
        }
        if (i < 1) {
            value = 1;
            break;
        } else if (i == 1) {
            value = current;
            break;
        } else {
            current--;
        }
    }

    return *this;
}
PrimeNumber PrimeNumber::operator--(int) {
    PrimeNumber backup = *this;

    int current = value - 1;

    while (true) {
        int i = current - 1;

        for (i; i > 1; i--) {
            if (current % i == 0) {
                break;
            }
        }

        if (i < 1) {
            value = 1;
            break;
        } else if (i == 1) {
            value = current;
            break;
        } else {
            current--;
        }
    }

    return backup;
}