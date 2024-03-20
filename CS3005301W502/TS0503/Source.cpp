#include <ctype.h>

#include <iostream>
#include <string>
#include <vector>

typedef struct {
    char firstName[25];
    char lastName[30];
    char phone[15];
} StRec;

std::vector<StRec> records;

bool checkInput(std::string firstName, std::string lastName, std::string phone) {
    if (firstName.length() > 25 || lastName.length() > 30 || phone.length() > 15) {
        return false;
    }
    for (int i = 0; i < phone.length(); i++) {
        if (!isdigit(phone[i]))
            return false;
    }
    return true;
}

bool checkExist(std::string firstName, std::string lastName, std::string phone) {
    for (StRec i: records) {
        if (i.firstName == firstName && i.lastName == lastName && i.phone == phone)
            return true;
    }
    return false;
}

void printRecords() {
    if (records.size() == 0) {
        std::cout << "Print Error\n";
        return;
    }
    for (auto i: records) {
        std::cout << i.firstName << ' ' << i.lastName << ' ' << i.phone << '\n';
    }
}

void deleteRecord() {
    std::string firstName, lastName, phone;
    std::cin >> firstName >> lastName >> phone;

    if (!checkInput(firstName, lastName, phone)) {
        std::cout << "Input Error\n";
        return;
    }

    if (!checkExist(firstName, lastName, phone)) {
        std::cout << "Delete Error\n";
        return;
    }

    for (int i = 0; i < records.size(); i++) {
        if (records[i].firstName == firstName && records[i].lastName == lastName && records[i].phone == phone) {
            records.erase(records.begin() + i);
            return;
        }
    }
}

void searchRecord() {
    std::string firstName, lastName, phone;
    std::cin >> firstName >> lastName >> phone;

    if (!checkInput(firstName, lastName, phone)) {
        std::cout << "Input Error\n";
        return;
    }

    for (int i = 0; i < records.size(); i++) {
        if (records[i].firstName == firstName && records[i].lastName == lastName && records[i].phone == phone) {
            std::cout << i << '\n';
            return;
        }
    }
    std::cout << "Search Error\n";
}

void insertRecord() {
    std::string firstName, lastName, phone;
    std::cin >> firstName >> lastName >> phone;

    if (!checkInput(firstName, lastName, phone)) {
        std::cout << "Input Error\n";
        return;
    }

    if (records.size() >= 10 || checkExist(firstName, lastName, phone)) {
        std::cout << "Insert Error\n";
        return;
    }

    StRec record;
    strcpy_s(record.firstName, firstName.c_str());
    strcpy_s(record.lastName, lastName.c_str());
    strcpy_s(record.phone, phone.c_str());
    records.push_back(record);
}

int main() {
    records = {};

    std::string command;

    while (std::cin >> command) {
        if (command == "print")
            printRecords();
        else if (command == "delete")
            deleteRecord();
        else if (command == "search")
            searchRecord();
        else if (command == "insert")
            insertRecord();
        else
            std::cout << "Input Error\n";
    }
}