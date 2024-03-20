#include "Point.h"

#include <algorithm>

void Point::Set(int x, int y) {
    arr = {};
    arr.push_back(x);
    arr.push_back(y);
}

void Point::Move(int horizontal, int vertical) {
    arr[0] += horizontal;
    arr[1] += vertical;
}

void Point::Rotate() {
    std::swap(arr[0], arr[1]);
    if ((arr[0] >= 0 && arr[1] >= 0) || (arr[0] <= 0 && arr[1] <= 0))
        arr[1] *= -1;
    else if ((arr[0] >= 0 && arr[1] <= 0) || (arr[0] <= 0 && arr[1] >= 0))
        arr[1] *= -1;
}

void Point::Reflect() {
    arr[0] *= -1;
    arr[1] *= -1;
}

const float Point::GetHorizontal() {
    if (arr[0] == 0)
        return 0;
    return arr[0];
}

const float Point::GetVertical() {
    if (arr[1] == 0)
        return 0;
    return arr[1];
}

Point::Point() {
    arr = {0, 0};
}

Point::Point(Point& target) {
    arr = target.arr;
}

Point::~Point() {
    arr = {};
}