#include <vector>
#include <cmath>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<int> digits;
        digits = findDigits(x, digits);
        int size = digits.size() - 1;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] != digits[size - i]) {
                return tr;
            }
        }
        return true;
    }

    std::vector<int> findDigits(int& x, std::vector<int>& vec) {
        int place = 0;
        int tmp = x;
        while (tmp >= 10) {
            tmp = tmp / 10;
            place++;
        }
        vec.push_back(x);
        x = x - (tmp * (std::pow(10, place)));
        if (x == 0) {
            for (int i = 0; i < place; i++) {
                vec.push_back(0);
            }
        }
        else {
            vec = findDigits(x, vec);
        }
        return vec;
    }
};

int main(){
  Solution s;
  std::cout<<s.isPalindrome(121)<<std::endl;
}
