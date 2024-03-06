#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool drawSquare(std::vector<std::vector<char>>& board) {
    int width, x, y;
    std::cin >> width >> x >> y;

    if (x + width > board[0].size() || y + width > board.size() || x > board[0].size() || y > board.size()) {
        return false;
    }

    for (int i = y; i < y + width; i++) {
        for (int j = x; j < x + width; j++) {
            board[i][j] = 'X';
        }
    }
    return true;
}

bool drawTriangle(std::vector<std::vector<char>>& board) {
    int         width, x, y;
    std::string direction;
    std::cin >> width >> x >> y >> direction;

    if (x >= board[0].size() || y >= board.size() || x < 0 || y < 0) {
        return false;
    }

    if (direction == "LU") {
        if (x - width < -1 || y - width < -1)
            return false;
        for (int i = y - width + 1; i <= y; i++) {
            for (int j = x - (i - y + width - 1); j <= x; j++) {
                board[i][j] = 'X';
            }
        }
    } else if (direction == "LD") {
        if (x - width < -1 || y + width > board.size())
            return false;
        for (int i = y; i < y + width; i++) {
            for (int j = x - width + (i - y) + 1; j <= x; j++) {
                board[i][j] = 'X';
            }
        }
    } else if (direction == "RU") {
        if (x + width > board[0].size() || y - width < -1)
            return false;
        for (int i = y - width + 1; i <= y; i++) {
            for (int j = x; j <= x + (i - y + width - 1); j++) {
                board[i][j] = 'X';
            }
        }
    } else if (direction == "RD") {
        if (x + width > board[0].size() || y + width > board.size())
            return false;
        for (int i = y; i < y + width; i++) {
            for (int j = x; j <= x + width - (i - y) - 1; j++) {
                board[i][j] = 'X';
            }
        }
    }
    return true;
}

bool drawLine(std::vector<std::vector<char>>& board) {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    if (x1 >= board[0].size() || y1 >= board.size() || x1 < 0 || y1 < 0) {
        return false;
    }
    if (x2 >= board[0].size() || y2 >= board.size() || x2 < 0 || y2 < 0) {
        return false;
    }

    // Vertical
    if (x1 == x2) {
        for (int i = std::min(y1, y2); i <= std::max(y1, y2); ++i) {
            board[i][x1] = 'X';
        }
    }
    // Horizontal
    else if (y1 == y2) {
        for (int i = std::min(x1, x2); i <= std::max(x1, x2); ++i) {
            board[y1][i] = 'X';
        }
    } else {
        int dx     = (x2 > x1) ? 1 : -1;
        int dy     = (y2 > y1) ? 1 : -1;
        int length = std::max(abs(x2 - x1), abs(y2 - y1));
        for (int i = 0; i <= length; ++i) {
            int x       = x1 + i * dx;
            int y       = y1 + i * dy;
            board[y][x] = 'X';
        }
    }
    return true;
}

void printBoard(std::vector<std::vector<char>>& board) {
    for (auto row: board) {
        for (char cell: row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::string                    type;
    std::vector<std::vector<char>> board(n, std::vector<char>(m, '*'));

    while (std::cin >> type) {
        if (type == "EXIT") {
            break;
        }
        bool status = true;

        if (type == "S") {
            status = drawSquare(board);
        } else if (type == "T") {
            status = drawTriangle(board);
        } else if (type == "L") {
            status = drawLine(board);
        }

        if (status)
            printBoard(board);
        else
            std::cout << "Out of range.\n";
        std::cout << '\n';
    }
}