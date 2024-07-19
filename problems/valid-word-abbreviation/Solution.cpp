#include <iostream>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wi = 0, num = 0;
        for (int ai = 0; ai < abbr.size(); ai++) {
            if (abbr[ai] - 'a' >= 0 && abbr[ai] - 'a' < 26) {
                if (num > 0) {
                    wi += num;
                    if (wi >= word.size()) return false;
                    num = 0;
                }
                if (word[wi] != abbr[ai]) return false;
                wi++;
                continue;
            }
            num = num * 10 + (abbr[ai] - '0');
            if (num == 0) return false;   // leading 0 or empty substitution
            if (ai + 1 == abbr.size()) {
                wi += num;
            }
        }
        return (wi == word.size());
    }
};
