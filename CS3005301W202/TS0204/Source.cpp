#include <ctype.h>
#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

// Check if a string is numeric
bool is_numeric(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        // Check if every character is digit
        if (!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int         n;                 // Row count
    std::string str1, str2, str3;  // Row string

    // Input till EOF
    while (std::cin >> n) {
        std::vector<std::string> col1;
        std::vector<std::string> col2;
        std::vector<std::string> col3;
        int                      max1 = 0, max2 = 0, max3 = 0;  // The max lenght of every column

        for (int i = 0; i < n; i++) {
            std::cin >> str1 >> str2 >> str3;

            col1.push_back(str1);
            col2.push_back(str2);
            col3.push_back(str3);

            // Get every column max length while inputing
            if (str1.length() > max1)
                max1 = str1.length();
            if (str2.length() > max2)
                max2 = str2.length();
            if (str3.length() > max3)
                max3 = str3.length();
        }

        // Add two space length if it's a numeric column
        if (is_numeric(str1))
            max1 += 2;
        if (is_numeric(str2))
            max2 += 2;
        if (is_numeric(str3))
            max3 += 2;

        // Format output
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < max1 - col1[i].length(); j++)
                std::cout << " ";
            std::cout << col1[i] << "|";
            for (int j = 0; j < max2 - col2[i].length(); j++)
                std::cout << " ";
            std::cout << col2[i] << "|";
            for (int j = 0; j < max3 - col3[i].length(); j++)
                std::cout << " ";
            std::cout << col3[i] << "\n";
        }
    }
}