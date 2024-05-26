#include <algorithm>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

class Book {
    public:
    std::string      title;
    std::string      author;
    std::vector<int> editions;

    Book(std::string title, std::string author, int edition) {
        this->title    = title;
        this->author   = author;
        this->editions = {edition};
    }
};

bool getString(std::stringstream& ss, std::string& location) {
    ss >> location;
    if (location[0] != '\"')
        return false;
    while (location[location.length() - 1] != '\"') {
        std::string tmp;
        ss >> tmp;
        if (ss.fail()) {
            return false;
        }
        location += ' ';
        location += tmp;
    }
    return true;
}

std::vector<Book> books;

void insert(std::string title, std::string author, int edition) {
    title  = title.substr(1, title.length() - 2);
    author = author.substr(1, author.length() - 2);

    int bookIndex = -1;

    for (int i = 0; i < books.size(); i++) {
        if (books[i].title == title && books[i].author == author) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        books.push_back(Book(title, author, edition));
        std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
        return;
    }

    std::vector<int> editions = books[bookIndex].editions;

    if (std::count(editions.begin(), editions.end(), edition) == 0) {
        books[bookIndex].editions.push_back(edition);
        std::sort(books[bookIndex].editions.begin(), books[bookIndex].editions.end());
        std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << ".\n";
    } else {
        std::cout << "Datum already exist.\n";
    }
}

void deleteEdition(std::string title, std::string author, int edition) {
    title  = title.substr(1, title.length() - 2);
    author = author.substr(1, author.length() - 2);

    int bookIndex = -1;

    for (int i = 0; i < books.size(); i++) {
        if (books[i].title == title && books[i].author == author) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        std::cout << "Datum doesn't exist.\n";
        return;
    }

    std::vector<int> editions = books[bookIndex].editions;
    if (std::count(editions.begin(), editions.end(), edition) == 0) {
        std::cout << "Datum doesn't exist.\n";
        return;
    }

    int editionIndex = std::find(editions.begin(), editions.end(), edition) - editions.begin();
    books[bookIndex].editions.erase(books[bookIndex].editions.begin() + editionIndex);

    std::cout << "Delete " << author << "'s " << title << ", Edition: " << edition << ".\n";
}

void deleteBook(std::string title, std::string author) {
    title  = title.substr(1, title.length() - 2);
    author = author.substr(1, author.length() - 2);

    int bookIndex = -1;

    for (int i = 0; i < books.size(); i++) {
        if (books[i].title == title && books[i].author == author) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        std::cout << "Book doesn't exist.\n";
        return;
    }

    books.erase(books.begin() + bookIndex);
    std::cout << "Delete " << author << "'s " << title << ".\n";
}

void findBook(std::string title, std::string author) {
    title  = title.substr(1, title.length() - 2);
    author = author.substr(1, author.length() - 2);

    int bookIndex = -1;

    for (int i = 0; i < books.size(); i++) {
        if (books[i].author == author && books[i].title == title) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        std::cout << "Book doesn't exist.\n";
        return;
    }

    std::cout << "Title: " << title << "\tAuthor: " << author << "\tEdition: ";
    for (int i = 0; i < books[bookIndex].editions.size() - 1; i++) {
        std::cout << books[bookIndex].editions[i] << ", ";
    }
    std::cout << books[bookIndex].editions[books[bookIndex].editions.size() - 1];
    std::cout << '\n';
}

void findAuthor(std::string author) {
    author = author.substr(1, author.length() - 2);

    std::vector<std::string> titles;

    for (auto i: books) {
        if (i.author == author) {
            titles.push_back(i.title);
        }
    }

    if (titles.size() == 0) {
        std::cout << "No book found.\n";
        return;
    }
    std::sort(titles.begin(), titles.end(), [](std::string& a, std::string& b) {
        return a < b;
    });

    std::cout << author << "'s Books: ";
    for (int i = 0; i < titles.size() - 1; i++) {
        std::cout << titles[i] << ", ";
    }
    std::cout << titles[titles.size() - 1] << '\n';
}

void sortByTitle() {
    std::sort(books.begin(), books.end(), [](Book& a, Book& b) {
        if (a.title == b.title)
            return a.author < b.author;
        return a.title < b.title;
    });

    for (auto i: books) {
        std::cout << "Title: " << i.title << "\tAuthor: " << i.author << "\tEdition: ";
        for (int j = 0; j < i.editions.size() - 1; j++) {
            std::cout << i.editions[j] << ", ";
        }
        std::cout << i.editions[i.editions.size() - 1];
        std::cout << '\n';
    }
}

void sortByAuthor() {
    std::sort(books.begin(), books.end(), [](Book& a, Book& b) {
        if (a.author == b.author)
            return a.title < b.title;
        return a.author < b.author;
    });

    for (auto i: books) {
        std::cout << "Title: " << i.title << "\tAuthor: " << i.author << "\tEdition: ";
        for (int j = 0; j < i.editions.size() - 1; j++) {
            std::cout << i.editions[j] << ", ";
        }
        std::cout << i.editions[i.editions.size() - 1];
        std::cout << '\n';
    }
}

int main() {
    books = {};
    std::string instruction;
    std::string command;

    while (std::getline(std::cin, instruction)) {
        if (instruction == "")
            continue;
        std::stringstream ss(instruction);

        bool error = false;

        ss >> command;
        if (command == "Insert") {
            std::string title;
            std::string author;
            int         edition;

            if (!getString(ss, title))
                error = true;
            if (!getString(ss, author))
                error = true;
            ss >> edition;
            if (ss.fail())
                error = true;

            if (!error)
                insert(title, author, edition);
        } else if (command == "Delete") {
            std::string type;

            ss >> type;
            if (ss.fail()) {
                error = true;
            } else if (type == "Edition") {
                std::string title;
                std::string author;
                int         edition;

                if (!getString(ss, title))
                    error = true;
                if (!getString(ss, author))
                    error = true;
                ss >> edition;
                if (ss.fail())
                    error = true;

                if (!error)
                    deleteEdition(title, author, edition);
            } else if (type == "Book") {
                std::string title;
                std::string author;

                if (!getString(ss, title))
                    error = true;
                if (!getString(ss, author))
                    error = true;

                if (!error)
                    deleteBook(title, author);
            } else {
                std::cout << "Unknown Command.\n";
            }
        } else if (command == "Find") {
            std::string type;
            ss >> type;
            if (ss.fail()) {
                error = true;
            } else if (type == "Book") {
                std::string title;
                std::string author;

                if (!getString(ss, title))
                    error = true;
                if (!getString(ss, author))
                    error = true;

                if (!error)
                    findBook(title, author);
            } else if (type == "Author") {
                std::string author;

                if (!getString(ss, author))
                    error = true;

                if (!error)
                    findAuthor(author);
            } else {
                std::cout << "Unknown Command.\n";
            }
        } else if (command == "Sort") {
            std::string by;
            std::string type;

            ss >> by >> type;
            if (ss.fail())
                error = true;

            if (by != "by" || (type != "Title" && type != "Author")) {
                std::cout << "Unkonwn Command.\n";
            } else if (type == "Title") {
                sortByTitle();
            } else if (type == "Author") {
                sortByAuthor();
            }
        } else {
            std::cout << "Unknown Command.\n";
        }

        if (error) {
            std::cout << "Incomplete Command.\n";
        }
    }
}