#include <iostream>
#include <string>
class School {
    public:
    School(std::string, float);
    ~School();

    void                 admissions(float amount);
    virtual void         dropouts(float amount);
    void                 transfer(float amount, School& toSchool);
    void                 setStudentAmount(float);
    void                 setStudentAmountNextYear(float);
    float                getStudentAmount();
    float                getStudentAmountNextYear();
    friend std::ostream& operator<<(std::ostream&, School const);

    private:
    std::string name;
    float       studentAmount;
    float       studentAmountNextYear;
};

class PrivateSchool: public School {
    public:
    PrivateSchool(std::string, float);
    ~PrivateSchool();
    void dropouts(float amount) override;

    private:
    int dropCount;
};

class PublicSchool: public School {
    public:
    PublicSchool(std::string, float);
    ~PublicSchool();
    void dropouts(float amount) override;
    void apply_growth();

    private:
    float getting_rate = 0.05;
};