#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    const string romans[7] = {"M", "D", "C", "L", "X", "V", "I"};
    const int numerals[7] = {1000, 500, 100, 50, 10, 5, 1};
    string val;

    string intToRoman(int num) {
        int idx = 0;
        val = "";
        while (idx < 7) {
            while (num >= numerals[idx]) {
                if (floor(num / numerals[idx]) == 9) {
                    val = val + romans[idx] + romans[idx - 2];
                    // cout << romans[idx] << romans[idx - 2];
                    num = num - floor(num / numerals[idx]) * numerals[idx];
                } else if (floor(num / numerals[idx]) >= 5) {
                    val = val + romans[idx - 1];
                    // cout << romans[idx - 1];
                    num = num - numerals[idx - 1];
                } else if (floor(num / numerals[idx]) == 4) {
                    val = val + romans[idx] + romans[idx - 1];
                    // cout << romans[idx] << romans[idx - 1];
                    num = num - floor(num / numerals[idx]) * numerals[idx];
                } else {
                    val = val + romans[idx];
                    // cout << romans[idx];
                    num -= numerals[idx];
                }
            }
            idx += 2;
        }
        return val;
    }
};

int main() {
    int num = 3999;
    Solution s;
    cout << s.intToRoman(num) << endl;
    return 0;
}