#include <iostream>
#include <string>
#include <vector>

void add(std::string n1, std::string n2, bool neg) {
    std::string num1 = n1;
    std::string num2 = n2;

    if (num1.length() < num2.length())
        std::swap(num1, num2);

    std::string result = "";
    int         carry  = 0;

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    for (int i = 0; i < num1.length(); i++) {
        int temp = carry;
        temp += (num1[i] - '0');
        if (i < num2.length())
            temp += (num2[i] - '0');
        result += ((temp % 10) + '0');
        carry = temp / 10;
    }

    if (carry)
        result += (carry + '0');

    std::reverse(result.begin(), result.end());

    if (neg)
        std::cout << '-';
    std::cout << result << '\n';
}

void sub(std::string n1, std::string n2, bool neg) {
    std::string num1 = n1;
    std::string num2 = n2;

    bool resultNeg = false;

    if ((num1.length() < num2.length()) || ((num1.length() == num2.length()) && num1.compare(num2) == -1)) {
        std::swap(num1, num2);
        resultNeg = true;
    }

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    std::string result = "";

    int borrow = 0;
    for (int i = 0; i < num1.length(); i++) {
        int diff = (num1[i] - '0');
        if (i < num2.length()) {
            diff -= (num2[i] - '0');
        }

        if (diff < 0) {
            borrow = 1;
            num1[i + 1]--;
            diff += 10;
        } else {
            borrow = 0;
        }

        result += (diff + '0');
    }

    bool start      = false;
    int  startIndex = 0;

    for (int i = result.length() - 1; i >= 1; i--) {
        if (result[i] != '0' || start) {
            start = true;
        } else {
            startIndex++;
        }
    }

    std::reverse(result.begin(), result.end());

    if (startIndex)
        result.erase(result.begin(), result.begin() + startIndex);

    if (resultNeg ^ neg && result.length() != 0 && (!(result.length() == 1 && result[0] == '0')))
        std::cout << '-';
    std::cout << result << '\n';
}

void mul(std::string n1, std::string n2, bool neg) {
    std::string num1 = n1;
    std::string num2 = n2;

    if ((num1.length() < num2.length()) || (num1.length() == num2.length()) && num1.compare(num2) == -1)
        std::swap(num1, num2);

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    std::vector<int> ans(num1.length() + num2.length() + 2, 0);

    for (int i = 0; i < num1.length(); i++) {
        for (int j = 0; j < num2.length(); j++) {
            int temp = ans[i + j] + (num1[i] - '0') * (num2[j] - '0');

            ans[i + j] = temp % 10;
            ans[i + j + 1] += (temp / 10);
        }
    }

    bool        start  = false;
    std::string result = "";
    for (int i = num1.length() + num2.length() + 2 - 1; i > 0; i--) {
        if (ans[i] != 0) {
            start = true;
        }

        if (start) {
            result += (ans[i] + '0');
        }
    }
    result += (ans[0] + '0');

    if (neg && result.length() != 0 && (!(result.length() == 1 && ans[0] == 0)))
        std::cout << '-';
    std::cout << result << '\n';
}

int main() {
    std::string num1, num2;

    while (std::cin >> num1 >> num2) {
        bool neg1 = num1[0] == '-';
        bool neg2 = num2[0] == '-';

        if (neg1 == false && neg2 == false) {
            add(num1, num2, false);
            sub(num1, num2, false);
            mul(num1, num2, false);
        } else if (neg1 == false && neg2 == true) {
            num2.erase(num2.begin());
            sub(num1, num2, false);  // num1 - |num2|
            add(num1, num2, false);  // num1 + |num2|
            mul(num1, num2, true);
        } else if (neg1 == true && neg2 == false) {
            num1.erase(num1.begin());
            sub(num1, num2, true);  // |num1| - num2
            add(num1, num2, true);  // |num1| + num2
            mul(num1, num2, true);
        } else {
            num1.erase(num1.begin());
            num2.erase(num2.begin());
            add(num1, num2, true);  // |num1| + |num2|
            sub(num1, num2, true);  // |num1| - |num2|
            mul(num1, num2, false);
        }
    }
}
