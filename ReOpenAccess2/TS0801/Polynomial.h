#include <vector>
#include <cmath>

class Polynomial {
private:
	
public:
	std::vector<double> coeffceints;
	int size;

	Polynomial();
	Polynomial(double* param, int size);
	Polynomial(const Polynomial& poly);

	int mySize() const;

	void operator=(const Polynomial& poly);

	double operator[](int index) const;
	double& operator[](int index);

	Polynomial operator+(const Polynomial& poly);
	Polynomial operator-(const Polynomial& poly);
	Polynomial operator*(const Polynomial& poly);

	Polynomial operator+(const double& n);
	Polynomial operator-(const double& n);
	Polynomial operator*(const double& n);
};

double evaluate(const Polynomial& poly, const double& var);

Polynomial operator+(double n, Polynomial poly);
Polynomial operator-(double n, Polynomial poly);
Polynomial operator*(double n, Polynomial poly);
