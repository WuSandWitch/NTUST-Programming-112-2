#include <string>
#include <iostream>

class School {
private:
	
public:
	std::string name;
	float studentAmount;
	float studentAmountNextYear;

	School(std::string name,float studentAmount);
	void admissions(float amount);
	virtual void dropouts(float amount);
	void transfer(float amount, School& toSchool);

	friend std::ostream& operator<<(std::ostream& strm,const School& school);
};

class PrivateSchool : public School {

private:
	int dropCount;
public:
	PrivateSchool(std::string name, float studentAmount);
	void dropouts(float amount) override;

};

class PublicSchool : public School {
private:
	float growing_rate = 0.05;
public:
	PublicSchool(std::string name, float studentAmount);
	void apply_growth();
	void dropouts(float amount) override;
};