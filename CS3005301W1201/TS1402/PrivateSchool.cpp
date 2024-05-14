#include "School.h"

PrivateSchool::PrivateSchool(std::string _name, float _amount): School(_name, _amount) {
    dropCount = 0;
}

PrivateSchool::~PrivateSchool() {
}

void PrivateSchool::dropouts(float amount) {
    if (amount > getStudentAmount())
        return;

    dropCount++;

    setStudentAmount(getStudentAmount() - amount);

    if (dropCount > 1) {
        setStudentAmountNextYear(getStudentAmountNextYear() - 100);
    }
}