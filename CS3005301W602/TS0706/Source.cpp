#include <iostream>
#include <vector>

bool lineConnected(std::vector<std::vector<int>> arr, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        return true;
    } else if (x1 == x2) {
        for (int i = std::min(y1, y2); i <= std::max(y1, y2); i++) {
            if (arr[i][x1] != 0)
                return false;
        }
        return true;
    } else if (y1 == y2) {
        for (int i = std::min(x1, x2); i <= std::max(x1, x2); i++) {
            if (arr[y1][i] != 0)
                return false;
        }
        return true;
    }
    return false;
}

bool pairMatched(std::vector<std::vector<int>>& arr, int x1, int y1, int x2, int y2) {
    if (x1 > 5 || x2 > 5 || x1 < 0 || x2 < 0 || y1 > 5 || y2 > 5 || y1 < 0 || y2 < 0)
        return false;
    if (x1 == x2 && y1 == y2)
        return false;

    x1++;
    y1++;
    x2++;
    y2++;
    if (arr[y1][x1] == 0 || arr[y2][x2] == 0)
        return false;
    if (arr[y1][x1] != arr[y2][x2])
        return false;

    int backupA = arr[y1][x1];
    int backupB = arr[y2][x2];
    arr[y1][x1] = 0;
    arr[y2][x2] = 0;

    for (int i = 0; i < 8; i++) {
        if (lineConnected(arr, x1, y1, x1, i) && lineConnected(arr, x1, i, x2, i) && lineConnected(arr, x2, i, x2, y2)) {
            return true;
        }
        if (lineConnected(arr, x1, y1, i, y1) && lineConnected(arr, i, y1, i, y2) && lineConnected(arr, i, y2, x2, y2)) {
            return true;
        }
    }
    arr[y1][x1] = backupA;
    arr[y2][x2] = backupB;
    return false;
}

int main() {
    std::vector<std::vector<int>> arr(8, std::vector<int>(8, 0));
    int                           num;

    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            std::cin >> num;
            arr[i][j] = num;
        }
    }

    int x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2) {
        if (pairMatched(arr, x1, y1, x2, y2)) {
            std::cout << "pair matched\n";
        } else {
            std::cout << "bad pair\n";
        }
    }
}