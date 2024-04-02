#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Form {
    private:
    std::string              word;
    std::vector<std::string> wordsList = std::vector<std::string>();
    std::ifstream            wordsFile;

    public:
    void SetInputWord(std::string inputWord);  // set input
    void ProcessInputWord();                   // process input
    void SetFileName(std::string fileName);    // set file name
    void Load_CompareWord();                   // read-in data and compare
    void PrintFoundWords();                    // print answers
};

void Form::SetInputWord(std::string inputWord) {
    word = inputWord;
}

void Form::ProcessInputWord() {
    std::string lower = "";
    for (char i: word) {
        lower += tolower(i);
    }
    word = lower;
}

void Form::SetFileName(std::string filename) {
    wordsFile.open(filename);
}

void Form::Load_CompareWord() {
    std::map<char, int> charCount;
    std::map<char, int> emptyCharCount;
    for (auto i: word) {
        if (charCount[i] > 0)
            charCount[i]++;
        else {
            charCount[i]      = 1;
            emptyCharCount[i] = 0;
        }
    }

    std::string line;
    while (!wordsFile.eof()) {
        std::getline(wordsFile, line);

        std::map<char, int> currentCharCount = emptyCharCount;

        bool pass = true;
        for (auto i: line) {
            if (currentCharCount.find(i) == currentCharCount.end()) {
                pass = false;
                break;
            }
            currentCharCount[i]++;
        }
        if (!pass)
            continue;
        for (auto i: charCount) {
            if (i.second < currentCharCount[i.first]) {
                pass = false;
                break;
            }
        }
        if (!pass)
            continue;

        wordsList.push_back(line);
    }
}

void Form::PrintFoundWords() {
    for (auto word: wordsList) {
        std::cout << word << '\n';
    }
}