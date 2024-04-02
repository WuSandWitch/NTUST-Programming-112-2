#include <cmath>
#include <string>
using namespace std;

class Atoi {
    private:
    string beTrans;

    public:
    Atoi();
    Atoi(string s);
    void         SetString(string s);
    const string GetString();
    int          Length();
    bool         IsDigital();
    int          StringToInteger();
};

Atoi::Atoi() {
    beTrans = "";
}

Atoi::Atoi(string s) {
    beTrans = s;
}

void Atoi::SetString(string s) {
    beTrans = s;
}

const string Atoi::GetString() {
    return beTrans;
}

int Atoi::Length() {
    int l = beTrans.length();
    if (beTrans[0] == '-')
        l -= 1;
    return l;
}

bool Atoi::IsDigital() {
    for (auto i: beTrans) {
        if ((!isdigit(i)) && i != '-')
            return false;
    }
    return true;
}

int Atoi::StringToInteger() {
    int num = 0;
    for (int i = 0; i < beTrans.length(); i++) {
        char current = beTrans[beTrans.length() - i - 1];
        if (current == '-')
            num *= -1;
        else {
            num += (current - '0') * pow(10, i);
        }
    }
    return num;
}
