#include <iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int total = 0, prev = 0, curr = 0;
        char ch = 0, optr = '+';
        for (int i = 0; i < s.size(); i++) {
            ch = s[i];
            if (isdigit(ch)) {
                curr = curr * 10 + (ch - '0');
            }
            if (ispunct(ch) || i + 1 == s.size()) {
                if (optr == '+' || optr == '-') {
                    total += prev;
                    prev = (optr == '-') ? -curr : curr;
                }
                else if (optr == '*') {
                    prev *= curr;
                }
                else if (optr == '/') {
                    prev /= curr;
                }
                optr = ch;
                curr = 0;
            }
        }
        total += prev;
        return total;
    }
};
