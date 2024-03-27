#include <iostream>
#include <string>

int charToQua(char bit) {
    switch (bit) {
        case 'V':
            return 0;
        case 'U':
            return 1;
        case 'C':
            return 2;
        case 'D':
            return 3;
    }
}

char quaToChar(int num) {
    return "VUCD"[num];
}

void add(std::string& num1, std::string& num2) {
    std::string result = "";
    int         carry  = 0;
    for (int i = 0; i < num2.length(); i++) {
        char bitA = num2[num2.length() - i - 1];
        char bitB = 'V';
        if (i < num1.length()) {
            bitB = num1[num1.length() - i - 1];
        }

        int numA = charToQua(bitA);
        int numB = charToQua(bitB);

        int sum = numA + numB + carry;
        carry   = sum > 3 ? 1 : 0;
        sum %= 4;

        result = quaToChar(sum) + result;
    }
    if (carry != 0)
        result = quaToChar(carry) + result;
    num2 = result;
}

void rightShift(std::string& num) {
    num = "V" + num.substr(0, num.length() - 1);
}

void leftShift(std::string& num) {
    num += "V";
}

void opeartion(std::string& num1, std::string& num2, char op) {
    if (op == 'N')
        return;

    if (op == 'R') {
        rightShift(num2);
    } else if (op == 'L') {
        leftShift(num2);
    } else if (op == 'A') {
        add(num1, num2);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cout << "COWCULATIONS OUTPUT\n";
    for (int i = 0; i < n; i++) {
        std::string num1, num2;
        std::cin >> num1;
        std::cin >> num2;

        char op;
        for (int j = 0; j < 3; j++) {
            std::cin >> op;
            opeartion(num1, num2, op);
        }
        std::string result;
        std::cin >> result;

        bool equal = result == num2;
        for (int i = 0; i < result.length() - num2.length(); i++) {
            if (std::string(i + 1, 'V') + num2 == result)
                equal = true;
        }

        if (equal)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    std::cout << "END OF OUTPUT\n";
}