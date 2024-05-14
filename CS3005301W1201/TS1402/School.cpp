#include "School.h"

School::School(std::string _name, float _amount) {
    name                  = _name;
    studentAmount         = _amount;
    studentAmountNextYear = _amount;
}

School::~School() {
}

void School::admissions(float amount) {
    studentAmount += amount;
}

void School::dropouts(float amount) {
    if (amount > getStudentAmount())
        return;

    studentAmount -= amount;
}

void School::transfer(float amount, School& toSchool) {
    if (amount > getStudentAmount())
        return;

    dropouts(amount);
    toSchool.admissions(amount);
}

void School::setStudentAmount(float amount) {
    studentAmount = amount;
}

void School::setStudentAmountNextYear(float amount) {
    studentAmountNextYear = amount;
}

float School::getStudentAmount() {
    return studentAmount;
}

float School::getStudentAmountNextYear() {
    return studentAmountNextYear;
}

std::ostream& operator<<(std::ostream& os, School const src) {
    os << src.name << '\t' << src.studentAmount << '\t' << src.studentAmountNextYear;
    return os;
}