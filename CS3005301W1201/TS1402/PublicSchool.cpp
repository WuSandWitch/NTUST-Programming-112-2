#include "School.h"

PublicSchool::PublicSchool(std::string _name, float _amount): School(_name, _amount) {
}

PublicSchool::~PublicSchool() {
}

void PublicSchool::dropouts(float amount) {
    float studentAmountNextYear = getStudentAmountNextYear();
    float studentAmount         = getStudentAmount();

    if (amount > studentAmount) {
        return;
    }
    setStudentAmount(studentAmount - amount);
    if (amount > 100) {
        setStudentAmountNextYear(int(studentAmountNextYear * (1 - getting_rate)));
    }
}

void PublicSchool::apply_growth() {
    float amount = getStudentAmountNextYear();
    setStudentAmountNextYear(int(amount + getting_rate * amount));
}