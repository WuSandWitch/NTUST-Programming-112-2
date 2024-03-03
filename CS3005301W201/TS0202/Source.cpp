#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void getHighScores(std::vector<std::string> names, std::vector<int> scores) {
    // Sorting two array using bubble sort
    for (int i = 0; i < scores.size(); i++) {
        for (int j = 0; j < scores.size() - i - 1; j++) {
            if (scores[j] > scores[j + 1]) {
                std::swap(scores[j], scores[j + 1]);
                std::swap(names[j], names[j + 1]);
            }
        }
    }

    // Output the highest score and name
    for (int i = 0; i < 3; i++) {
        std::cout << names.back() << '\n';
        std::cout << scores.back() << '\n';

        names.pop_back();
        scores.pop_back();
    }
}

int main() {
    std::ifstream ScoreFile("scores.txt");
    std::string   name, score;

    std::vector<std::string> names;
    std::vector<int>         scores;

    while (std::getline(ScoreFile, name)) {
        std::getline(ScoreFile, score);

        names.push_back(name);
        scores.push_back(stoi(score));
    }

    getHighScores(names, scores);
}