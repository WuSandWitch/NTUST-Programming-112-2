#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

struct Word {
    std::string word;
    bool        isUsed;
};

bool checkInvaild(int x, int y, std::vector<std::vector<bool>> visited) {
    return !(x < 0 || x >= 4 || y < 0 || y >= 4 || visited[y][x]);
}

bool wordsAbout(std::string input, std::vector<Word>& words, std::map<char, std::set<std::string>>& ans) {
    bool findAbout = false;

    for (int i = 0; i < words.size(); i++) {
        if (words[i].word == input) {
            if (words[i].isUsed == false) {
                words[i].isUsed = true;
                ans[words[i].word[0]].insert(words[i].word);
            }
        }

        if (words[i].word.find(input) != std::string::npos) {
            findAbout = true;
        }
    }

    return findAbout;
}

void setWord(
  std::string input, std::vector<std::vector<bool>> visited, std::vector<Word>& words, int x, int y, std::vector<std::vector<char>> board,
  int length, std::map<char, std::set<std::string>>& result) {
    visited[y][x] = true;

    if (length >= 3 && (!wordsAbout(input, words, result)))
        return;

    int directionX[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int directionY[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    for (int i = 0; i < 8; i++) {
        if (checkInvaild(x + directionX[i], y + directionY[i], visited)) {
            std::string next = input + board[y + directionY[i]][x + directionX[i]];
            setWord(next, visited, words, x + directionX[i], y + directionY[i], board, length + 1, result);
        }
    }
}

int main() {
    char inputChar;
    while (std::cin >> inputChar) {
        std::ifstream inFile("words.txt");

        std::map<char, std::vector<Word>> words;

        std::string input;

        while (inFile >> input) {
            Word word = {input, false};
            words[input[0]].push_back(word);
        }

        std::vector<std::vector<char>> board = std::vector<std::vector<char>>(4, std::vector<char>(4, ' '));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != 0 || j != 0)
                    std::cin >> inputChar;

                board[i][j] = inputChar;
            }
        }

        std::map<char, std::set<std::string>> result;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::vector<std::vector<bool>> visited(4, std::vector<bool>(4, false));

                std::string temp = " ";
                temp[0]          = board[i][j];

                setWord(temp, visited, words[temp[0]], j, i, board, 1, result);
            }
        }

        for (auto i: result)
            for (auto j: i.second)
                std::cout << j << '\n';
        ;
        std::cout << '\n';
    }
}
