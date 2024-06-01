#include "School.h"

PrivateSchool::PrivateSchool(std::string name, float amount) : School(name, amount) {
	dropCount = 0;
};

void PrivateSchool::dropouts(float amount) {
	if (amount > studentAmount) return;

	dropCount++;

	studentAmount -= amount;
	if (dropCount > 1) studentAmountNextYear -= 100;
}
