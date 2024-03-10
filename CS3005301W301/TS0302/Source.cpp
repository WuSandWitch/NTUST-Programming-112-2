#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

int main() {
    std::string   grades_string;
    std::ifstream grades_file("grade.txt");

    while (std::getline(grades_file, grades_string)) {
        // Init the stringstream
        std::stringstream ss(grades_string);
        ss >> std::noskipws;

        // Init the map
        std::map<int, int, std::greater<int>> grade_count;
        for (int i = 0; i < 6; i++)
            grade_count[i] = 0;

        int  grade;
        char ch;

        while (!ss.eof()) {
            ss >> grade >> ch;
            grade_count[grade]++;
        }

        // Write to file
        std::ofstream output;
        output.open("grades.output");
        for (auto i = grade_count.rbegin(); i != grade_count.rend(); i++) {
            output << i->second << " grade(s) of " << i->first << '\n';
        }
        output.close();
    }
}