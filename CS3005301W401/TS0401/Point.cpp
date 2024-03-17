#include "Point.h"

#include <algorithm>

void Point::Set(int vertical, int horizontal) {
    this->vertical   = vertical;
    this->horizontal = horizontal;
}

void Point::Move(int x, int y) {
    this->vertical += x;
    this->horizontal += y;
}
void Point::Rotate() {
    std::swap(vertical, horizontal);
    if ((vertical >= 0 && horizontal >= 0) || (vertical <= 0 && horizontal <= 0))
        horizontal *= -1;
    else if ((vertical >= 0 && horizontal <= 0) || (vertical <= 0 && horizontal >= 0))
        horizontal *= -1;
}
