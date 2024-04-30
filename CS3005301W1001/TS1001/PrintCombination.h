#pragma once
#include <iostream>
#include <set>
#include <vector>

void calculateCombination(int num, int index, int m, int n, std::set<int> nums, std::vector<std::set<int>>& result) {
    if (index == m) {
        result.push_back(nums);
        return;
    }

    if (index > m || num >= n)
        return;

    calculateCombination(num + 1, index, m, n, nums, result);
    nums.insert(num + 1);
    calculateCombination(num + 1, index + 1, m, n, nums, result);
}

void PrintCombination(int* arrayPtr, int n, int r) {
    for (int i = 0; i <= n - r; i++) {
        std::set<int>              nums = {i + 1};
        std::vector<std::set<int>> result;

        calculateCombination(i + 1, 1, r, n, nums, result);

        for (int j = result.size() - 1; j >= 0; j--) {
            for (auto k = result[j].begin(); k != result[j].end(); k++) {
                if (std::distance(k, result[j].end()) != 1)
                    std::cout << *k << " ";
                else
                    std::cout << *k;
            }

            if (i != n - r || j != result.size() - 1) {
                std::cout << std::endl;
            }
        }
    }
}
