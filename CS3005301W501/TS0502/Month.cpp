#include "Month.h"

#include <iostream>
#include <string>

std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Month::Month() {
    month = 1;
}

Month::Month(char first, char second, char third) {
    std::string monthStr = std::string(1, first) + second + third;

    for (int i = 0; i < 12; i++) {
        if (months[i] == monthStr) {
            month = i + 1;
            return;
        }
    }
    month = 1;
}

Month::Month(int monthInt) {
    month = monthInt;
    if (month < 1 || month > 12)
        month = 1;
}

Month::~Month() {
}

void Month::inputInt() {
    int monthInt;
    std::cin >> monthInt;
    if (monthInt < 1 || monthInt > 12) {
        month = 1;
        return;
    }
    month = monthInt;
}

void Month::inputStr() {
    char first, second, third;
    std::cin >> first >> second >> third;
    std::string monthStr = std::string(1, first) + second + third;

    for (int i = 0; i < 12; i++) {
        if (months[i] == monthStr) {
            month = i + 1;
            return;
        }
    }
    month = 1;
}

void Month::outputInt() {
    std::cout << month;
}

void Month::outputStr() {
    std::cout << months[month - 1];
}

Month Month::nextMonth() {
    return Month((month) % 12 + 1);
}
