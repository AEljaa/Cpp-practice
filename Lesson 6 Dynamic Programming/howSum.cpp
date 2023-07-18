#include <iostream>
#include <map>
#include <vector>

std::vector<int> howSum(int target, std::vector<int>& arr, std::map<int, std::vector<int>>& memo) {
    if (memo.count(target) > 0) {
        return memo[target];
    }
    if (target == 0) {
        return {};
    }
    if (target < 0) {
        return {};
    }
    for (int x : arr) {
        int remainder = target - x;
        memo[target] = howSum(remainder, arr, memo);
        memo[target].push_back(x);
        if (!memo[target].empty()) {
            return memo[target];
        }
    }
    memo[target] = {};
    return {};
}

int main() {
    std::map<int, std::vector<int>> memo;
    std::vector<int> arr = {6, 34, 45};
    std::vector<int> result = howSum(10, arr, memo);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}