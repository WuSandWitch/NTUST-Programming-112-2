#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int levenshteinDistance(std::string word1, std::string word2) {
    int word1_length = word1.length();
    int word2_length = word2.length();

    std::vector<std::vector<int>> dl(word1_length + 1, std::vector<int>(word2_length + 1, 0));

    for (int i = 0; i <= word1_length; i++) {
        dl[i][0] = i;
    }
    for (int j = 0; j <= word2_length; j++) {
        dl[0][j] = j;
    }

    for (int i = 1; i <= word1_length; i++) {
        for (int j = 1; j <= word2_length; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dl[i][j] = std::min({dl[i - 1][j - 1], dl[i][j - 1] + 1, dl[i - 1][j] + 1});
            } else {
                dl[i][j] = std::min({dl[i - 1][j - 1], dl[i][j - 1], dl[i - 1][j]}) + 1;
            }
        }
    }

    return dl[word1_length][word2_length];
}

int main() {
    std::string word1, word2;

    while (std::getline(std::cin, word1)) {
        std::getline(std::cin, word2);

        int distance = levenshteinDistance(word1, word2);
        std::cout << distance << '\n';
    }
}
