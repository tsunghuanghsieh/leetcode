#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int multiplier = 0;
        // INT_MAX is  2147483647 (10 digits)
        // INT_MIN is -2147483648 (10 digits)
        int res = 0;
        bool seenDigit = false;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
                seenDigit = true;
                multiplier = (multiplier == 0) ? 1 : multiplier;
                if (res  > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') * multiplier > INT_MAX % 10)) {
                    return INT_MAX;
                }
                if (res < INT_MIN / 10 || (res == INT_MIN / 10 && (str[i] - '0') * multiplier < INT_MIN % 10)) {
                    return INT_MIN;
                }
                res = res * 10 + (str[i] - '0') * multiplier;
            }
            else if (str[i] == '-' || str[i] == '+' || str[i] == ' ') {
                if (seenDigit) break;
                if (multiplier != 0) return 0;
                if (str[i] == ' ') continue;
                multiplier = (str[i] == '-') ? -1 : 1;
            }
            else {
                if (seenDigit) break;
                return 0;
            }
        }
        return res;
    }
};