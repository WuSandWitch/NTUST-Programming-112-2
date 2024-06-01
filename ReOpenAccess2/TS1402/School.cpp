#include "School.h"

School::School(std::string name, float studentAmount) {
	this->name = name;
	this->studentAmount = studentAmount;
	this->studentAmountNextYear = studentAmount;
}


void School::admissions(float amount) {
	this->studentAmount += amount;
}

void School::dropouts(float amount) {
	if (studentAmount < amount) return;
	this->studentAmount -= amount;
}

void School::transfer(float amount, School& toSchool) {
	dropouts(amount);
	toSchool.admissions(amount);
}

std::ostream& operator<<(std::ostream& strm,const School& school) {
	strm << school.name << '\t' << school.studentAmount << '\t' << school.studentAmountNextYear;
	return strm;
}