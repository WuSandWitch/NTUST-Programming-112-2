#include "School.h"

PublicSchool::PublicSchool(std::string name, float amount) : School(name, amount) {};

void PublicSchool::apply_growth() {
	studentAmountNextYear += growing_rate * studentAmountNextYear;
}

void PublicSchool::dropouts(float amount) {
	if (amount > studentAmount) return;
	studentAmount -= amount;
	
	if (amount < 100) return;

	studentAmountNextYear = int(studentAmountNextYear * 0.95);
}