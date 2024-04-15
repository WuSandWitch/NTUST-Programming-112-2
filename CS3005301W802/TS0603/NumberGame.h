#pragma once
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class NumberGame {
    private:
    int         a;
    std::string fileName;

    std::vector<int> numbers;
    std::vector<int> digital;
    std::set<int>    list;

    public:
    void SetInput(int input) {
        this->a = input;
    }
    void ProcessInput() {
        int temp = this->a;

        while (temp != 0) {
            digital.push_back(temp % 10);

            temp /= 10;
        }
    }
    void SetFileName(std::string fileName) {
        this->fileName = fileName;
    }
    void LoadNumberList() {
        std::ifstream inFile(fileName);

        int num;

        while (inFile >> num) {
            this->numbers.push_back(num);
        }
    }
    void PrintAllValid() {
        FindAllMulNumber(0, 1);

        if (std::find(digital.begin(), digital.end(), 1) == digital.end()) {
            list.erase(list.begin());
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (list.find(numbers[i]) != list.end()) {
                std::cout << numbers[i] << '\n';
            }
        }
    }
    void Reset() {
        numbers.clear();
        digital.clear();
        list.clear();
        fileName.clear();
    }

    void FindAllMulNumber(int index, int mul) {
        if (index < digital.size()) {
            FindAllMulNumber(index + 1, mul);
            list.insert(mul);

            mul *= digital[index];
            FindAllMulNumber(index + 1, mul);
            list.insert(mul);
        }
    }
};