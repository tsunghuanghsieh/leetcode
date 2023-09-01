#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        string strNum = std::to_string(x);
        for (int i = 0; i < strNum.size() / 2; i++) {
            if (strNum[i] != strNum[strNum.size() - 1 - i]) return false;
        }
        return true;
    }
};

class Solution2 {
public:
    // Follow-up optimization: without using string
    bool isPalindrome (int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        vector<int> digits;
        while (x / 10 != 0) {
            digits.emplace_back(x % 10);
            x /= 10;
        }
        digits.emplace_back(x);
        for (int i = 0; i < digits.size() / 2; i++) {
            if (digits[i] != digits[digits.size() - 1 - i]) return false;
        }
        return true;
    }
};