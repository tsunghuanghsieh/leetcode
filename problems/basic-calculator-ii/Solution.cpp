#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int start = 0;
        regex patternOps("[+|\\-|\\\\*|/]");
        sregex_token_iterator itr(s.begin(), s.end(), patternOps);
        queue<char> q_operators;
        queue<int> q_operands;

        for (; itr != sregex_token_iterator(); itr++) {
            int idx = s.find(*itr, start);
            q_operands.push(stoi(s.substr(start, idx - start)));
            q_operators.push(*(*itr).str().c_str());
            start = idx + 1;
        }
        q_operands.push(stoi(s.substr(start)));
        char optr = 0;
        int prev = q_operands.front(), oprd = 0, total = 0;
        q_operands.pop();
        while (q_operators.size() > 0) {
            optr = q_operators.front();
            q_operators.pop();
            oprd = q_operands.front();
            q_operands.pop();
            if (optr == '+' || optr == '-') {
                total += prev;
                prev = (optr == '-') ? -oprd : oprd;
            }
            else if (optr == '*') {
                prev *= oprd;
            }
            else {
                prev /= oprd;
            }
        }
        total += prev;
        return total;
    }
};
