#include <ctype.h>

#include <algorithm>
#include <iostream>
#include <string>

struct BigInt {
    std::string s   = "";
    int         len = 0;
    void        set_length() {
        this->len = this->s.length();
    }
    // Check if member "s" is numeric
    bool is_numeric() {
        for (int i = 0; i < this->s.length(); i++) {
            if (!isdigit(this->s[i])) {
                return false;
            }
        }
        return true;
    }
};

BigInt Add(const BigInt& lhs, const BigInt& rhs) {
    // Get the longer number length
    int max_len = 0;
    if (lhs.len > rhs.len)
        max_len = lhs.len;
    else
        max_len = rhs.len;

    // Reverse two variable to calculate from last digit
    std::string reversed_lhs = lhs.s;
    reverse(reversed_lhs.begin(), reversed_lhs.end());
    std::string reversed_rhs = rhs.s;
    reverse(reversed_rhs.begin(), reversed_rhs.end());

    std::string reversed_result = "";
    int         carry           = 0;

    for (int i = 0; i < max_len; i++) {
        // Sum two digit and carry
        int sum = carry;
        if (i < reversed_lhs.length())
            sum += reversed_lhs[i] - '0';
        if (i < reversed_rhs.length())
            sum += reversed_rhs[i] - '0';

        // Append sum to reversed result
        reversed_result += std::to_string(sum % 10);
        // Update carry
        carry = sum / 10;
    }
    // Append final carry to last digit
    if (carry != 0) {
        reversed_result += std::to_string(carry);
    }

    // Reverse back to the result and create struct
    reverse(reversed_result.begin(), reversed_result.end());
    BigInt result;
    result.s = reversed_result;
    result.set_length();

    return result;
}

int main() {
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        BigInt a, b;

        std::cin >> a.s;
        std::cin >> b.s;

        if ((!a.is_numeric()) || (!b.is_numeric())) {
            std::cout << "Not a valid number, please try again.\n";
            continue;
        }

        a.set_length();
        b.set_length();

        BigInt result = Add(a, b);

        std::cout << result.s << '\n';
    }
}