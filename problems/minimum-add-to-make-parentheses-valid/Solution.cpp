#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int total = 0, curr = 0;
        for (char c : s) {
            if (c == '(') {
                if (curr < 0) {
                    total += abs(curr);
                    curr = 0;
                }
                curr++;
            }
            else curr--;
        }
        total += abs(curr);
        return total;
    }
};
