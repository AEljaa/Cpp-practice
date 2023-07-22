#include <iostream>
#include <map>
#include <vector>

std::vector<int> howSum(int target, std::vector<int> arr, std::map<int, std::vector<int>>& memo) {
    if (memo.find(target) != memo.end()) {
        return memo[target];
    }
    if (target == 0) {
        return {};
    }
    if (target < 0) {
        memo[target] = {}; // Use an empty vector for invalid combinations
        return {-1};
    }

    for (int i = 0; i < arr.size(); i++) {
        int remainder = target - arr[i];
        auto remainderResult = howSum(remainder, arr, memo);
        if (remainderResult[0] != -1) {
            std::vector<int> updatedResult = remainderResult;
            updatedResult.push_back(arr[i]);
            memo[target] = updatedResult;
            return updatedResult;
        }
    }

    memo[target] = {}; // Use an empty vector for invalid combinations
    return {-1};
}

int main() {
    std::map<int, std::vector<int>> memo;
    std::vector<int> arr = {6, 34, 45};
    std::vector<int> result = howSum(40, arr, memo);
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
